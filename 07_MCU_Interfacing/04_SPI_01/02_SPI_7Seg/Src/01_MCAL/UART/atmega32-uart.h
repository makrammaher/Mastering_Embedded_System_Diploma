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

#define USART_TX_BUFFER_SIZE        64  /* Size of transmitter buffer   MAX = 255 */
#define USART_RX_BUFFER_SIZE        64  /* Size of reciver buffer       MAX = 255 */


typedef struct
{
    uint8_t Mode;
    uint8_t Data;
    uint8_t Parity;
    uint8_t Stop;
    uint8_t Interrupt;
    uint16_t UBRR_Value;
    uint8_t Speed_Mode;
    char String_Terminator;
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

#define USART_INTERRUPT_ENABLE                  0b10000000
#define USART_INTERRUPT_DISABLE                 0b00000000

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
 * @brief Flush Transmitter Buffer
 * 
 */
void USART_Flush_TX_Buf(void);

/**
 * @brief Flush Reciver Buffer
 * 
 */
void USART_Flush_RX_Buf(void);

/**
 * @brief get number or recived bytes in rx buffer
 * 
 * @return uint8_t Number of bytes available in rx buffer
 */
uint8_t USART_Available_Bytes(void);

/**
 * @brief this is asychnronous function to send one byte using tx buffer
 * 
 * @param Byte byte to be sent
 */
void USART_SendByte(uint8_t Byte);

/**
 * @brief this is asychnronous function to send number of bytes using tx buffer
 * 
 * @param Buffer pointer to buffer that holds bytes to be send
 * @param size size of the buffer that will be send
 */
void USART_SendBytes(uint8_t* Buffer, uint8_t size);

/**
 * @brief this is asychnronous function to send string using tx buffer
 * 
 * @param Str : pointer to the first char of string
 * @param size : Maximum size of str
 */
void USART_SendString(const char* Str, uint8_t size);

/**
 * @brief this is asychnronous function to get one byte using rx buffer
 * 
 * @param Byte byte to be sent
 */
uint8_t USART_GetByte(void);

/**
 * @brief this is asychnronous function to get number of bytes using rx buffer
 * 
 * @param Buffer pointer to buffer that holds bytes to be send
 * @param size size of the buffer that will be send
 */
void USART_GetBytes(uint8_t* Buffer, uint8_t size);

/**
 * @brief this is asychnronous function to get string using rx buffer
 * 
 * @param Str : pointer to the first char of string
 * @param size : Maximum size of str
 * @param terminator : Terminator character
 */
void USART_GetString(char* Str, uint8_t size);

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


#endif