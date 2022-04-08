/*
 *           File: main.c
 *     Created on: Thursday 07/04/2022 19:09
 *         Author: Makram Maher Makram
 *        Subject: Testing Makefile
 *
 *
 */

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#include <stdint.h>

typedef union
{
    /* data */
    uint32_t allBytes;
    struct
    {
        /* data */
        uint32_t reserved : 2;
        uint32_t IOPAEN : 1;
    } PIN;

} APB2ENR_t;

typedef union
{
    /* data */
    uint32_t allBytes;
    struct
    {
        /* data */
        uint32_t reserved : 20;
        uint32_t MODE : 4;
    } PIN;
} GPIOA_CRH_t;

typedef union
{
    /* data */
    uint32_t allBytes;
    struct
    {
        /* data */
        uint32_t reserved : 13;
        uint32_t P_13 : 1;
    } PIN;
} GPIOA_ODR_t;

#define APB2ENR ((volatile APB2ENR_t *)(RCC_BASE + 0x18))
#define GPIOACRH ((volatile GPIOA_CRH_t *)(GPIOA_BASE + 0x04))
#define GPIOAODR ((volatile GPIOA_ODR_t *)(GPIOA_BASE + 0x0C))

int main(void)
{
    uint32_t i;
    APB2ENR->PIN.IOPAEN = 1;
    GPIOACRH->PIN.MODE = 2;
    while (1)
    {
        GPIOAODR->PIN.P_13 = 1;
        for (i = 0; i < 150000; i++)
            ;
        GPIOAODR->PIN.P_13 = 0;
        for (i = 0; i < 150000; i++)
            ;
    }
    return 0;
}