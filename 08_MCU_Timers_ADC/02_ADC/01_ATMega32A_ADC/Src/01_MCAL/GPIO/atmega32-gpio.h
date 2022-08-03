/*
 *           File: atmega32-gpio.h
 *     Created on: Monday 06/06/2022 20:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 GPIO Driver
 *
 *
 */

#ifndef _ATMEGA32_GPIO_H_
#define _ATMEGA32_GPIO_H_

#include "atmega32.h"

typedef struct
{
    uint8_t PINx;
    uint8_t DDRx;
    uint8_t PORTx;
} GPIOx_t;

/** @defgroup GPIOx_define GPIO Define
 * @{
 */
#define GPIOA       (GPIOx_t *)(&(PINA))
#define GPIOB       (GPIOx_t *)(&(PINB))
#define GPIOC       (GPIOx_t *)(&(PINC))
#define GPIOD       (GPIOx_t *)(&(PIND))
/**
 * @}
 */

/** @defgroup GPIO_MODE_define GPIO Mode For Each PIN
 * @{
 */
#define GPIO_MODE_OUTPUT            (uint8_t)0b10
#define GPIO_MODE_INPUT_FLOATING    (uint8_t)0b00
#define GPIO_MODE_INPUT_PULL_UP     (uint8_t)0b01
/**
 * @}
 */


/** @defgroup GPIO_PIN_define GPIO PIN
 * @{
 */
#define GPIO_PIN_0      (uint8_t)0b00000001
#define GPIO_PIN_1      (uint8_t)0b00000010
#define GPIO_PIN_2      (uint8_t)0b00000100
#define GPIO_PIN_3      (uint8_t)0b00001000
#define GPIO_PIN_4      (uint8_t)0b00010000
#define GPIO_PIN_5      (uint8_t)0b00100000
#define GPIO_PIN_6      (uint8_t)0b01000000
#define GPIO_PIN_7      (uint8_t)0b10000000
/**
 * @}
 */

/** @defgroup GPIO_STATUS_define GPIO PIN Status
 * @{
 */
#define GPIO_PIN_HIGH   (uint8_t)1
#define GPIO_PIN_LOW    (uint8_t)0
/**
 * @}
 */


/**
 * @brief Initialize the GPIO PIN to be input or output, ..
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @param Mode Specifies the operation mode of the pin ,Must be selected from @ref GPIO_MODE_define
 * @param Pin Specifies the pin number ,Must be selected from @ref GPIO_PIN_define
 */
void GPIO_Init(GPIOx_t *GPIOx, uint8_t Mode, uint8_t Pin);


/**
 * @brief Reset the gpio port
 * 
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 */
void GPIO_Reset(GPIOx_t *GPIOx);

/**
 * @brief Writes value to pin
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @param Pin Specifies the pin number ,Must be selected from @ref GPIO_PIN_define
 * @param Status Specifies the status even low or high ,Must be Selected from @ref GPIO_STATUS_define
 */
void GPIO_Write_Pin(GPIOx_t *GPIOx, uint8_t Pin, uint8_t Status);

/**
 * @brief Writes value to port
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @param Value the value of the port to be writen
 */
void GPIO_Write_Port(GPIOx_t *GPIOx, uint8_t Value);

/**
 * @brief Reads from the pin
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @param Pin Specifies the pin number ,Must be selected from @ref GPIO_PIN_define
 * @return uint8_t the value of the pin
 */
uint8_t GPIO_Read_Pin(GPIOx_t *GPIOx, uint8_t Pin);

/**
 * @brief Reads from the port
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @return uint8_t the value of the port
 */
uint8_t GPIO_Read_Port(GPIOx_t *GPIOx);

#endif