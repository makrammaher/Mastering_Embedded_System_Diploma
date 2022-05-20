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

/* GPIO */
#define GPIOA_BASE      0x40010800
#define GPIOA_CRL       *((volatile uint32_t *)(GPIOA_BASE + 0x00))

#define GPIOC_BASE      0x40011000
#define GPIOC_CRH       *((volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR       *((volatile uint32_t *)(GPIOC_BASE + 0x0C))

/* EXTI */
#define EXTI_BASE       0x40010400
#define EXTI_IMR        *((volatile uint32_t *)(EXTI_BASE + 0x00))
#define EXTI_RTSR       *((volatile uint32_t *)(EXTI_BASE + 0x08))
#define EXTI_FTSR       *((volatile uint32_t *)(EXTI_BASE + 0x0C))
#define EXTI_PR         *((volatile uint32_t *)(EXTI_BASE + 0x14))

/* NVIC */
#define NVIC_BASE       0xE000E100
#define NVIC_ISER0      *((volatile uint32_t *)(NVIC_BASE + 0x00))

/* AFIO */
#define AFIO_BASE       0x40010000
#define AFIO_EXTICR1    *((volatile uint32_t *)(AFIO_BASE + 0x08))


void clock_init(void);
void gpio_init(void);
void exti_init(void);

int main(void)
{
    /* Initialization */
    clock_init();
    gpio_init();
    exti_init();

    while (1);

    return 0;
}

void exti_init(void)
{
    /* Set AFIO to Connect PC0 to EXTI0 */
    AFIO_EXTICR1 = 0;
    /* Enable Rising Eage on EXTI0 */
    EXTI_RTSR |= (1<<0);
    /* Enable Mask on EXTI0 */
    EXTI_IMR |= (1<<0);
    /* Set NVIC to Enable EXIT0 */
    NVIC_ISER0 |= (1<<6);

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

    /* Enable clock to GPIOC */
    RCC_APB2ENR |= (1 << 4);

    /* Enable Clock to GPIOA */
    RCC_APB2ENR |= (1 << 2);

    /* Enable clock to AFIO */
    RCC_APB2ENR |= (1 << 0);

}

void gpio_init(void)
{
    /* Enable P0 as an Floating Input */
    GPIOA_CRL |= (1<<2);
    /* Enable P13 as an Output PIN */
    GPIOC_CRH &= 0xFF0FFFFF;
    GPIOC_CRH |= 0x00200000;

}

void EXTI0_handler(void)
{
    /* Toggle led */
    GPIOC_ODR ^= (1 << 13);

    /* clear interrupt pending status write 1 to clear */
    EXTI_PR |= (1<<0);
}