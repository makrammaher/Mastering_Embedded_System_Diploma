/*
 *           File: keypad.h
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 LCD and Keypad
 *
 *
 */

#ifndef _KEYPAD_H_
#define _KEYPAD_H_

#include "macros.h"

#define KEYPAD_ROWS     4
#define KEYPAD_COLUMNS  4

#define KEYPAD_DDR      DDRD
#define KEYPAD_PORT     PORTD
#define KEYPAD_PIN      PIND

#define KEYPAD_R0_PIN   0
#define KEYPAD_R1_PIN   1
#define KEYPAD_R2_PIN   2
#define KEYPAD_R3_PIN   3

#define KEYPAD_C0_PIN   4
#define KEYPAD_C1_PIN   5
#define KEYPAD_C2_PIN   6
#define KEYPAD_C3_PIN   7
    
void keypad_init(void);
char keypad_getkey(void);
    
#endif