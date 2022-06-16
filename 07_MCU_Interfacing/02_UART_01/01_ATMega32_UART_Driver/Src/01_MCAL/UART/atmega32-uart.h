/*
 *           File: atmega32-uart.h
 *     Created on: Sunday 12/06/2022 20:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 UART Driver
 *
 *
 */

#ifndef _ATMEGA32_UART_H_
#define _ATMEGA32_UART_H_

#include "atmega32.h"

typedef struct
{
    uint8_t Mode;
    uint8_t Data;
    uint8_t Parity;
    uint8_t Stop;
    uint16_t UBRR_Value;
    uint8_t Speed_Mode;
}USART_Config_t;


#define USART_MODE_ASYNC_RECEIVER_TRANSMITTER   0b011000
#define USART_MODE_ASYNC_TRANSMITTER            0b001000
#define USART_MODE_ASYNC_RECEIVER               0b010000
#define USART_MODE_SYNC_RECEIVER_TRANSMITTER    0b111000
#define USART_MODE_SYNC_TRANSMITTER             0b101000
#define USART_MODE_SYNC_RECEIVER                0b110000

#define USART_DATA_5_BIT                        0b0000
#define USART_DATA_6_BIT                        0b0010
#define USART_DATA_7_BIT                        0b0100
#define USART_DATA_8_BIT                        0b0110
#define USART_DATA_9_BIT                        0b1110

#define USART_PARITY_DISABLE                    0b000000
#define USART_PARITY_EVEN                       0b100000
#define USART_PARITY_ODD                        0b110000

#define USART_STOP_1_BIT                        0b0000
#define USART_STOP_2_BIT                        0b1000

#define USART_UBRR_VALUE_8MHZ_2400              207
#define USART_UBRR_VALUE_8MHZ_4800              103
#define USART_UBRR_VALUE_8MHZ_9600              51

#define USART_NORMAL_SPEED_MODE                 0b00
#define USART_DOUBLE_SPEED_MODE                 0b10



/**
 * @brief 
 * 
 * @param Config : is a poiner to USART_Config structure that hold the configuration of the USART
 */
void USART_Init(USART_Config_t* Config);

/**
 * @brief 
 * 
 * @param Data : the data to be tansmitted
 */
void USART_Transmit(uint16_t Data);

/**
 * @brief 
 * 
 * @return uint16_t : the recived data
 */
uint16_t USART_Recive(void);

/**
 * @brief 
 * 
 * @param str : Pointer to string 
 */
void USART_SendString(char* str);

/**
 * @brief 
 * 
 * @param buff : Buffer to hold the recived string
 * @param Terminator : Terminator Character
 */
void USART_ReadString(char* buff, char Terminator);




#endif