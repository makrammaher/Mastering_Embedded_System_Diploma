/*
 *           File: stm32f103c6-spi.h
 *     Created on: Wednesday 29/06/2022 02:38
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 SPI Driver
 *
 *
 */

#ifndef _STM32F103C6_SPI_H_
#define _STM32F103C6_SPI_H_

#include "stm32f103c6.h"

typedef struct
{
    uint8_t Mode;   /* Specifies the Mode of SPI */
                    /* Must be set by @ref SPI_MODE_define */
    
    uint16_t Direction_Mode;    /* Specifies the Data Direction mode of SPI */
                                /* Must be set by @ref SPI_DIRECTION_define */

    uint16_t Frame_Formate; /* Specifies the Frame Formate of SPI */
                            /* Must be set by @ref SPI_FRAME_define */

    uint8_t CLK_Polarity_Phase; /* Specifies the CLK Polarity and Phase of SPI */
                                /* Must be set by @ref SPI_CLK_define */
    
    uint8_t CLK_Prescaler;      /* Specifies the CLK Prescaler of SPI */
                                /* Must be set by @ref SPI_PRESCALER_define */

    uint16_t NSS;   /* Specifies the NSS Configration of SPI */
                    /* Must be set by @ref SPI_NSS_define */

    uint8_t Interrupt_Enable;   /* Specifies the interrupt enable of SPI */
                                /* Must be set by @ref SPI_INTERRUPT_define */

    void(*P_IRQ_Callback)(void);    /* Poiter to function callback Which will be called once the IRQ Happend */

}SPI_Config_t;


/** @defgroup SPI_MODE_define
 *  @brief SPI Mode Define
 * @{
 */
#define SPI_MODE_MASTER     0x0004
#define SPI_MODE_SLAVE      0x0000

/**
 * @}
 */

/** @defgroup SPI_DIRECTION_define
 *  @brief SPI Direction Define
 * @{
 */
#define SPI_DIRECTION_2LINES            0x0000
#define SPI_DIRECTION_2LINES_RX_ONLY    0x0400
#define SPI_DIRECTION_1LINE_TX_ONLY     0xC000
#define SPI_DIRECTION_1LINE_RX_ONLY     0x8000

/**
 * @}
 */



/** @defgroup SPI_FRAME_define
 *  @brief Frame formate Define
 * @{
 */
#define SPI_FRAME_8BIT_LSBF     0x0080
#define SPI_FRAME_8BIT_MSBF     0x0000
#define SPI_FRAME_16BIT_LSBF    0x0880
#define SPI_FRAME16_BIT_MSBF    0x0800

/**
 * @}
 */

/** @defgroup SPI_CLK_define
 *  @brief SPI CLK Polatiry Phase Define
 * @{
 */
#define SPI_CLK_LOW_IDLE_FIRST_EDGE_DATA_CAPTURE    0x00
#define SPI_CLK_LOW_IDLE_SECOND_EDGE_DATA_CAPTURE   0x01
#define SPI_CLK_HIGH_IDLE_FIRST_EDGE_DATA_CAPTURE   0x02
#define SPI_CLK_HIGH_IDLE_SECOND_EDGE_DATA_CAPTURE  0x03

/**
 * @}
 */

/** @defgroup SPI_PRESCALER_define
 *  @brief SPI PRESCALER Define
 * @{
 */
#define SPI_PRESCALER_DIV_2     0x00
#define SPI_PRESCALER_DIV_4     0x08
#define SPI_PRESCALER_DIV_8     0x10
#define SPI_PRESCALER_DIV_16    0x18
#define SPI_PRESCALER_DIV_32    0x20
#define SPI_PRESCALER_DIV_64    0x28
#define SPI_PRESCALER_DIV_128   0x30
#define SPI_PRESCALER_DIV_256   0x38

/**
 * @}
 */

/** @defgroup SPI_NSS_define
 *  @brief SPI NSS Define
 * @{
 */
#define SPI_NSS_SOFTWARE_SET            0x0300
#define SPI_NSS_SOFTWARE_RESET          0x0200
#define SPI_NSS_HARDWARE_MULTIMASTER    0x0000
#define SPI_NSS_HARDWARE_MASTER         0x0004

/**
 * @}
 */


/** @defgroup SPI_INTERRUPT_define
 *  @brief SPI Interrupt Enable Define
 * @{
 */
#define SPI_INTERRUPT_DISABLE       0x00
#define SPI_INTERRUPT_TXE_ENABLE    0x80
#define SPI_INTERRUPT_RXNE_ENABLE   0x40
#define SPI_INTERRUPT_ERR_ENABLE    0x20

/**
 * @}
 */


/** @defgroup SPI_POLLING_define
 *  @brief SPI Polling Define
 * @{
 */

#define SPI_POLLING_ENABLE    1
#define SPI_POLLING_DISABLE   0

/**
 * @}
 */


/**
 * @brief Initialize SPI
 * 
 * @param SPIx : SPI1, SPI2
 * @param Config : Pointer to structure of SPI_Config_t that hold the configration of SPI
 */
void SPI_Init(SPIx_t* SPIx, SPI_Config_t* Config);

/**
 * @brief Reset SPIx
 * 
 * @param SPIx : SPI1, SPI2
 */
void SPI_Reset(SPIx_t* SPIx);

/**
 * @brief Transmit data throw SPI
 * 
 * @param SPIx : SPI1, SPI2
 * @param Data : Data to be transmitted
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 */
void SPI_Send_Data(SPIx_t* SPIx, uint16_t Data, uint8_t Polling_Enable);

/**
 * @brief 
 * 
 * @param SPIx : SPI1, SPI2
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 * @return uint16_t : Received data
 */
uint16_t SPI_Receive_Data(SPIx_t* SPIx, uint8_t Polling_Enable);

/**
 * @brief 
 * 
 * @param SPIx : SPI1, SPI2
 * @param Data : Data to be transmitted
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 * @return uint16_t  : Received data
 */
uint16_t SPI_Send_Receive_Data(SPIx_t* SPIx, uint16_t Data, uint8_t Polling_Enable);



#endif