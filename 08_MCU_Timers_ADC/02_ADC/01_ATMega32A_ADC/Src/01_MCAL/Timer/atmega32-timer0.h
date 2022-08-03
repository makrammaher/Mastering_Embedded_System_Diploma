/*
 *           File: atmega32-timer0.h
 *     Created on: Thursday 14/07/2022 17:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 TIMER Driver
 *
 *
 */

#ifndef _ATMEGA32_TIMER0_H_
#define _ATMEGA32_TIMER0_H_

#include "atmega32.h"
#include "atmega32-gpio.h"

typedef struct
{
    uint8_t Mode;   /* Specifies the Timer 0 Mode */
                    /* Must be set by @ref TIMER0_MODE_define */

    uint8_t Compare_Match_Output;   /* Specifies the Compare Match Output of Timer 0 */
                                    /* Must be set by @ref TIMER0_COMPARE_MATCH_OUTPUT_define */
    
    uint8_t Clock;  /* Specifies the Timer 0 Clock */
                    /* Must be set by @ref TIMER0_CLOCK_define */

    uint8_t Interrupt_Enable;   /* Specifies the Interrupt Enable of SPI */
                                /* Must be set by @ref TIMER0_INTERRUPT_define */

    void (*P_IRQ_Compare_Match_Callback)(void);   /* Poiter to function callback Which will be called once the IRQ Happend */

    void (*P_IRQ_Over_Flow_Callback)(void);   /* Poiter to function callback Which will be called once the IRQ Happend */
} TIMER0_Config;


/** @defgroup TIMER0_MODE_define
 *  @brief Timer 0 Modes Define
 * @{
 */
#define TIMER0_MODE_NORMAL              0x00
#define TIMER0_MODE_PWM_PHASE_CORRECT   0x40
#define TIMER0_MODE_CTC                 0x08
#define TIMER0_MODE_PWM_FAST            0x48

/**
 * @}
 */


/** @defgroup TIMER0_COMPARE_MATCH_OUTPUT_define
 *  @brief Timer 0 Compare match output Define
 * @{
 */
#define TIMER0_COMPARE_MATCH_OUTPUT_DISCONNECT_OC0      0x00
#define TIMER0_COMPARE_MATCH_OUTPUT_TOGGLE_OC0          0x10
#define TIMER0_COMPARE_MATCH_OUTPUT_CLEAR_OC0           0x20
#define TIMER0_COMPARE_MATCH_OUTPUT_SET_OC0             0x30
#define TIMER0_COMPARE_MATCH_OUTPUT_PWM_NON_INVERTING   0x20
#define TIMER0_COMPARE_MATCH_OUTPUT_PWM_INVERTING       0x30

/**
 * @}
 */

/** @defgroup TIMER0_CLOCK_define
 *  @brief Timer 0 Clk Define
 * @{
 */
#define TIMER0_CLOCK_NO_CLK_SOURCE  0x00
#define TIMER0_CLOCK_DIV_1          0x01
#define TIMER0_CLOCK_DIV_8          0x02
#define TIMER0_CLOCK_DIV_64         0x03
#define TIMER0_CLOCK_DIV_256        0x04
#define TIMER0_CLOCK_DIV_1024       0x05
#define TIMER0_CLOCK_T0_FALLING     0x06
#define TIMER0_CLOCK_T0_RISING      0x07


/**
 * @}
 */

/** @defgroup TIMER0_INTERRUPT_define
 *  @brief Timer 0 interrupt Define
 * @{
 */
#define TIMER0_INTERRUPT_DISABLE        0x00
#define TIMER0_INTERRUPT_COMPARE_MATCH  0x02
#define TIMER0_INTERRUPT_OVERFLOW       0x01

/**
 * @}
 */

/**
 * @brief Initialzie TIMER0
 * 
 * @param Config : Pointer to structure that hold configuration of TIMER0
 */
void TIMER0_Init(TIMER0_Config *Config);

/**
 * @brief Reset Timer 0
 * 
 */
void TIMER0_Reser(void);

/**
 * @brief Start Timer 0
 * 
 */
void TIMER0_Start(void);

/**
 * @brief Stop Timer 0
 * 
 */
void TIMER0_Stop(void);

/**
 * @brief Set Compare Value of Timer0
 * 
 * @param CompareValue : Compare Value
 */
void TIMER0_Set_Compare_Value(uint8_t CompareValue);

/**
 * @brief Get Compare Value of Timer0
 * 
 * @return uint8_t : Compare Value
 */
uint8_t TIMER0_Get_Compare_Value(void);

/**
 * @brief Set Counter Value
 * 
 * @param CounterValue : Counter Value
 */
void TIMER0_Set_Counter_Value(uint8_t CounterValue);

/**
 * @brief Get Counter Value
 * 
 * @return uint8_t : Counter Value
 */
uint8_t TIMER0_Get_Counter_Value(void);

/**
 * @brief Get Over flow flag
 * 
 * @return uint8_t OverFlow Flag
 */
uint8_t TIMER0_Get_OverFlow_Flag(void);

/**
 * @brief Get Compare Flag
 * 
 * @return uint8_t Compare Flag
 */
uint8_t TIMER0_Get_Compare_Flag(void);

/**
 * @brief Clears Over flow flag
 * 
 */
void TIMER0_Clear_OverFlow_Flag(void);

/**
 * @brief Clear Compare Flag
 * 
 */
void TIMER0_Clear_Compare_Flag(void);





#endif