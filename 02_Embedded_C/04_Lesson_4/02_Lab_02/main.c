/*
 *           File: main.c
 *     Created on: Friday 15/04/2022 23:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx Toggle P13 LED
 *
 *
 */
#include<stdint.h>

#define APB2ENR     *((volatile uint32_t *)(0x40021018))
#define GPIOCCRH    *((volatile uint32_t *)(0x40011004))

typedef union
{
    uint32_t all_byte;
    struct
    {
        uint32_t reserved:13;
        uint32_t P13:1;
    }pin;
}GPIOC_ODR_t;

#define GPIOCODR    ((volatile GPIOC_ODR_t *)(0x4001100C))

int main(void)
{
    uint32_t i;
    APB2ENR |= (1<<4);
    GPIOCCRH &= (0xFF0FFFFF);
    GPIOCCRH |= (0x00200000);
    while(1)
    {
        GPIOCODR->pin.P13 = 0;
        for(i = 0;i<100000;i++);
        GPIOCODR->pin.P13 = 1;
        for(i = 0;i<100000;i++);
    }
    return 0;
}