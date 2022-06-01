/*
 *           File: bcd_7seg.h
 *     Created on: Monday 30/05/2022 19:43
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 7seg Driver
 *
 *
 */

#ifndef _BCD_7SEG_H_
#define _BCD_7SEG_H_

#include "stm32f103c6-gpio.h"

#define BCD_7SEG_GPIO   GPIOB

#define BCD_7SEG_P0     GPIO_PIN_12
#define BCD_7SEG_P1     GPIO_PIN_13
#define BCD_7SEG_P2     GPIO_PIN_14
#define BCD_7SEG_P3     GPIO_PIN_15

void bcd_7seg_Init(void);
void bcd_7deg_Write(uint8_t num);

#endif