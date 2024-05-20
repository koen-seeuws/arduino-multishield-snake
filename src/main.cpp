#include <Arduino.h>
#include <MultiShield.h>
#include <SmartButton.h>
#include <SnakeSetup.h>
#include <Snake.h>

void display(byte displayPosition, uint8_t value);

auto leftButton = SmartButton(BUTTON_1_PIN);
auto middleButton = SmartButton(BUTTON_2_PIN);
auto rightButton = SmartButton(BUTTON_3_PIN);

auto snake = Snake();

void setup() {
    // write your initialization code here
    Serial.begin(9600);

    pinMode(BUTTON_1_PIN, INPUT_PULLUP);

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
        snake.move();
    }

    if (leftButton.isPressed()) {
        snake.turnLeft();
    }

    if (rightButton.isPressed()) {
        snake.turnRight();
    }

    for (int i = 0; i < 4; i++) {
        display(i, DISPLAY_NUMERIC[snake.getDirection()]);
    }
}

void display(const byte displayPosition, const uint8_t value) {
    digitalWrite(LATCH_PIN,LOW);
    shiftOut(DATA_PIN, CLK_PIN,MSBFIRST, value); //Send value to the 4 displays
    shiftOut(DATA_PIN, CLK_PIN,MSBFIRST, DISPLAY_POSITIONS[displayPosition]); //Send which display
    digitalWrite(LATCH_PIN,HIGH);
}
