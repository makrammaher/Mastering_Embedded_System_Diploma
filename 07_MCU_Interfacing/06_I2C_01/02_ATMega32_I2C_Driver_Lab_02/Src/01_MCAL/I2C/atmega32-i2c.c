/*
 *           File: atmega32-i2c.c
 *     Created on: Wednesday 06/07/2022 01:12
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 I2C Driver
 *
 *
 */

#include "atmega32-i2c.h"

void (*volatile GP_I2C_IRQ_CallBack)(void);

#define I2C_TWINT() ((TWCR & 0x80) == 0x80)
#define I2C_CLEAR_TWINT() (TWCR |= (1 << 7))

/**
 * @brief Initialize I2C
 *
 * @param Config : Pointer to structure that hold the configuration of I2C
 */
void I2C_Init(I2C_Config_t *Config)
{
    GP_I2C_IRQ_CallBack = Config->P_IRQ_Callback;

    TWAR = Config->My_Address << 1;
    TWSR &= 0xF8;
    TWSR |= Config->SCL_Prescaler;

    uint8_t prescaler;
    switch (Config->SCL_Prescaler)
    {
    case I2C_PRESCALER_1:
        prescaler = 1;
        break;
    case I2C_PRESCALER_4:
        prescaler = 4;
        break;
    case I2C_PRESCALER_16:
        prescaler = 16;
        break;
    case I2C_PRESCALER_64:
        prescaler = 64;
        break;
    default:
        break;
    }

    TWBR = (uint8_t)(((F_CPU / Config->SCL_Frequency) - 16) / (2 * prescaler));

    TWCR = 0;
    TWCR |= Config->Interrupt_Enable;
    TWCR |= Config->ACK_Enable;
    TWCR |= (1 << 2);

    if (Config->Interrupt_Enable == I2C_INTERRUPT_ENABLE)
    {
        /* Enable Global Interrupts Mask */
        SETBIT(SREG, 7);
    }
}

/**
 * @brief Get TWINT Flag Status
 *
 * @return uint8_t : TWINT Flag True or False
 */
uint8_t I2C_Get_TWINT_Flag(void)
{
    /* Return 1 or 0 */
    return I2C_TWINT();
}

/**
 * @brief Clear the TWINT to Start Transmitting
 *
 */
void I2C_Clear_TWINT_Flag(void)
{
    /* Clear by writing one on it */
    I2C_CLEAR_TWINT();
}

/**
 * @brief Enable Acknowledge
 *
 */
void I2C_Enable_ACK(void)
{
    TWCR = (TWCR | (1 << 6)) & 0x7F;
}

/**
 * @brief Disable or Not Acknowledge
 *
 */
void I2C_Disable_ACK(void)
{
    TWCR = (TWCR & (~(1 << 6))) & 0x7F;
}

/**
 * @brief Get I2C Status From TWSR masked
 *
 * @return uint8_t : I2C Status
 */
uint8_t I2C_Get_Status(void)
{
    /* Return I2C Status after masking */
    return (TWSR & 0xF8);
}

/**
 * @brief Master Send Start Condition on I2C
 *
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 */
void I2C_Send_Start_Condition(uint8_t Polling_Enable)
{
    /* Set start condition bit TWSTA */
    TWCR &= 0x4F;
    TWCR |= (1 << 5);
    /* Clear TWINT Flag */
    I2C_CLEAR_TWINT();
    /* Polling on the flag if you need */
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        while (!I2C_TWINT())
            ;
    }
}

/**
 * @brief Master Send Stop Condition on I2C
 *
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 */
void I2C_Send_Stop_Condition(uint8_t Polling_Enable)
{
    /* Set start condition bit TWSTO */
    TWCR &= 0x4F;
    TWCR |= (1 << 4);
    /* Clear TWINT Flag */
    I2C_CLEAR_TWINT();
    /* Polling on the flag if you need */
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        while (!I2C_TWINT())
            ;
    }
}

/**
 * @brief Master Transmitt Slave address and read or write
 *
 * @param Slave_Address : Address of the Slave
 * @param R_W : Specifies the Transmition condition even read or write
 *              Must be set by @ref I2C_SLA_define
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 */
void I2C_Send_Slave_Address(uint8_t Slave_Address_7Bits, uint8_t R_W, uint8_t Polling_Enable)
{
    TWDR = (Slave_Address_7Bits << 1) + R_W;
    TWCR &= 0x4F;
    I2C_CLEAR_TWINT();
    /* Polling on the flag if you need */
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        while (!I2C_TWINT())
            ;
    }
}

/**
 * @brief Transmitt Data
 *
 * @param Data : Data to be transmit
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 */
void I2C_Send_Data(uint8_t Data, uint8_t Polling_Enable)
{
    TWDR = Data;
    TWCR &= 0x4F;
    I2C_CLEAR_TWINT();
    /* Polling on the flag if you need */
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        while (!I2C_TWINT())
            ;
    }
}

/**
 * @brief Receive Data
 *
 * @param Polling_Enable : Specifies the Polling Enable
 *                         Must be set by @ref I2C_SLA_define
 * @return uint8_t Received data
 */
uint8_t I2C_Receive_Data(uint8_t Polling_Enable)
{
    uint8_t data;
    TWCR &= 0x4F;
    I2C_CLEAR_TWINT();
    /* Polling on the flag if you need */
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        while (!I2C_TWINT())
            ;
    }
    data = TWDR;
    return data;
}

/* I2C I2C_vect */
void __vector_19(void) __attribute__((signal, used, externally_visible));

void __vector_19(void)
{
    GP_I2C_IRQ_CallBack();
}
