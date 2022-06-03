/*
 *           File: stm32f103c6-gpio.c
 *     Created on: Monday 30/05/2022 19:43
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 GPIO Driver
 *
 *
 */

#include "stm32f103c6-gpio.h"

/**
 * @brief Initialize GPIO Pin
 *
 * @param GPIOx : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Mode  : Specifies the operating mode for the selected pins.
 *                This parameter can be a value of @ref GPIO_mode_define
 * @param Pin   : Specifies the GPIO pins to be configured.
 *                This parameter can be any value of @ref GPIO_pins_define
 */
void GPIO_Init(GPIOx_t *GPIOx, uint8_t Mode, uint16_t Pin)
{
    uint8_t shift = 0;
    uint16_t temp = Pin;
    if (Pin < GPIO_PIN_8)
    {
        /* use CRL */
        while (temp > GPIO_PIN_0)
        {
            temp >>= 1;
            shift++;
        }
        GPIOx->CRL &= ~((uint32_t)0x0F << (shift * 4));
        GPIOx->CRL |= ((uint32_t)(Mode & 0x0F) << (shift * 4));
    }
    else
    {
        /* Use CRH */
        while (temp > GPIO_PIN_8)
        {
            temp >>= 1;
            shift++;
        }
        GPIOx->CRH &= ~((uint32_t)0x0F << (shift * 4));
        GPIOx->CRH |= ((uint32_t)(Mode & 0x0F) << (shift * 4));
    }
    if (Mode & (0xF0))
    {
        /* ODR Must by set by one */
        GPIOx->ODR |= Pin;
    }
    else
    {
        /* ODR Must be reset by zero */
        GPIOx->ODR &= ~Pin;
    }
}

/**
 * @brief deinitialize GPIO Port
 *
 * @param GPIOx Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 */
void GPIO_Reset(GPIOx_t *GPIOx)
{
    if (GPIOx == GPIOA)
    {
        SET_BIT(RCC->APB2RSTR, 2);
        CLEAR_BIT(RCC->APB2RSTR, 2);
    }
    else if (GPIOx == GPIOB)
    {
        SET_BIT(RCC->APB2RSTR, 3);
        CLEAR_BIT(RCC->APB2RSTR, 3);
    }
    else if (GPIOx == GPIOC)
    {
        SET_BIT(RCC->APB2RSTR, 4);
        CLEAR_BIT(RCC->APB2RSTR, 4);
    }
    else if (GPIOx == GPIOD)
    {
        SET_BIT(RCC->APB2RSTR, 5);
        CLEAR_BIT(RCC->APB2RSTR, 5);
    }
    else if (GPIOx == GPIOE)
    {
        SET_BIT(RCC->APB2RSTR, 6);
        CLEAR_BIT(RCC->APB2RSTR, 6);
    }
    else
    {
        GPIOx->CRL = 0x44444444;
        GPIOx->CRH = 0x44444444;
        GPIOx->ODR = 0x00000000;
        GPIOx->BSRR = 0x00000000;
        GPIOx->BRR = 0x00000000;
        GPIOx->LCKR = 0x00000000;
    }
}

/**
 * @brief Read Pin Status 0 or 1
 *
 * @param GPIOx     : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Pin       : Specifies the GPIO pins to be configured.
 *                    This parameter can be any value of @ref GPIO_pins_define
 * @return uint8_t  : GPIO Bit SET and Bit RESET
 */
uint8_t GPIO_Read_Pin(GPIOx_t *GPIOx, uint16_t Pin)
{
    if (GPIOx->IDR & (uint32_t)Pin)
    {
        return GPIO_PIN_SET;
    }
    else
    {
        return GPIO_PIN_RESET;
    }
}

/**
 * @brief Read Port From GPIOx
 *
 * @param GPIOx         : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @return uint16_t     : GPIO Port Value
 */
uint16_t GPIO_Read_Port(GPIOx_t *GPIOx)
{
    return (uint16_t)(GPIOx->IDR);
}

/**
 * @brief Write Status to pin in GPIOx
 *
 * @param GPIOx         : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Pin           : Specifies the GPIO pins to be configured.
 *                        This parameter can be any value of @ref GPIO_pins_define
 * @param Pin_Status    : Specifies the GPIO pin status.
 *                        This parameter can be any value of @ref GPIO_PIN_STATUS
 */
void GPIO_Write_Pin(GPIOx_t *GPIOx, uint16_t Pin, uint8_t Pin_Status)
{
    if (Pin_Status == GPIO_PIN_SET)
    {
        GPIOx->BSRR = (uint32_t)Pin;
    }
    else
    {
        GPIOx->BRR = (uint32_t)Pin;
    }
}

/**
 * @brief Write Port Value in GPIOx
 *
 * @param GPIOx         : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Port_Value    : Specifies the GPIO Port Value.
 */
void GPIO_Write_Port(GPIOx_t *GPIOx, uint16_t Port_Value)
{
    GPIOx->ODR = (uint32_t)Port_Value;
}

/**
 * @brief Toggle Pin in GPIOx
 *
 * @param GPIOx : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Pin   : Specifies the GPIO pin status.
 *                This parameter can be any value of @ref GPIO_PIN_STATUS
 */
void GPIO_Toggle_Pin(GPIOx_t *GPIOx, uint16_t Pin)
{
    GPIOx->ODR ^= (uint32_t)Pin;
}

/**
 * @brief Locks Pin in GPIOx
 *
 * @param GPIOx     : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Pin       : Specifies the GPIO pin status.
 *                    This parameter can be any value of @ref GPIO_PIN_STATUS
 * @return uint8_t  : GPIO Pin Lock done or error
 */

uint8_t GPIO_Lock_Pin(GPIOx_t *GPIOx, uint16_t Pin)
{
    uint32_t temp = 1 << 16;
    temp |= Pin;

    GPIOx->LCKR = temp;
    GPIOx->LCKR = Pin;
    GPIOx->LCKR = temp;
    temp = GPIOx->LCKR;

    if (GPIOx->LCKR & ((uint32_t)1 << 16))
    {
        return GPIO_PIN_LOCK_DONE;
    }
    else
    {
        return GPIO_PIN_LOCK_ERROR;
    }
}