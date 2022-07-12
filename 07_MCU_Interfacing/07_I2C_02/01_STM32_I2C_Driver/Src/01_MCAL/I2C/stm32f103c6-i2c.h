/*
 *           File: stm32f103c6-i2c.h
 *     Created on: Saturday 09/07/2022 02:38
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 I2C Driver
 *
 *
 */

#ifndef _STM32F103C6_I2C_H_
#define _STM32F103C6_I2C_H_

#include "stm32f103c6.h"

typedef struct
{
    uint8_t Address;        /* Specifies the Address of I2C */
                            
    uint16_t Frequency_Mode;    /* Specifies the Frequency mode of I2C */
                                /* Must be set by @ref I2C_FREQUNCY_MODE_define */
    
    uint32_t Frequency;     /* Specifies the Frequency of I2C */
    
    uint8_t Stretch;    /* Specifies the Strech Enable of I2C */
                        /* Must be set by @ref I2C_STRETCH_define */

    uint8_t GeneralCall;    /* Specifies the General Call Enable of I2C */
                            /* Must be set by @ref I2C_GENERAL_CALL_define */

    uint16_t Acknowledge;   /* Specifies the Acknowledge Enable of I2C */
                            /* Must be set by @ref I2C_ACKNOWLEDGE_define */

    uint16_t Interrupt_Enable; /* Specifies the interrupt enable of I2C */
                               /* Must be set by @ref I2C_INTERRUPT_define */

    void (*P_IRQ_Callback)(uint16_t ER_EV, uint32_t Status); /* Poiter to function callback Which will be called once the IRQ Happend */
} I2C_Config_t;





/** @defgroup I2C_FREQUNCY_MODE_define
 *  @brief I2C Frequency mode Define
 * @{
 */
#define I2C_FREQUNCY_MODE_STANDERD  0x0000
#define I2C_FREQUNCY_MODE_FAST      0x8000
/**
 * @}
 */

/** @defgroup I2C_STRETCH_define
 *  @brief I2C Stretch enable Define
 * @{
 */
#define I2C_STRETCH_ENABLE      0x00
#define I2C_STRETCH_DISABLE     0x80
/**
 * @}
 */

/** @defgroup I2C_GENERAL_CALL_define
 *  @brief I2C General Call Enable Define
 * @{
 */
#define I2C_GENERAL_CALL_ENABLE     0x40
#define I2C_GENERAL_CALL_DISABLE    0x00
/**
 * @}
 */

/** @defgroup I2C_ACKNOWLEDGE_define
 *  @brief  Define
 * @{
 */
#define I2C_ACKNOWLEDGE_ENABLE      0x0400
#define I2C_ACKNOWLEDGE_DISABLE     0x0000
/**
 * @}
 */

/** @defgroup I2C_INTERRUPT_define
 *  @brief I2C Interrupt Define
 * @{
 */
#define I2C_INTERRUPT_DISABLE       0x0000
#define I2C_INTERRUPT_EVENT         0x0200
#define I2C_INTERRUPT_ERROR         0x0100
#define I2C_INTERRUPT_EVENT_ERROR   0x0300
/**
 * @}
 */

/** @defgroup I2C_POLLING_define
 *  @brief I2C Polling Define
 * @{
 */

#define I2C_POLLING_ENABLE    1
#define I2C_POLLING_DISABLE   0

/**
 * @}
 */

/** @defgroup I2C_DIRECTION_define
 *  @brief I2C Direction Define
 * @{
 */

#define I2C_DIRECTION_READ    1
#define I2C_DIRECTION_WRITE   0

/**
 * @}
 */

/**
 * @brief Initialize I2C
 * 
 * @param I2Cx : I2C1, I2C2
 * @param Config : Pointer to structure of SPI_Config_t that hold the configration of I2C
 */
void I2C_Init(I2Cx_t *I2Cx, I2C_Config_t *Config);

/**
 * @brief Reset I2C
 * 
 * @param I2Cx : I2C1, I2C2
 */
void I2C_Reset(I2Cx_t *I2Cx);

/**
 * @brief Send Start Condition
 * 
 * @param I2Cx : I2C1, I2C2
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref I2C_POLLING_define
 */
void I2C_Send_Start_Condition(I2Cx_t *I2Cx, uint8_t Polling_Enable);

/**
 * @brief Send Stop Condition
 * 
 * @param I2Cx : I2C1, I2C2
 */
void I2C_Send_Stop_Condition(I2Cx_t *I2Cx);


/**
 * @brief Get Status of I2C
 * 
 * @param I2Cx : I2C1, I2C2
 * @return I2C_Status : Status
 */
uint32_t I2C_Get_Status(I2Cx_t *I2Cx);


/**
 * @brief Set Acknowledge State
 * 
 * @param I2Cx : I2C1, I2C2
 * @param Ack : Specifies the Acknowledge Enable of I2C
 *              Must be set by @ref I2C_ACKNOWLEDGE_define
 */
void I2C_Set_Acknowledge(I2Cx_t *I2Cx, uint16_t Ack);

/**
 * @brief Send Address followed by Drirection Read or Write
 * 
 * @param I2Cx : I2C1, I2C2
 * @param Address: Address to be send
 * @param Direction : Specifies the Direction of I2C
 *                    Must be set by @ref I2C_DIRECTION_define
 * @param Polling_Enable : Specifies the Polling enable of I2C
 *                         Must be set by @ref I2C_POLLING_define
 */
void I2C_Send_Address(I2Cx_t *I2Cx, uint8_t Address, uint8_t Direction, uint8_t Polling_Enable);

/**
 * @brief Send Data
 * 
 * @param I2Cx : I2C1, I2C2
 * @param Data : the data to be send
 * @param Polling_Enable : Specifies the Polling enable of I2C
 *                         Must be set by @ref I2C_POLLING_define
 */
void I2C_Send_Data(I2Cx_t *I2Cx, uint8_t Data, uint8_t Polling_Enable);

/**
 * @brief Receive Data
 * 
 * @param I2Cx : I2C1, I2C2
 * @param Polling_Enable : Specifies the Polling enable of I2C
 *                         Must be set by @ref I2C_POLLING_define
 * @return uint8_t : Received Data
 */
uint8_t I2C_Receive_Data(I2Cx_t *I2Cx, uint8_t Polling_Enable);

#endif