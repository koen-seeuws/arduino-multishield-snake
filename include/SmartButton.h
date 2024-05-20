//
// Created by Koen Seeuws on 20/05/2024.
//

#ifndef SMARTBUTTON_H
#define SMARTBUTTON_H

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
    explicit SmartButton(int buttonPin);

    bool isPressed();
    bool isReleased();
    bool isHeldDown();
};

#endif //SMARTBUTTON_H
