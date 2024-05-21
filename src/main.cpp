#include <Arduino.h>
#include <MultiShield.h>
#include <SmartButton.h>
#include <SnakeSetup.h>
#include <Snake.h>

void display(byte displayPosition, uint8_t value);

void printSnakeToSerial();

auto leftButton = SmartButton(BUTTON_1_PIN);
auto middleButton = SmartButton(BUTTON_2_PIN);
auto rightButton = SmartButton(BUTTON_3_PIN);

auto field = new Field(8, 3);
auto snake = new Snake(4, field);

void setup() {
    // write your initialization code here
    Serial.begin(9600);

    setupLeds();
    setupBuzzer();
    setupDisplay();
}

static constexpr unsigned long REFRESH_INTERVAL = 1000; // ms
static unsigned long currentTime;
static unsigned long lastRefreshTime = 0;

void loop() {
    // write your code here
    currentTime = millis();

    if (currentTime - lastRefreshTime >= REFRESH_INTERVAL) {
        lastRefreshTime += REFRESH_INTERVAL;
        Serial.println(lastRefreshTime);

        snake->move();

        printSnakeToSerial();
    }

    if (leftButton.isPressed()) {
        snake->turnLeft();
    }

    if (rightButton.isPressed()) {
        snake->turnRight();
    }

    uint8_t displayValues[] = {0xFF, 0xFF, 0xFF, 0xFF};


    /*
    for (int i = 0; i < snake->getLength() - 1; i++) {
        const auto pos1 = positions[i];
        const auto pos2 = positions[i + 1];

        auto xDiff = pos1->getX() - pos2->getX();
        auto yDiff = pos1->getY() - pos2->getY();

        auto displayPosition = 1;
    }
*/

    for (byte i = 0; i < 4; i++) {
        display(0, displayValues[0]);
    }
}

void display(const byte displayPosition, const uint8_t value) {
    digitalWrite(LATCH_PIN,LOW);
    shiftOut(DATA_PIN, CLK_PIN,MSBFIRST, value); //Send value to the 4 displays
    shiftOut(DATA_PIN, CLK_PIN,MSBFIRST, DISPLAY_POSITIONS[displayPosition]); //Send which display
    digitalWrite(LATCH_PIN,HIGH);
}

void printSnakeToSerial() {
    for (int y = field->getHeight() - 1; y >= 0; y--) {
        for (int x = 0; x < field->getWidth(); x++) {
            auto position = field->getPosition(x, y);
            if (position->getSnake() != nullptr) {
                Serial.print("S");
            } else {
                Serial.print("*");
            }
        }
        Serial.println();
    }
}
