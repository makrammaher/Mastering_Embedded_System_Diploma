/*
 *           File: main.c
 *     Created on: Monday 16/05/2022 12:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx MCU Clocks
 *
 *
 */
#include <stdint.h>

#define GPIOC_BASE  0x40011000
#define RCC_BASE    0x40021000

#define GPIOC_CRH   *((volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR   *((volatile uint32_t *)(GPIOC_BASE + 0x0C))
#define APB2ENR     *((volatile uint32_t *)(RCC_BASE + 0x18))
#define RCC_CFGR    *((volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_CR      *((volatile uint32_t *)(RCC_BASE + 0x00))

int main(void)
{
    /* Initialization */
    /*Bits 26:24 MCO: Microcontroller clock output
    Set and cleared by software.
    0xx: No clock
    100: System clock (SYSCLK) selected
    101: HSI clock selected
    110: HSE clock selected
    111: PLL clock divided by 2 selected
    Note: This clock output may have some truncated cycles at startup or during MCO clock
    source switching.
    When the System Clock is selected to output to the MCO pin, make sure that this clock
    does not exceed 50 MHz (the maximum IO speed).
    */

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
    Bit 17 PLLXTPRE: HSE divider for PLL entry
    Set and cleared by software to divide HSE before PLL entry. This bit can be written only
    when PLL is disabled.
    0: HSE clock not divided
    1: HSE clock divided by 2
    */

    /*
    Bit 16 PLLSRC: PLL entry clock source
    Set and cleared by software to select PLL clock source. This bit can be written only when
    PLL is disabled.
    0: HSI oscillator clock / 2 selected as PLL input clock <---
    1: HSE oscillator clock selected as PLL input clock
    */
    RCC_CFGR &=~ (1<<16);

    /*
    Bits 15:14 ADCPRE: ADC prescaler
    Set and cleared by software to select the frequency of the clock to the ADCs.
    00: PCLK2 divided by 2
    01: PCLK2 divided by 4
    10: PCLK2 divided by 6
    11: PCLK2 divided by 8
    */

    /*
    Bits 13:11 PPRE2: APB high-speed prescaler (APB2)
    Set and cleared by software to control the division factor of the APB high-speed clock
    (PCLK2).
    0xx: HCLK not divided
    100: HCLK divided by 2
    101: HCLK divided by 4 <---
    110: HCLK divided by 8
    111: HCLK divided by 16
    */
    RCC_CFGR |= (0b101 << 11);

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
    RCC_CFGR &=~ (1<<7);

    /*
    Bits 3:2 SWS: System clock switch status
    Set and cleared by hardware to indicate which clock source is used as system clock.
    00: HSI oscillator used as system clock
    01: HSE oscillator used as system clock
    10: PLL used as system clock
    11: not applicable
    */


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

    /*
    Bit 24 PLLON: PLL enable
    Set and cleared by software to enable PLL.
    Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
    PLL clock is used as system clock or is selected to become the system clock.
    0: PLL OFF
    1: PLL ON
    */
    RCC_CR |= (1<<24);

    APB2ENR |= (1<<4);
    GPIOC_CRH &= 0xFF0FFFFF;
    GPIOC_CRH |= 0x00200000;
    uint32_t i;

    while (1)
    {
        GPIOC_ODR |= (1 << 13);
        for (i = 0; i < 50000; i++);
        GPIOC_ODR &= ~(1 << 13);
        for (i = 0; i < 50000; i++);
    }

    return 0;
}