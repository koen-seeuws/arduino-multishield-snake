//
// Created by Koen Seeuws on 20/05/2024.
//

#ifndef SMARTBUTTON_H
#define SMARTBUTTON_H

#include <Arduino.h>

class SmartButton {
private:
    int pin;

    const unsigned long debounceDelay = 50; // 50 milliseconds debounce delay

    unsigned long pressLastDebouceTime;
    bool pressLastButtonState;
    bool buttonPressHandled;

    unsigned long releaseLastDebounceTime;
    bool releaseLastButtonState;
    bool buttonReleaseHandled;

    const unsigned long holdDelay = 1000; // Hold down threshold: 1000 milliseconds
    unsigned long buttonDownTime;
    bool buttonHeldDown;

public:
    explicit SmartButton(const int buttonPin) : pin(buttonPin),
                                                //Press variables
                                                pressLastDebouceTime(0),
                                                pressLastButtonState(LOW),
                                                buttonPressHandled(false),
                                                //Release variables
                                                releaseLastDebounceTime(0),
                                                releaseLastButtonState(HIGH),
                                                buttonReleaseHandled(true), //Initialized to true (because of startup)
                                                //Hold variables
                                                buttonDownTime(0), buttonHeldDown(false) {
        pinMode(pin, INPUT_PULLUP);
    }

    bool isPressed() {
        const unsigned long currentTime = millis();
        const bool buttonState = digitalRead(pin);

        if (buttonState != pressLastButtonState) {
            pressLastDebouceTime = currentTime;
            buttonPressHandled = false; // Reset the button handled flag when state changes
        }

        if (currentTime - pressLastDebouceTime <= debounceDelay) {
            return false;
        }

        if (buttonState == LOW && !buttonPressHandled) {
            buttonPressHandled = true;
            pressLastButtonState = buttonState;
            return true;
        }

        return false;
    }

    bool isReleased() {
        const unsigned long currentTime = millis();
        const bool buttonState = digitalRead(pin);

        if (buttonState != releaseLastButtonState) {
            releaseLastDebounceTime = currentTime;
            buttonReleaseHandled = false; // Reset the button handled flag when state changes
        }

        if (currentTime - releaseLastDebounceTime <= debounceDelay) {
            return false;
        }

        if (buttonState == HIGH && !buttonReleaseHandled) {
            buttonReleaseHandled = true;
            releaseLastButtonState = buttonState;
            return true;
        }


        return false;
    }

    bool isHeldDown() {
        const unsigned long currentTime = millis();
        const bool buttonState = digitalRead(pin);

        if (buttonState == LOW) {
            if (!buttonHeldDown) {
                buttonDownTime = currentTime;
                buttonHeldDown = true;
            }
            if (currentTime - buttonDownTime > holdDelay) {
                return true;
            }
        } else {
            buttonHeldDown = false;
        }

        return false;
    }
};

#endif //SMARTBUTTON_H
