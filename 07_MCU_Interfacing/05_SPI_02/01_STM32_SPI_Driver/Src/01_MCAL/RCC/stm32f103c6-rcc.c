/*
 *           File: stm32f103c6-rcc.h
 *     Created on: Monday 20/06/2022 05:40
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 RCC Driver
 *
 *
 */

#include "stm32f103c6-rcc.h"

/**
 * @brief getting the clock frequency of the system bus
 * 
 * @return uint32_t returned clock frequancy
 */
uint32_t RCC_Get_SYSCLK_Freq(void)
{
    uint32_t SYSCLK;
    switch((RCC->CFGR & 0x0C) >> 2)
    {
        case 0x00:
        SYSCLK = RCC_HSI_CLK;
        break;
        case 0x01:
        SYSCLK = RCC_HSE_CLK;
        break;
        case 0x02:
            /* No time to do this :P */
        break;
        default:
        break;
    }
    return SYSCLK;
}


/**
 * @brief getting the clock frequency of the AHB bus
 * 
 * @return uint32_t returned clock frequancy
 */
uint32_t RCC_Get_HCLK_Freq(void)
{
    uint32_t HCLK;
    switch((RCC->CFGR & 0xF0) >> 4)
    {
        case 0x00:
        HCLK = RCC_Get_SYSCLK_Freq();
        break;
        case 0x08:
        HCLK = RCC_Get_SYSCLK_Freq() / 2;
        break;
        case 0x09:
        HCLK = RCC_Get_SYSCLK_Freq() / 4;
        break;
        case 0x0A:
        HCLK = RCC_Get_SYSCLK_Freq() / 8;
        break;
        case 0x0B:
        HCLK = RCC_Get_SYSCLK_Freq() / 16;
        break;
        case 0x0C:
        HCLK = RCC_Get_SYSCLK_Freq() / 64;
        break;
        case 0x0D:
        HCLK = RCC_Get_SYSCLK_Freq() / 128;
        break;
        case 0x0E:
        HCLK = RCC_Get_SYSCLK_Freq() / 256;
        break;
        case 0x0F:
        HCLK = RCC_Get_SYSCLK_Freq() / 512;
        break;
        default:
        break;
    }
    return HCLK;
}


/**
 * @brief getting the clock frequency of the APB1 bus
 * 
 * @return uint32_t returned clock frequancy
 */
uint32_t RCC_Get_PCLK1_Freq(void)
{
    uint32_t PCLK1;
    switch((RCC->CFGR & 0x0700) >> 8)
    {
        case 0x00:
        PCLK1 = RCC_Get_HCLK_Freq();
        break;
        case 0x04:
        PCLK1 = RCC_Get_HCLK_Freq() / 2;
        break;
        case 0x05:
        PCLK1 = RCC_Get_HCLK_Freq() / 4;
        break;
        case 0x06:
        PCLK1 = RCC_Get_HCLK_Freq() / 8;
        break;
        case 0x07:
        PCLK1 = RCC_Get_HCLK_Freq() / 16;
        break;
        default:
        break;
    }
    return PCLK1;
}


/**
 * @brief getting the clock frequency of the APB2 bus
 * 
 * @return uint32_t returned clock frequancy
 */
uint32_t RCC_Get_PCLK2_Freq(void)
{
    uint32_t PCLK2;
    switch((RCC->CFGR & 0x3800) >> 11)
    {
        case 0x00:
        PCLK2 = RCC_Get_HCLK_Freq();
        break;
        case 0x04:
        PCLK2 = RCC_Get_HCLK_Freq() / 2;
        break;
        case 0x05:
        PCLK2 = RCC_Get_HCLK_Freq() / 4;
        break;
        case 0x06:
        PCLK2 = RCC_Get_HCLK_Freq() / 8;
        break;
        case 0x07:
        PCLK2 = RCC_Get_HCLK_Freq() / 16;
        break;
        default:
        break;
    }
    return PCLK2;
}