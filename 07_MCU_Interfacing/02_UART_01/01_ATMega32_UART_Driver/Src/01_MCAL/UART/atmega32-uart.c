/*
 *           File: atmega32-uart.c
 *     Created on: Sunday 12/06/2022 20:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 UART Driver
 *
 *
 */

#include "atmega32-uart.h"
#include "math.h"

/**
 * @brief
 *
 * @param Config : is a poiner to USART_Config structure that hold the configuration of the USART
 */
void USART_Init(USART_Config_t *Config)
{
    /* Set Baudrate first */
    UBRRL = (Config->UBRR_Value & 0xFF);
    UBRRH &= ~(0x0F);
    UBRRH |= ((Config->UBRR_Value >> 8) & 0x0F);
    /* Set Double speed or not */
    UCSRA &= ~(Config->Speed_Mode);

    /* Set UCSRB Register */
    UCSRB &= ~(0b00011100);
    UCSRB |= ((Config->Mode & 0b11000) | ((Config->Data & 0b1000) >> 1));

    /* Set UCSRC Register */
    UCSRC &= ~(0b01111110);
    UCSRC |= (((Config->Mode & 0b100000) << 1) | Config->Parity | Config->Stop | (Config->Data & 0b110));
}

/**
 * @brief
 *
 * @param Data : the data to be tansmitted
 */
void USART_Transmit(uint16_t Data)
{
    while (!(UCSRA & (1 << 5)))
        ;
    UCSRB &= ~(1 << 0);
    UCSRB |= ((Data & 0x100) >> 8);
    UDR = Data & 0xFF;
}

/**
 * @brief
 *
 * @return uint16_t : the recived data
 */
uint16_t USART_Recive(void)
{
    while (!(UCSRA & (1 << 7)))
        ;
    uint16_t Data = 0;
    Data = (uint16_t)(UCSRB & (1 << 1)) << 7;
    Data |= UDR;
    return Data;
}

/**
 * @brief
 *
 * @param str : Pointer to string
 */
void USART_SendString(char *str)
{
    while (*str != 0)
    {
        USART_Transmit((uint16_t)*str);
        str++;
    }
}

/**
 * @brief
 *
 * @param buff : Buffer to hold the recived string
 * @param Terminator : Terminator Character
 */
void USART_ReadString(char *buff, char Terminator)
{
    char recivedChar = Terminator + 1;
    while (recivedChar != Terminator)
    {
        recivedChar = (char)USART_Recive();
        if(recivedChar != Terminator)
        {
            *(buff++) = recivedChar;
        }
    }
    *buff = 0;
}