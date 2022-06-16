/*
 *           File: atmega32-exti.h
 *     Created on: Monday 06/06/2022 22:02
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 EXTI Driver
 *
 *
 */
#include "atmega32-exti.h"

void (*GP_IRQ_CallBack[3])();

/**
 * @brief
 *
 * @param EXTIx Must be set by one of those (EXTI0, EXTI1, EXTI2)
 * @param Trigger Must be set by @ref EXTI_TRIGGER_def
 * @param P_CallBack Pointer to callback function
 */
void EXTI_Init(uint8_t EXTIx, uint8_t Trigger, void (*P_CallBack)(void))
{
    switch (EXTIx)
    {
    case EXTI0:
        GPIO_Init(EXTI0_PORT, GPIO_MODE_INPUT_FLOATING, EXTI0_PIN);
        MCUCR &= ~(0b11 << 0);
        MCUCR |= (Trigger << 0);
        GICR |= (1 << 6);
        break;
    case EXTI1:
        GPIO_Init(EXTI1_PORT, GPIO_MODE_INPUT_FLOATING, EXTI1_PIN);
        MCUCR &= ~(0b11 << 2);
        MCUCR |= (Trigger << 2);
        GICR |= (1 << 7);
        break;
    case EXTI2:
        GPIO_Init(EXTI2_PORT, GPIO_MODE_INPUT_FLOATING, EXTI2_PIN);
        MCUCSR &= ~(1 << 6);
        MCUCSR |= ((Trigger & 0x01) << 6);
        GICR |= (1 << 5);
        break;
    default:
        break;
    }
    GP_IRQ_CallBack[EXTIx] = P_CallBack;
    SREG |= (1 << 7);
}

/**
 * @brief
 *
 * @param EXTIx Must be set by one of those (EXTI0, EXTI1, EXTI2)
 */
void EXTI_Reset(uint8_t EXTIx)
{
    switch (EXTIx)
    {
    case EXTI0:
        MCUCR &= ~(0b11 << 0);
        GICR &= ~(1 << 6);
        break;
    case EXTI1:
        MCUCR &= ~(0b11 << 2);
        GICR &= ~(1 << 7);
        break;
    case EXTI2:
        MCUCSR &= ~(1 << 6);
        GICR &= ~(1 << 5);
        break;
    default:
        break;
    }
    GP_IRQ_CallBack[EXTIx] = 0;
}

void __vector_1 (void) __attribute__ ((signal,used, externally_visible)); 

void __vector_1 (void)
{
    GIFR |= (1 << 6);
    GP_IRQ_CallBack[EXTI0]();
}

void __vector_2 (void) __attribute__ ((signal,used, externally_visible)); 

void __vector_2 (void)
{
    GIFR |= (1 << 6);
    GP_IRQ_CallBack[EXTI0]();
}


void __vector_3 (void) __attribute__ ((signal,used, externally_visible)); 

void __vector_3 (void)
{
    GIFR |= (1 << 6);
    GP_IRQ_CallBack[EXTI0]();
}
