/*
 *           File: atmega32-spi.h
 *     Created on: Sunday 26/06/2022 20:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 SPI Driver
 *
 *
 */

#ifndef _ATMEGA32_SPI_H_
#define _ATMEGA32_SPI_H_

#include "atmega32.h"
#include "atmega32-gpio.h"

#define SPI_GPIO        GPIOB
#define SPI_SS_PIN      GPIO_PIN_4
#define SPI_MOSI_PIN    GPIO_PIN_5
#define SPI_MISO_PIN    GPIO_PIN_6
#define SPI_SCK_PIN     GPIO_PIN_7

typedef struct
{
    uint8_t Mode;   /* Specifies the Mode of SPI */
                    /* Must be set by @ref SPI_MODE_define */

    uint8_t DataOrder;  /* Specifies the Data order of SPI */
                        /* Must be set by @ref SPI_DATA_define */

    uint8_t ClockRate;  /* Specifies the Clock rate of SPI */
                        /* Must be set by @ref SPI_CLOCK_define */

    uint8_t Interrupt_Enable;   /* Specifies the Interrupt Enable of SPI */
                                /* Must be set by @ref SPI_INTERRUPT_define */

    void (*P_IRQ_Callback)();   /* Poiter to function callback Which will be called once the IRQ Happend */
} SPI_Config;


/** @defgroup SPI_MODE_define
 *  @brief SPI MODE Define
 * @{
 */
#define SPI_MODE_MASTER         (uint8_t)0x10
#define SPI_MODE_SLAVE          (uint8_t)0x00
/**
 * @}
 */


/** @defgroup SPI_DATA_define
 *  @brief SPI DATA Define
 * @{
 */
#define SPI_DATA_LSB_FIRST      (uint8_t)0x20
#define SPI_DATA_MSB_FIRST      (uint8_t)0x00
/**
 * @}
 */


/** @defgroup SPI_CLOCK_define
 *  @brief SPI clock rate Define
 * @{
 */
#define SPI_CLOCK_F_DIV_4       (uint8_t)0x00
#define SPI_CLOCK_F_DIV_16      (uint8_t)0x01
#define SPI_CLOCK_F_DIV_64      (uint8_t)0x02
#define SPI_CLOCK_F_DIV_128     (uint8_t)0x03
#define SPI_CLOCK_F_DIV_2       (uint8_t)0x04
#define SPI_CLOCK_F_DIV_8       (uint8_t)0x05
#define SPI_CLOCK_F_DIV_32      (uint8_t)0x06
/**
 * @}
 */


/** @defgroup SPI_INTERRUPT_define
 *  @brief SPI Interrupt Define
 * @{
 */
#define SPI_INTERRUPT_ENABLE    (uint8_t)0x80
#define SPI_INTERRUPT_DISABLE   (uint8_t)0x00
/**
 * @}
 */


/** @defgroup SPI_POLLING_define
 *  @brief SPI Polling Define
 * @{
 */

#define SPI_POLLING_ENABLE      1
#define SPI_POLLING_DISABLE     0

/**
 * @}
 */


/**
 * @brief Initialize SPI
 * 
 * @param Config is a poiner to SPI_Config structure that hold the configuration of the SPI
 */
void SPI_Init(SPI_Config* Config);


/**
 * @brief Transmite and recdive From SPI
 * 
 * @param Data : data to be transmitted
 * @return uint8_t : Received data
 */
uint8_t SPI_Transmit_Receive_Polling(uint8_t Data);


/**
 * @brief Transmit Data To SPI
 * 
 * @param Data : Data to be transmitted
 * @param Polling_Enable :  Specifies the Polling Enable
 *                          Must be set by @ref SPI_POLLING_define
 */
void SPI_Transmit(uint8_t Data, uint8_t Polling_Enable);


/**
 * @brief 
 * 
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref SPI_POLLING_define
 * @return uint8_t : Received Data
 */
uint8_t SPI_Receive(uint8_t Polling_Enable);


/**
 * @brief get the SPIF Flag Status
 * 
 * @return uint8_t : Flag status
 */
uint8_t SPI_Get_SPIF(void);




#endif