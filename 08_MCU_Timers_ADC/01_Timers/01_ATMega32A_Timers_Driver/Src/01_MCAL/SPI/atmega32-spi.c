/*
 *           File: atmega32-spi.c
 *     Created on: Sunday 26/06/2022 20:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 SPI Driver
 *
 *
 */

#include "atmega32-spi.h"

void (* volatile GP_SPI_IRQ_CallBack)(void);


/**
 * @brief Initialize SPI
 *
 * @param Config is a poiner to SPI_Config structure that hold the configuration of the SPI
 */
void SPI_Init(SPI_Config *Config)
{
    /* Initialize GPIO */
    if (Config->Mode == SPI_MODE_MASTER)
    {
        GPIO_Init(SPI_GPIO, GPIO_MODE_OUTPUT, SPI_SS_PIN);
        GPIO_Write_Pin(SPI_GPIO, SPI_SS_PIN, GPIO_PIN_HIGH);
        GPIO_Init(SPI_GPIO, GPIO_MODE_OUTPUT, SPI_MOSI_PIN);
        GPIO_Init(SPI_GPIO, GPIO_MODE_OUTPUT, SPI_SCK_PIN);
        GPIO_Init(SPI_GPIO, GPIO_MODE_INPUT_FLOATING, SPI_MISO_PIN);
    }
    else if (Config->Mode == SPI_MODE_SLAVE)
    {
        GPIO_Init(SPI_GPIO, GPIO_MODE_INPUT_FLOATING, SPI_SS_PIN);
        GPIO_Init(SPI_GPIO, GPIO_MODE_INPUT_FLOATING, SPI_MOSI_PIN);
        GPIO_Init(SPI_GPIO, GPIO_MODE_INPUT_FLOATING, SPI_SCK_PIN);
        GPIO_Init(SPI_GPIO, GPIO_MODE_OUTPUT, SPI_MISO_PIN);
    }

    /* Set Register SPCR */
    SPCR &= ~(0xF3);
    SPCR |= (Config->Mode);
    SPCR |= (Config->DataOrder);
    SPCR |= (Config->Interrupt_Enable);
    SPCR |= (Config->ClockRate & 0b011);

    /* Set Register SPSR */
    SPSR |= (Config->ClockRate >> 2);

    /* Set IRQ Callback Function */
    GP_SPI_IRQ_CallBack = Config->P_IRQ_Callback;

    /* Enable SPI */
    SPCR |= (1 << 6);

    
}

/**
 * @brief Transmite and recdive From SPI
 *
 * @param Data : data to be transmitted
 * @return uint8_t : Received data
 */
uint8_t SPI_Transmit_Receive_Polling(uint8_t Data)
{
    SPDR = Data;
    while (!(SPSR & (1 << 7)))
        ;
    return SPDR;
}

/**
 * @brief Transmit Data To SPI
 * 
 * @param Data : Data to be transmitted
 * @param Polling_Enable :  Specifies the Polling Enable
 *                          Must be set by @ref SPI_POLLING_define
 */
void SPI_Transmit(uint8_t Data, uint8_t Polling_Enable)
{
    SPDR = Data;
    if(Polling_Enable)
    {
        while (!(SPSR & (1 << 7)))
        ;
    }
}

/**
 * @brief 
 * 
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref SPI_POLLING_define
 * @return uint8_t : Received Data
 */
uint8_t SPI_Receive(uint8_t Polling_Enable)
{
    if(Polling_Enable)
    {
        while (!(SPSR & (1 << 7)))
        ;
    }
    return SPDR;
}


/**
 * @brief get the SPIF Flag Status
 * 
 * @return uint8_t : Flag status
 */
uint8_t SPI_Get_SPIF(void)
{
    if((SPSR & (1 << 7)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* ISR SPI_vect */
void __vector_12(void) __attribute__((signal, used, externally_visible));

void __vector_12(void)
{
    GP_SPI_IRQ_CallBack();
}
