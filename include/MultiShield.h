//
// Created by Koen Seeuws on 18/05/2024.
//

#ifndef MULTISHIELD_H
#define MULTISHIELD_H

#ifndef __AVR_ATmega328P__  // Arduino UNO, NANO
  #error : Library only for Arduino Uno, Nano and so on with ATmega328
#endif

#include "Arduino.h"

static const uint8_t LED_1_PIN=13;
static const uint8_t LED_2_PIN=12;
static const uint8_t LED_3_PIN=11;
static const uint8_t LED_4_PIN=10;
static const uint8_t POT_PIN=0;
static const uint8_t BUZZER_PIN=3;
static const uint8_t BUTTON_1_PIN=A1;
static const uint8_t BUTTON_2_PIN=A2;
static const uint8_t BUTTON_3_PIN=A3;
static const uint8_t LATCH_PIN=4;
static const uint8_t CLK_PIN=7;
static const uint8_t DATA_PIN=8;
static const uint8_t LM35_PIN=A4;

#endif //MULTISHIELD_H
