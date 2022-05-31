/*
 *           File: main.c
 *     Created on: Thursday 19/05/2022 21:46
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx GPIO
 *
 *
 */

#include "stm32f103c6-gpio.h"

void wait_ms(uint32_t time);

int main(void)
{
    /* Initialization */
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();

    /* Initialize GPIO-A */
    GPIO_Init(GPIOA, GPIO_MODE_INPUT_F, GPIO_PIN_1);
    GPIO_Init(GPIOA, GPIO_MODE_INPUT_F, GPIO_PIN_13);
    GPIO_Init(GPIOB, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_1);
    GPIO_Init(GPIOB, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_13);

    while (1)
    {
        if(GPIO_Read_Pin(GPIOA, GPIO_PIN_1) == GPIO_PIN_RESET)
        {
            GPIO_Toggle_Pin(GPIOB, GPIO_PIN_1);
            while(GPIO_Read_Pin(GPIOA, GPIO_PIN_1) == GPIO_PIN_RESET);
        }
        if(GPIO_Read_Pin(GPIOA, GPIO_PIN_13) == GPIO_PIN_SET)
        {
             GPIO_Toggle_Pin(GPIOB, GPIO_PIN_13);
        }
    }

    return 0;
}

void wait_ms(uint32_t time)
{
    uint32_t i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 1000; j++)
            ;
    }
}
