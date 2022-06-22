/*
 *           File: stm32f103c6-usart.h
 *     Created on: Monday 20/06/2022 02:38
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 USART Driver
 *
 *
 */

#ifndef _STM32F103C6_USART_H_
#define _STM32F103C6_USART_H_

#include "stm32f103c6.h"

typedef struct
{
    uint8_t Mode; /* Specifies the Mode of USART */
                  /* Must be set by @ref USART_MODE_define */

    uint16_t Data_Width; /* Specifies the data width of USART */
                         /* Must be set by @ref USART_DATA_WIDTH_define */

    uint16_t Parity; /* Specifies the data width of USART */
                     /* Must be set by @ref USART_PARITY_define */

    uint16_t Stop_Bits; /* Specifies the stop bits of USART */
                        /* Must be set by @ref USART_STOP_BITS_define */

    uint32_t Baudrate;  /* Specifies the Baudrate of USART */

    uint8_t Interrupt_Enable;   /* Specifies the interrupt enable of USART */
                                /* Must be set by @ref USART_INTERRUPT_define */
    
    void(*P_IRQ_Callback)(void);    /* Poiter to function callback Which will be called once the IRQ Happend */

} USART_Config_t;


/** @defgroup USART_MODE_define
 *  @brief USART MODE Define
 * @{
 */

#define USART_MODE_TX       0b1000
#define USART_MODE_RX       0b0100
#define USART_MODE_TX_RX    0b1100

/**
 * @}
 */

/** @defgroup USART_DATA_WIDTH_define
 *  @brief USART DATA WIDTH Define
 * @{
 */

#define USART_DATA_WIDTH_8_BITS 0x0000
#define USART_DATA_WIDTH_9_BITS 0x1000

/**
 * @}
 */

/** @defgroup USART_PARITY_define
 *  @brief USART PARITY Define
 * @{
 */

#define USART_PARITY_NONE   0x0000
#define USART_PARITY_EVEN   0x0400
#define USART_PARITY_ODD    0x0600

/**
 * @}
 */

/** @defgroup USART_STOP_BITS_define
 *  @brief USART STOP Define
 * @{
 */

#define USART_STOP_BITS__half       0x1000
#define USART_STOP_BITS__1          0x0000
#define USART_STOP_BITS__1_half     0x3000
#define USART_STOP_BITS__2          0x2000

/**
 * @}
 */


/** @defgroup USART_INTERRUPT_define
 *  @brief USART INTERRUPT Define
 * @{
 */

#define USART_INTERRUPT_DISABLED    0x00
#define USART_INTERRUPT_TXE         0x80
#define USART_INTERRUPT_RXNE        0x20
#define USART_INTERRUPT_TXE_RXNE    0xA0

/**
 * @}
 */


/** @defgroup USART_POLLING_define
 *  @brief USART Polling Define
 * @{
 */

#define USART_POLLING_ENABLE    1
#define USART_POLLING_DISABLE   0

/**
 * @}
 */


/**
 * @brief Initialaize the USARTx
 * 
 * @param USARTx : USART1, UASRT2, UASRT3
 * @param USART_Config : Pointer to structure of USART_Config_t that hold the configration of USART
 */
void USART_Init(USARTx_t* USARTx, USART_Config_t* USART_Config);

/**
 * @brief Reset USARTx
 * 
 * @param USARTx : USART1, UASRT2, UASRT3
 */
void USART_Reset(USARTx_t* USARTx);


/**
 * @brief Transmit data using USART
 * 
 * @param USARTx : USART1, UASRT2, UASRT3
 * @param Data : the data to be send
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 */
void USART_Send_Data(USARTx_t* USARTx, uint16_t Data, uint8_t Polling_Enable);


/**
 * @brief Receive Data using USART
 * 
 * @param USARTx : USART1, UASRT2, UASRT3
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 * @return uint16_t : the received data
 */
uint16_t USART_Receive_Data(USARTx_t* USARTx, uint8_t Polling_Enable);

#endif