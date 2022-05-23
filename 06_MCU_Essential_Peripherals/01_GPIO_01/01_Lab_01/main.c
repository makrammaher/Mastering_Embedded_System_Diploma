/*
 *           File: main.c
 *     Created on: Thursday 19/05/2022 21:46
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx MCU Interrupts
 *
 *
 */
#include <stdint.h>

/* RCC */
#define RCC_BASE        0x40021000
#define RCC_APB2ENR     *((volatile uint32_t *)(RCC_BASE + 0x18))
#define RCC_CFGR        *((volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_CR          *((volatile uint32_t *)(RCC_BASE + 0x00))

/* GPIO-A */
#define GPIOA_BASE      0x40010800
#define GPIOA_CRL       *((volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_CRH       *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_IDR       *((volatile uint32_t *)(GPIOA_BASE + 0x08))
#define GPIOA_ODR       *((volatile uint32_t *)(GPIOA_BASE + 0x0C))

/* GPIO-B */
#define GPIOB_BASE      0x40010C00
#define GPIOB_CRL       *((volatile uint32_t *)(GPIOB_BASE + 0x00))
#define GPIOB_CRH       *((volatile uint32_t *)(GPIOB_BASE + 0x04))
#define GPIOB_IDR       *((volatile uint32_t *)(GPIOB_BASE + 0x08))
#define GPIOB_ODR       *((volatile uint32_t *)(GPIOB_BASE + 0x0C))


void gpio_init(void);
void wait_ms(uint32_t time);
void clock_init(void);

int main(void)
{
    uint8_t b1_flag = 0;

    /* Initialization */
    clock_init();
    gpio_init();

    while (1)
    {
        /* Button 1 handler */
        if (((GPIOA_IDR & (1 << 1)) >> 1) == 0)
        {
            /* Button 1 is Pressed */
            if (b1_flag == 0)
            {
                /* Toggle led */
                GPIOB_ODR ^= (1 << 1);
                /* Set flag of pressed */
                b1_flag = 1;
            }
        }
        else
        {
            /* Clear flag of pressed */
            b1_flag = 0;
        }

        /* Button 2 handler */
        if (((GPIOA_IDR & (1 << 13)) >> 13) == 1)
        {
            /* Button 2 is Pressed */
            /* Toggle led */
            GPIOB_ODR ^= (1 << 13);

        }
        wait_ms(3);
    }

    return 0;
}

void gpio_init(void)
{

    /* Configration of GPIO-A */
    /* PIN 1 as Input floating */
    GPIOA_CRL &= ~((uint32_t)0x0F << 4);
    GPIOA_CRL |= ((uint32_t)0x01 << 6);
    /* PIN 13 as Input floating */
    GPIOA_CRH &= ~((uint32_t)0x0F << 20);
    GPIOA_CRH |= ((uint32_t)0x01 << 22);

    /* Configration of GPIO-B */
    /* PIN 1 as Output push-pull */
    GPIOB_CRL &= ~((uint32_t)0x0F << 4);
    GPIOB_CRL |= ((uint32_t)0x01 << 4);
    /* PIN 13 as Output push-pull */
    GPIOB_CRH &= ~((uint32_t)0x0F << 20);
    GPIOB_CRH |= ((uint32_t)0x01 << 20);

}

void wait_ms(uint32_t time)
{
    uint32_t i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 1000; j++);
    }
}

void clock_init(void)
{
    /* use internal RC Oscilator and PLL (4x8) 32MHz */
    /*
    Bits 21:18 PLLMUL: PLL multiplication factor
    These bits are written by software to define the PLL multiplication factor. These bits can be
    written only when PLL is disabled.
    Caution: The PLL output frequency must not exceed 72 MHz.
    0000: PLL input clock x 2
    0001: PLL input clock x 3
    0010: PLL input clock x 4
    0011: PLL input clock x 5
    0100: PLL input clock x 6
    0101: PLL input clock x 7
    0110: PLL input clock x 8 <---
    0111: PLL input clock x 9
    1000: PLL input clock x 10
    1001: PLL input clock x 11
    1010: PLL input clock x 12
    1011: PLL input clock x 13
    1100: PLL input clock x 14
    1101: PLL input clock x 15
    1110: PLL input clock x 16
    1111: PLL input clock x 16
    */
    RCC_CFGR |= (0b0110 << 18);

    /*
    Bit 16 PLLSRC: PLL entry clock source
    Set and cleared by software to select PLL clock source. This bit can be written only when
    PLL is disabled.
    0: HSI oscillator clock / 2 selected as PLL input clock <---
    1: HSE oscillator clock selected as PLL input clock
    */
    RCC_CFGR &= ~(1 << 16);

    /*
    Bit 24 PLLON: PLL enable
    Set and cleared by software to enable PLL.
    Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
    PLL clock is used as system clock or is selected to become the system clock.
    0: PLL OFF
    1: PLL ON
    */
    RCC_CR |= (1 << 24);

    /*
    Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
    Set and cleared by software to control the division factor of the APB high-speed clock
    (PCLK2).
    0xx: HCLK not divided <---
    100: HCLK divided by 2
    101: HCLK divided by 4
    110: HCLK divided by 8
    111: HCLK divided by 16
    */
    RCC_CFGR &= ~ (0 << 13);

    /*
    Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
    Set and cleared by software to control the division factor of the APB low-speed clock
    (PCLK1).
    Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
    0xx: HCLK not divided
    100: HCLK divided by 2 <---
    101: HCLK divided by 4
    110: HCLK divided by 8
    111: HCLK divided by 16
    */
    RCC_CFGR |= (0b100 << 8);

    /*
    Bits 7:4 HPRE: AHB prescaler
    Set and cleared by software to control the division factor of the AHB clock.
    0xxx: SYSCLK not divided <---
    1000: SYSCLK divided by 2
    1001: SYSCLK divided by 4
    1010: SYSCLK divided by 8
    1011: SYSCLK divided by 16
    1100: SYSCLK divided by 64
    1101: SYSCLK divided by 128
    1110: SYSCLK divided by 256
    1111: SYSCLK divided by 512
    */
    RCC_CFGR &= ~ (1 << 7);

    /*
    Bits 1:0 SW: System clock switch
    Set and cleared by software to select SYSCLK source.
    Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
    failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
    System is enabled).
    00: HSI selected as system clock
    01: HSE selected as system clock
    10: PLL selected as system clock <---
    11: not allowed
    */
    RCC_CFGR |= (0b10);

    /* Enable Clock to GPIOA */
    RCC_APB2ENR |= (1 << 2);

    /* Enable clock to GPIOB */
    RCC_APB2ENR |= (1 << 3);
}

