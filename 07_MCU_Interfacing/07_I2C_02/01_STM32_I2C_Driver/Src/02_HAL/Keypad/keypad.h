/*
 *           File: keypad.h
 *     Created on: Tuesday 31/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: Keypad Driver HAL Layer
 *
 *
 */

#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#include "stm32f103c6-gpio.h"

#define KEYPAD_ROWS     4
#define KEYPAD_COLUMNS  4

#define KEYPAD_GPIO     GPIOB

#define KEYPAD_R0_PIN   GPIO_PIN_0
#define KEYPAD_R1_PIN   GPIO_PIN_1
#define KEYPAD_R2_PIN   GPIO_PIN_3
#define KEYPAD_R3_PIN   GPIO_PIN_4

#define KEYPAD_C0_PIN   GPIO_PIN_5
#define KEYPAD_C1_PIN   GPIO_PIN_6
#define KEYPAD_C2_PIN   GPIO_PIN_7
#define KEYPAD_C3_PIN   GPIO_PIN_8
    
void keypad_init(void);
char keypad_getkey(void);
    
#endif