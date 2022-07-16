/*
 *           File: atmega32-i2c.h
 *     Created on: Wednesday 06/07/2022 01:12
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 I2C Driver
 *
 *
 */

#ifndef _ATMEGA32_I2C_H_
#define _ATMEGA32_I2C_H_

#include "atmega32.h"
#include "atmega32-gpio.h"

#define I2C_GPIO        GPIOC
#define I2C_SDA_PIN     GPIO_PIN_1
#define I2C_SCL_PIN     GPIO_PIN_0

typedef struct
{
    uint32_t SCL_Frequency;     /* Specifies the I2C SCL Frequency in HZ */

    uint8_t SCL_Prescaler;      /* Specifies the I2C Prescaler */
                                /* Must be set by @ref I2C_PRESCALER_define */
    uint8_t My_Address;         /* Specifies the Address of your MCU */

    uint8_t ACK_Enable;         /* Specifies the I2C Acknowledge Enable */
                                /* Must be set by @ref I2C_ACK_define */

    uint8_t Interrupt_Enable;   /* Specifies the Interrupt Enable of I2C */
                                /* Must be set by @ref I2C_INTERRUPT_define */

    void (*P_IRQ_Callback)();   /* Poiter to function callback Which will be called once the IRQ Happend */
}I2C_Config_t;

/** @defgroup I2C_ACK_define
 *  @brief I2C ACK Define
 * @{
 */
#define I2C_PRESCALER_1         (uint8_t)0x00
#define I2C_PRESCALER_4         (uint8_t)0x01
#define I2C_PRESCALER_16        (uint8_t)0x02
#define I2C_PRESCALER_64        (uint8_t)0x03
/**
 * @}
 */

/** @defgroup I2C_ACK_define
 *  @brief I2C ACK Define
 * @{
 */
#define I2C_ACK_ENABLE         (uint8_t)0x40
#define I2C_ACK_DISABLE        (uint8_t)0x00

/**
 * @}
 */

/** @defgroup I2C_INTERRUPT_define
 *  @brief I2C Interrupt Define
 * @{
 */
#define I2C_INTERRUPT_ENABLE         (uint8_t)0x01
#define I2C_INTERRUPT_DISABLE        (uint8_t)0x00

/**
 * @}
 */

/** @defgroup I2C_POLLING_define
 *  @brief I2C Polling Define
 * @{
 */

#define I2C_POLLING_ENABLE      1
#define I2C_POLLING_DISABLE     0

/**
 * @}
 */

/** @defgroup I2C_SLA_define
 *  @brief I2C SLA Define
 * @{
 */

#define I2C_SLA_WRITE       0
#define I2C_SLA_READ        1

/**
 * @}
 */



#define I2C_M_T_START_CONDITION_TRANSMITTED			0x08
#define I2C_M_T_REPEATED_START_TRANSMITTED			0x10
#define I2C_M_T_SLA_W_TRANSMITTED_ACK_RECEIVED		0x18
#define I2C_M_T_SLA_W_TRANSMITTED_NOT_ACK_RECEIVED	0x20
#define I2C_M_T_DATA_TRANSMITTED_ACK_RECEIVED		0x28
#define I2C_M_T_DATA_TRANSMITTED_NOT_ACK_RECEIVED	0x30
#define I2C_M_T_ARBITRATION_LOST					0x38

#define I2C_M_R_START_CONDITION_TRANSMITTED			0x08
#define I2C_M_R_REPEATED_START_TRANSMITTED			0x10
#define I2C_M_R_ARBITRATION_LOST_NOT_ACK			0x38
#define I2C_M_R_SLA_R_TRANSMITTED_ACK_RECEIVED		0x40
#define I2C_M_R_SLA_R_TRANSMITTED_NOT_ACK_RECEIVED	0x48
#define I2C_M_R_DATA_RECEIVED_ACK_RETURNED			0x50
#define I2C_M_R_DATA_RECEIVED_NOT_ACK_RETURNED		0x58

#define I2C_S_R_SLA_W_RECEIVED_ACK_RETURNED							0x60
#define I2C_S_R_ARBITRATION_LOST_SLA_W_RECEIVED_ACK_RETURNED		0x68
#define I2C_S_R_GENERAL_CALL_RECEIVED_ACK_RETURNED					0x70
#define I2C_S_R_ARBITRATION_LOST_GENERAL_CALL_RECEIVED_ACK_RETURNED	0x78
#define I2C_S_R_DATA_RECEIVED_ACK_RETURNED							0x80
#define I2C_S_R_DATA_RECEIVED_NOT_ACK_RETURNED						0x88
#define I2C_S_R_DATA_RECEIVED_GENERAL_CALL_ACK_RETURNED				0x90
#define I2C_S_R_DATA_RECEIVED_GENERAL_CALL_NOT_ACK_RETURNED			0x98
#define I2C_S_R_STOP_OR_REPEATED_START_RECEIVED						0xA0

#define I2C_S_T_SLA_R_RECEIVED_ACK_RETURNED							0xA8
#define I2C_S_T_ARBITRATION_LOST_SLA_W_RECEIVED_ACK_RETURNED		0xB0
#define I2C_S_T_DATA_TRANSMITTED_ACK_RECEVIED						0xB8
#define I2C_S_T_DATA_TRANSMITTED_NOT_ACK_RECEVIED					0xC0
#define I2C_S_T_LAST_DATA_TRANSMITTED_ACK_RECEVIED		            0xC8

#define I2C_NO_RELEVANT_STATE_INFORMATION_AVAILABLE		            0xF8
#define I2C_ILLEGAL_START_OR_STOR_CONDITION				            0x00





/**
 * @brief Initialize I2C
 * 
 * @param Config : Pointer to structure that hold the configuration of I2C
 */
void I2C_Init(I2C_Config_t *Config);

/**
 * @brief Get TWINT Flag Status
 * 
 * @return uint8_t : TWINT Flag True or False
 */
uint8_t I2C_Get_TWINT_Flag(void);

/**
 * @brief Clear the TWINT to Start Transmitting
 * 
 */
void I2C_Clear_TWINT_Flag(void);

/**
 * @brief Enable Acknowledge
 * 
 */
void I2C_Enable_ACK(void);

/**
 * @brief Disable or Not Acknowledge
 * 
 */
void I2C_Disable_ACK(void);

/**
 * @brief Get I2C Status From TWSR masked
 * 
 * @return uint8_t : I2C Status
 */
uint8_t I2C_Get_Status(void);

/**
 * @brief Master Send Start Condition on I2C
 * 
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 */
void I2C_Send_Start_Condition(uint8_t Polling_Enable);

/**
 * @brief Master Send Stop Condition on I2C
 * 
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 */
void I2C_Send_Stop_Condition(uint8_t Polling_Enable);

/**
 * @brief Master Transmitt Slave address and read or write
 * 
 * @param Slave_Address : Address of the Slave
 * @param R_W : Specifies the Transmition condition even read or write
 *              Must be set by @ref I2C_SLA_define
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 */
void I2C_Send_Slave_Address(uint8_t Slave_Address_7Bits, uint8_t R_W, uint8_t Polling_Enable);

/**
 * @brief Transmitt Data
 * 
 * @param Data : Data to be transmit
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 */
void I2C_Send_Data(uint8_t Data, uint8_t Polling_Enable);

/**
 * @brief Receive Data
 * 
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 * @return uint8_t Received data
 */
uint8_t I2C_Receive_Data(uint8_t Polling_Enable);


#endif