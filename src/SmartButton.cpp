//
// Created by Koen Seeuws on 20/05/2024.
//

#include "SmartButton.h"
#include "Arduino.h"

SmartButton::SmartButton(const int buttonPin) : pin(buttonPin),
                                                //Press variables
                                                pressLastDebouceTime(0),
                                                pressLastButtonState(LOW),
                                                buttonPressHandled(false),
                                                //Release variables
                                                releaseLastDebounceTime(0),
                                                releaseLastButtonState(HIGH),
                                                buttonReleaseHandled(true), //Initialized to true (because of startup)
                                                //Hold variables
                                                buttonDownTime(0), buttonHeldDown(false)
{
    pinMode(pin, INPUT_PULLUP);
}

bool SmartButton::isPressed() {
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

bool SmartButton::isReleased() {
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

bool SmartButton::isHeldDown() {
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