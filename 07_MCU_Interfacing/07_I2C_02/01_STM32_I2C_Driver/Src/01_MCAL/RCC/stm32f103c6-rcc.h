/*
 *           File: stm32f103c6-rcc.h
 *     Created on: Monday 20/06/2022 05:40
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 RCC Driver
 *
 *
 */

#ifndef _STM32F103C6_RCC_H_
#define _STM32F103C6_RCC_H_

#include "stm32f103c6.h"

#define RCC_HSI_CLK 8000000UL
#define RCC_HSE_CLK 16000000UL


/**
 * @brief getting the clock frequency of the system bus
 * 
 * @return uint32_t returned clock frequancy
 */
uint32_t RCC_Get_SYSCLK_Freq(void);


/**
 * @brief getting the clock frequency of the AHB bus
 * 
 * @return uint32_t returned clock frequancy
 */
uint32_t RCC_Get_HCLK_Freq(void);


/**
 * @brief getting the clock frequency of the APB1 bus
 * 
 * @return uint32_t returned clock frequancy
 */
uint32_t RCC_Get_PCLK1_Freq(void);


/**
 * @brief getting the clock frequency of the APB2 bus
 * 
 * @return uint32_t returned clock frequancy
 */
uint32_t RCC_Get_PCLK2_Freq(void);


#endif