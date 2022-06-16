/*
 *           File: atmega32-exti.h
 *     Created on: Monday 06/06/2022 22:02
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 EXTI Driver
 *
 *
 */

#ifndef _ATMEGA32_EXTI_H_
#define _ATMEGA32_EXTI_H_

#include "atmega32.h"
#include "atmega32-gpio.h"


#define EXTI0 0
#define EXTI1 1
#define EXTI2 2

#define EXTI0_PORT GPIOD
#define EXTI0_PIN GPIO_PIN_2

#define EXTI1_PORT GPIOD
#define EXTI1_PIN GPIO_PIN_3

#define EXTI2_PORT GPIOB
#define EXTI2_PIN GPIO_PIN_2

/** @defgroup EXTI_TRIGGER_def
 * @{
 */
#define EXTI_TRIGGER_LOW_LEVEL 0b00
#define EXTI_TRIGGER_LOGICAL_CHANGE 0b01
#define EXTI_TRIGGER_FALLING_EDGE 0b10
#define EXTI_TRIGGER_RISING_EDGE 0b11
/**
 * @}
 */

/**
 * @brief
 *
 * @param EXTIx Must be set by one of those (EXTI0, EXTI1, EXTI2)
 * @param Trigger Must be set by @ref EXTI_TRIGGER_def
 * @param P_CallBack Pointer to callback function
 */
void EXTI_Init(uint8_t EXTIx, uint8_t Trigger, void (*P_CallBack)(void));

/**
 * @brief
 *
 * @param EXTIx Must be set by one of those (EXTI0, EXTI1, EXTI2)
 */
void EXTI_Reset(uint8_t EXTIx);

#endif