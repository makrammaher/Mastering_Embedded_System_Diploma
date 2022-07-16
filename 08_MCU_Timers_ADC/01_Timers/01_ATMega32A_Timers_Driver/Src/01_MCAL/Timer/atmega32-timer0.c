/*
 *           File: atmega32-timer0.c
 *     Created on: Thursday 14/07/2022 17:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 TIMER Driver
 *
 *
 */

#include "atmega32-timer0.h"

void (*volatile GP_TIMER0_OVF_IRQ_CallBack)(void);
void (*volatile GP_TIMER0_COMP_IRQ_CallBack)(void);
uint8_t Timer0_Clock_Src;

/**
 * @brief Initialzie TIMER0
 *
 * @param Config : Pointer to structure that hold configuration of TIMER0
 */
void TIMER0_Init(TIMER0_Config *Config)
{
    TCCR0 = 0;
    TCCR0 |= Config->Mode;
    TCCR0 |= Config->Compare_Match_Output;
    Timer0_Clock_Src = Config->Clock;
    TIMSK &= ~(1 << 0);
    TIMSK &= ~(1 << 1);
    TIMSK |= Config->Interrupt_Enable;
    TIMER0_Set_Counter_Value(0);
    GP_TIMER0_OVF_IRQ_CallBack = Config->P_IRQ_Over_Flow_Callback;
    GP_TIMER0_COMP_IRQ_CallBack = Config->P_IRQ_Compare_Match_Callback;
    if (Config->Interrupt_Enable != 0)
    {
        /* Enable Global Interrupts Mask */
        SETBIT(SREG, 7);
    }
}

/**
 * @brief Reset Timer 0
 *
 */
void TIMER0_Reser(void)
{
    TCCR0 = 0;
    TCNT0 = 0;
    OCR0 = 0;
    TIMSK &= ~(0b011);
    TIFR |= (0b011);
    Timer0_Clock_Src = 0;
}

/**
 * @brief Start Timer 0
 *
 */
void TIMER0_Start(void)
{
    TCCR0 |= Timer0_Clock_Src;
}

/**
 * @brief Stop Timer 0
 *
 */
void TIMER0_Stop(void)
{
    TCCR0 &= !(0x07);
}

/**
 * @brief Set Compare Value of Timer0
 *
 * @param CompareValue : Compare Value
 */
void TIMER0_Set_Compare_Value(uint8_t CompareValue)
{
    OCR0 = CompareValue;
}

/**
 * @brief Get Compare Value of Timer0
 *
 * @return uint8_t : Compare Value
 */
uint8_t TIMER0_Get_Compare_Value(void)
{
    return OCR0;
}

/**
 * @brief Set Counter Value
 *
 * @param CounterValue : Counter Value
 */
void TIMER0_Set_Counter_Value(uint8_t CounterValue)
{
    TCNT0 = CounterValue;
}

/**
 * @brief Get Counter Value
 *
 * @return uint8_t : Counter Value
 */
uint8_t TIMER0_Get_Counter_Value(void)
{
    return TCNT0;
}

/**
 * @brief Get Over flow flag
 *
 * @return uint8_t OverFlow Flag
 */
uint8_t TIMER0_Get_OverFlow_Flag(void)
{
    return (TIFR & 0b01);
}

/**
 * @brief Get Compare Flag
 *
 * @return uint8_t Compare Flag
 */
uint8_t TIMER0_Get_Compare_Flag(void)
{
    return ((TIFR & 0b10) >> 1);
}

/**
 * @brief Clears Over flow flag
 *
 */
void TIMER0_Clear_OverFlow_Flag(void)
{
    TIFR |= (1 << 0);
}

/**
 * @brief Clear Compare Flag
 *
 */
void TIMER0_Clear_Compare_Flag(void)
{
    TIFR |= (1 << 1);
}

/* ISR TIMER0_COMP_vect */
void __vector_10(void) __attribute__((signal, used, externally_visible));

void __vector_10(void)
{
    GP_TIMER0_COMP_IRQ_CallBack();
}

/* ISR TIMER0_OVF_vect */
void __vector_11(void) __attribute__((signal, used, externally_visible));

void __vector_11(void)
{
    GP_TIMER0_OVF_IRQ_CallBack();
}
