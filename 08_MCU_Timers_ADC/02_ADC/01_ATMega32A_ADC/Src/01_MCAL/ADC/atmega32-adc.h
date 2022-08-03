/*
 *           File: atmega32-adc.h
 *     Created on: Tuesday 02/08/2022 12:32
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 ADC Driver
 *
 *
 */

#ifndef _ATMEGA32_ADC_H_
#define _ATMEGA32_ADC_H_

#include "atmega32.h"

typedef struct 
{
    uint8_t Mode;   /* Specifies the Mode of ADC */
                    /* Must be set by @ref ADC_MODE_define */

    uint8_t VRef;   /* Specifies the Voltage Reference of ADC */
                    /* Must be set by @ref ADC_VREF_define */

    uint8_t Prescaller; /* Specifies the Prescaller of ADC */
                        /* Must be set by @ref ADC_PRESCALLER_define */

    uint8_t Interrupt_Enable;   /* Specifies the Interrupt Enable of ADC */
                                /* Must be set by @ref ADC_INTERRUPT_define */

    void (*P_IRQ_Callback)(void);   /* Poiter to function callback Which will be called once the IRQ Happend */
} ADC_Config_t;


/** @defgroup ADC_MODE_define
 *  @brief ADC Modes Define
 * @{
 */
#define ADC_MODE_SINGLE_CONVERSION      0x00
#define ADC_MODE_FREE_RUNNING           0x01
#define ADC_MODE_ANALOGE_COMPARATOR     0x21
#define ADC_MODE_EXTI0                  0x41
#define ADC_MODE_TIMER0_CM              0x61
#define ADC_MODE_TIMER0_OF              0x81
#define ADC_MODE_TIMER1_CM              0xA1
#define ADC_MODE_TIMER1_OF              0xC1
#define ADC_MODE_TIMER1_CE              0xE1

/**
 * @}
 */

/** @defgroup ADC_CHANNEL_define
 *  @brief ADC Channel Define
 * @{
 */
#define ADC_CHANNEL_ADC0                0x00
#define ADC_CHANNEL_ADC1                0x01
#define ADC_CHANNEL_ADC2                0x02
#define ADC_CHANNEL_ADC3                0x03
#define ADC_CHANNEL_ADC4                0x04
#define ADC_CHANNEL_ADC5                0x05
#define ADC_CHANNEL_ADC6                0x06
#define ADC_CHANNEL_ADC7                0x07
#define ADC_CHANNEL_P_ADC0_N_ADC0_10x   0x08
#define ADC_CHANNEL_P_ADC1_N_ADC0_10x   0x09
#define ADC_CHANNEL_P_ADC0_N_ADC0_200x  0x0A
#define ADC_CHANNEL_P_ADC1_N_ADC0_200x  0x0B
#define ADC_CHANNEL_P_ADC2_N_ADC2_10x   0x0C
#define ADC_CHANNEL_P_ADC3_N_ADC2_10x   0x0D
#define ADC_CHANNEL_P_ADC2_N_ADC2_200x  0x0E
#define ADC_CHANNEL_P_ADC3_N_ADC2_200x  0x0F
#define ADC_CHANNEL_P_ADC0_N_ADC1_1x    0x10
#define ADC_CHANNEL_P_ADC1_N_ADC1_1x    0x11
#define ADC_CHANNEL_P_ADC2_N_ADC1_1x    0x12
#define ADC_CHANNEL_P_ADC3_N_ADC1_1x    0x13
#define ADC_CHANNEL_P_ADC4_N_ADC1_1x    0x14
#define ADC_CHANNEL_P_ADC5_N_ADC1_1x    0x15
#define ADC_CHANNEL_P_ADC6_N_ADC1_1x    0x16
#define ADC_CHANNEL_P_ADC7_N_ADC1_1x    0x17
#define ADC_CHANNEL_P_ADC0_N_ADC2_1x    0x18
#define ADC_CHANNEL_P_ADC1_N_ADC2_1x    0x19
#define ADC_CHANNEL_P_ADC2_N_ADC2_1x    0x1A
#define ADC_CHANNEL_P_ADC3_N_ADC2_1x    0x1B
#define ADC_CHANNEL_P_ADC4_N_ADC2_1x    0x1C
#define ADC_CHANNEL_P_ADC5_N_ADC2_1x    0x1D
#define ADC_CHANNEL_1_22V_V_BG          0x1E
#define ADC_CHANNEL_0V_GND              0x1F

/**
 * @}
 */


/** @defgroup ADC_VREF_define
 *  @brief ADC Voltage Reference Define
 * @{
 */
#define ADC_VREF_AREF                   0x00
#define ADC_VREF_AVCC_WITH_EXTERNAL_CAP 0x40
#define ADC_VREF_INTERNAL_2_56V         0xC0

/**
 * @}
 */

/** @defgroup ADC_PRESCALLER_define
 *  @brief ADC Prescaller Define
 * @{
 */
#define ADC_PRESCALLER_2        0x00
#define ADC_PRESCALLER_4        0x02
#define ADC_PRESCALLER_8        0x03
#define ADC_PRESCALLER_16       0x04
#define ADC_PRESCALLER_32       0x05
#define ADC_PRESCALLER_64       0x06
#define ADC_PRESCALLER_128      0x07

/**
 * @}
 */


/** @defgroup ADC_INTERRUPT_define
 *  @brief ADC interrupt Define
 * @{
 */
#define ADC_INTERRUPT_DISABLE       0x00
#define ADC_INTERRUPT_ENABLE        0x04

/**
 * @}
 */

/** @defgroup ADC_POLLING_define
 *  @brief ADC Polling Define
 * @{
 */

#define ADC_POLLING_ENABLE      1
#define ADC_POLLING_DISABLE     0

/**
 * @}
 */


/**
 * @brief Initialize ADC
 * 
 * @param Config : Pointer to structure that hold configuration of ADC
 */
void ADC_Init(ADC_Config_t * Config);

/**
 * @brief Start Single Conversion or First Conversion in free running mode
 * 
 * @param Channel : Specifies the Input Channel of ADC
 *                  Must be set by @ref ADC_CHANNEL_define
 */
void ADC_Start_Conversion(uint8_t Channel);

/**
 * @brief get Conversion Flag
 * 
 * @return uint8_t Confersion Flag
 */
uint8_t ADC_Conversion_Flag(void);

/**
 * @brief Clear Conversion Flag
 * 
 */
void ADC_Clear_Conversion_Flag(void);

/**
 * @brief Read ADC Value
 * 
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref ADC_POLLING_define 
 * @return uint16_t : ADC Value
 */
uint16_t ADC_Read(uint8_t Polling_Enable);


#endif