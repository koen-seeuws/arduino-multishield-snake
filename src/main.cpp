#include <Arduino.h>
#include <MultiShield.h>
#include <../lib/SnakeSetup/SnakeSetup.h>

void setup() {
    // write your initialization code here
    setupLeds();
    setupButtons();
    setupBuzzer();
    setupDisplay();
}

void loop() {
    // write your code here
}
