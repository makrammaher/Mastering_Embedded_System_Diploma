/*
 *           File: atmega32-gpio.c
 *     Created on: Monday 06/06/2022 20:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 GPIO Driver
 *
 *
 */

#include "atmega32-gpio.h"

/**
 * @brief Initialize the GPIO PIN to be input or output, ..
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @param Mode Specifies the operation mode of the pin ,Must be selected from @ref GPIO_MODE_define
 * @param Pin Specifies the pin number ,Must be selected from @ref GPIO_PIN_define
 */
void GPIO_Init(GPIOx_t *GPIOx, uint8_t Mode, uint8_t Pin)
{
    /* Initialze GPIO Mode Registers */
    switch (Mode)
    {
    case GPIO_MODE_OUTPUT:
        GPIOx->DDRx |= Pin;
        break;

    case GPIO_MODE_INPUT_FLOATING:
        GPIOx->DDRx &= ~Pin;
        GPIOx->PORTx &= ~Pin;
        break;

    case GPIO_MODE_INPUT_PULL_UP:
        GPIOx->DDRx &= ~Pin;
        GPIOx->PORTx |= Pin;
        break;
    default:
        break;
    }
}

/**
 * @brief Reset the gpio port
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 */
void GPIO_Reset(GPIOx_t *GPIOx)
{
    /* Reset all Registers of GPIOx */
    GPIOx->DDRx = 0;
    GPIOx->PINx = 0;
    GPIOx->PORTx = 0;
}

/**
 * @brief Writes value to pin
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @param Pin Specifies the pin number ,Must be selected from @ref GPIO_PIN_define
 * @param Status Specifies the status even low or high ,Must be Selected from @ref GPIO_STATUS_define
 */
void GPIO_Write_Pin(GPIOx_t *GPIOx, uint8_t Pin, uint8_t Status)
{
    switch (Status)
    {
    case GPIO_PIN_HIGH:
        GPIOx->PORTx |= Pin;
        break;
    case GPIO_PIN_LOW:
        GPIOx->PORTx &= ~Pin;
        break;
    default:
        break;
    }
}

/**
 * @brief Writes value to port
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @param Value the value of the port to be writen
 */
void GPIO_Write_Port(GPIOx_t *GPIOx, uint8_t Value)
{
    GPIOx->PORTx = Value;
}

/**
 * @brief Reads from the pin
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @param Pin Specifies the pin number ,Must be selected from @ref GPIO_PIN_define
 * @return uint8_t the value of the pin
 */
uint8_t GPIO_Read_Pin(GPIOx_t *GPIOx, uint8_t Pin)
{
    return ((GPIOx->PINx & Pin) == 0) ? GPIO_PIN_LOW : GPIO_PIN_HIGH;
}

/**
 * @brief Reads from the port
 *
 * @param GPIOx Specifies GPIOx ,Must be Selected From @ref GPIOx_define
 * @return uint8_t the value of the port
 */
uint8_t GPIO_Read_Port(GPIOx_t *GPIOx)
{
    return GPIOx->PINx;
}