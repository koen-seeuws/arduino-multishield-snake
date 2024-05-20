//
// Created by Koen Seeuws on 18/05/2024.
//

#ifndef MULTISHIELD_H
#define MULTISHIELD_H

#ifndef __AVR_ATmega328P__  // Arduino UNO, NANO
  #error : Library only for Arduino Uno, Nano and so on with ATmega328
#endif

#include "Arduino.h"

static constexpr uint8_t LED_1_PIN=13;
static constexpr uint8_t LED_2_PIN=12;
static constexpr uint8_t LED_3_PIN=11;
static constexpr uint8_t LED_4_PIN=10;
static constexpr uint8_t POT_PIN=0;
static constexpr uint8_t BUZZER_PIN=3;
static constexpr uint8_t BUTTON_1_PIN=A1;
static constexpr uint8_t BUTTON_2_PIN=A2;
static constexpr uint8_t BUTTON_3_PIN=A3;
static constexpr uint8_t LATCH_PIN=4;
static constexpr uint8_t CLK_PIN=7;
static constexpr uint8_t DATA_PIN=8;
static constexpr uint8_t LM35_PIN=A4;

static constexpr uint8_t DISPLAY_POSITIONS[] = {0xF1,0xF2,0xF4,0xF8};
static constexpr uint8_t DISPLAY_NUMERIC[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
static constexpr uint8_t DISPLAY_ALPHABET[] = {0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E, 0xC2, 0x89, 0xCF, 0xE1, 0x8A, 0xC7, 0xEA, 0xC8, 0xC0, 0x8C, 0x4A, 0xCC, 0x92, 0x87, 0xC1, 0xC1, 0xD5, 0x89, 0x91, 0xA4};
static constexpr uint8_t DISPLAY_LEDS[] = {0xFE};


#endif //MULTISHIELD_H
