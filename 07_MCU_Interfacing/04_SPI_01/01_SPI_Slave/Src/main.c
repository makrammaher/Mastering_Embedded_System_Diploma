/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 Slave SPI Interfacing
 *
 *
 */

#include "atmega32-gpio.h"

void wait_ms(uint8_t time);

void SPI_Init(void)
{
    GPIO_Init(GPIOB, GPIO_MODE_INPUT_FLOATING, GPIO_PIN_4);
    GPIO_Init(GPIOB, GPIO_MODE_INPUT_FLOATING, GPIO_PIN_5);
    GPIO_Init(GPIOB, GPIO_MODE_INPUT_FLOATING, GPIO_PIN_7);

    GPIO_Init(GPIOB, GPIO_MODE_OUTPUT, GPIO_PIN_6);

    SETBIT(SPCR, 6);
}

uint8_t SPI_Transmit(uint8_t data)
{
    SPDR = data;
    
    while (!(SPSR & (1 << 7)))
        ;
    
    return SPDR;
}

int main(void)
{
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_0);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_1);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_2);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_3);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_4);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_5);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_6);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_7);
    GPIO_Write_Port(GPIOA, 0);
    SPI_Init();
    wait_ms(10);
    /* Initialize SPI */

    while (1)
    {
        uint8_t i = 0;
        for (i = 255; i > 0; i--)
        {
            GPIO_Write_Port(GPIOA, SPI_Transmit(i));
        }
    }
    return 0;
}