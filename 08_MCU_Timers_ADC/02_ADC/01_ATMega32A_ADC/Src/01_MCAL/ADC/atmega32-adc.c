/*
 *           File: atmega32-adc.h
 *     Created on: Tuesday 02/08/2022 12:32
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 ADC Driver
 *
 *
 */
#include "atmega32-adc.h"

void (*volatile GP_ADC_IRQ_CallBack)(void);

/**
 * @brief Initialize ADC
 *
 * @param Config : Pointer to structure that hold configuration of ADC
 */
void ADC_Init(ADC_Config_t *Config)
{
    /* Set V Ref. */
    ADMUX |= Config->VRef;

    /* Set Prescaller */
    ADCSRA |= Config->Prescaller;

    /* Set Mode */
    SFIOR |= (Config->Mode & 0xE0);
    ADCSRA |= (Config->Mode << 5);
    

    /* Set Interrupt Enable */
    ADCSRA |= Config->Interrupt_Enable;
    if (Config->Interrupt_Enable)
    {
        /* Set Callback function */
        GP_ADC_IRQ_CallBack = Config->P_IRQ_Callback;
        /* Enable Global Interrupt */
        SREG |= (1 << 7);
    }

    /* Enable ADC */
    ADCSRA |= (1 << 7);
}

/**
 * @brief Start Single Conversion or First Conversion in free running mode
 *
 * @param Channel : Specifies the Input Channel of ADC
 *                  Must be set by @ref ADC_CHANNEL_define
 */
void ADC_Start_Conversion(uint8_t Channel)
{
    /* Select Channel */
    ADMUX |= Channel;

    /* Start Conversion */
    ADCSRA |= (1 << 6);
}

/**
 * @brief get Conversion Flag
 *
 * @return uint8_t Confersion Flag
 */
uint8_t ADC_Conversion_Flag(void)
{
    return ((ADCSRA & 0x10));
}

/**
 * @brief Clear Conversion Flag
 *
 */
void ADC_Clear_Conversion_Flag(void)
{
    ADCSRA |= (1 << 4);
}

/**
 * @brief Read ADC Value
 *
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref ADC_POLLING_define
 * @return uint16_t : ADC Value
 */
uint16_t ADC_Read(uint8_t Polling_Enable)
{
    if (Polling_Enable == ADC_POLLING_ENABLE)
    {
        while (ADC_Conversion_Flag() == 0)
            ;
    }
    uint16_t adcRead = 0;
    adcRead = ADCL;
    adcRead |= ADCH << 8;
    return adcRead;
}

/* ISR SPI_vect */
void __vector_16(void) __attribute__((signal, used, externally_visible));

void __vector_16(void)
{
    GP_ADC_IRQ_CallBack();
}
