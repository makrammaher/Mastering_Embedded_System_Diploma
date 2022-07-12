/*
 *           File: stm32f103c6-i2c.h
 *     Created on: Saturday 09/07/2022 02:38
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 I2C Driver
 *
 *
 */

#include "stm32f103c6-i2c.h"
#include "stm32f103c6-gpio.h"
#include "stm32f103c6-rcc.h"

void (*GP_I2C_IRQ_CallBack[2])(uint16_t ER_EV, uint32_t Status);

void I2C1_EV_handler(void)
{
    GP_I2C_IRQ_CallBack[0](I2C_INTERRUPT_EVENT, I2C_Get_Status(I2C1));
}
void I2C1_ER_handler(void)
{
    GP_I2C_IRQ_CallBack[0](I2C_INTERRUPT_ERROR, I2C_Get_Status(I2C1));
}
void I2C2_EV_handler(void)
{
    GP_I2C_IRQ_CallBack[1](I2C_INTERRUPT_EVENT, I2C_Get_Status(I2C2));
}
void I2C2_ER_handler(void)
{
    GP_I2C_IRQ_CallBack[1](I2C_INTERRUPT_ERROR, I2C_Get_Status(I2C2));
}

void I2C_GPIO_Init(I2Cx_t *I2Cx)
{
    /* Enable Clock for GPIO */
    RCC_GPIOB_CLK_EN();
    if (I2Cx == I2C1)
    {
        /* GPIOB */
        /* SDA = 7 , SCL = 6 */
        GPIO_Init(GPIOB, GPIO_MODE_AF_OD_2MHZ, GPIO_PIN_7);
        GPIO_Init(GPIOB, GPIO_MODE_AF_OD_2MHZ, GPIO_PIN_6);
    }
    else if (I2Cx == I2C2)
    {
        /* GPIOB */
        /* SDA = 11 , SCL = 10 */
        GPIO_Init(GPIOB, GPIO_MODE_AF_OD_2MHZ, GPIO_PIN_11);
        GPIO_Init(GPIOB, GPIO_MODE_AF_OD_2MHZ, GPIO_PIN_10);
    }
}

/**
 * @brief Initialize I2C
 *
 * @param I2Cx : I2C1, I2C2
 * @param Config : Pointer to structure of SPI_Config_t that hold the configration of I2C
 */
void I2C_Init(I2Cx_t *I2Cx, I2C_Config_t *Config)
{
    /* Enable clock for I2C */
    if (I2Cx == I2C1)
    {
        GP_I2C_IRQ_CallBack[0] = Config->P_IRQ_Callback;
        RCC_I2C1_CLK_EN();
    }
    else if (I2Cx == I2C2)
    {
        GP_I2C_IRQ_CallBack[1] = Config->P_IRQ_Callback;
        RCC_I2C2_CLK_EN();
    }
    /* Initialize GPIO */
    I2C_GPIO_Init(I2Cx);
    /* Enable POS */
    I2Cx->CR1 |= (1 << 11);
    /* ACK */
    I2Cx->CR1 |= Config->Acknowledge;
    /* Stretch */
    I2Cx->CR1 |= Config->Stretch;
    /* Genreral Call */
    I2Cx->CR1 |= Config->GeneralCall;
    /* Enable Interrupt */
    I2Cx->CR2 |= Config->Interrupt_Enable;
    /* Set Freq */
    uint32_t PCLK1 = RCC_Get_PCLK1_Freq();
    I2Cx->CR2 |= (PCLK1 / 1000000);
    /* Address */
    I2Cx->OAR1 |= (Config->Address << 1);
    /* Config CCR */
    I2Cx->CCR |= Config->Frequency_Mode;
    I2Cx->CCR |= (uint16_t)(PCLK1 / (Config->Frequency << 1));
    /* Config T-Rise */
    I2Cx->TRISE |= (PCLK1 / 1000000) + 1;
    /* Enable NVIC */
    if (I2Cx == I2C1)
    {
        if (Config->Interrupt_Enable == I2C_INTERRUPT_EVENT)
        {
            NVIC_IRQ31_I2C1_EV_EN();
        }
        else if (Config->Interrupt_Enable == I2C_INTERRUPT_ERROR)
        {
            NVIC_IRQ32_I2C1_ER_EN();
        }
        else if (Config->Interrupt_Enable == I2C_INTERRUPT_EVENT_ERROR)
        {
            NVIC_IRQ31_I2C1_EV_EN();
            NVIC_IRQ32_I2C1_ER_EN();
        }
        else
        {
            NVIC_IRQ31_I2C1_EV_DIS();
            NVIC_IRQ32_I2C1_ER_DIS();
        }
    }
    else if (I2Cx == I2C2)
    {
        if (Config->Interrupt_Enable == I2C_INTERRUPT_EVENT)
        {
            NVIC_IRQ33_I2C2_EV_EN();
        }
        else if (Config->Interrupt_Enable == I2C_INTERRUPT_ERROR)
        {
            NVIC_IRQ34_I2C2_ER_EN();
        }
        else if (Config->Interrupt_Enable == I2C_INTERRUPT_EVENT_ERROR)
        {
            NVIC_IRQ33_I2C2_EV_EN();
            NVIC_IRQ34_I2C2_ER_EN();
        }
        else
        {
            NVIC_IRQ33_I2C2_EV_DIS();
            NVIC_IRQ34_I2C2_ER_DIS();
        }
    }
    /* Enable I2C */
    I2Cx->CR1 |= (1 << 0);
}

/**
 * @brief Reset I2C
 *
 * @param I2Cx : I2C1, I2C2
 */
void I2C_Reset(I2Cx_t *I2Cx)
{
    if (I2Cx == I2C1)
    {
        NVIC_IRQ31_I2C1_EV_DIS();
        NVIC_IRQ32_I2C1_ER_DIS();
        RCC_I2C1_RST();
    }
    else if (I2Cx == I2C2)
    {
        NVIC_IRQ33_I2C2_EV_DIS();
        NVIC_IRQ34_I2C2_ER_DIS();
        RCC_I2C2_RST();
    }
}

/**
 * @brief Send Start Condition
 *
 * @param I2Cx : I2C1, I2C2
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref I2C_POLLING_define
 */
void I2C_Send_Start_Condition(I2Cx_t *I2Cx, uint8_t Polling_Enable)
{
    /* Generate Start Condition */
    I2Cx->CR1 |= (1 << 8);
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        while (I2Cx->CR1 & (1 << 8))
            ;
    }
}

/**
 * @brief Send Stop Condition
 *
 * @param I2Cx : I2C1, I2C2
 * @param Polling_Enable : Specifies the Polling enable of I2C
 *                         Must be set by @ref I2C_POLLING_define
 */
void I2C_Send_Stop_Condition(I2Cx_t *I2Cx)
{
    /* Generate Stop Condition */
    I2Cx->CR1 |= (1 << 9);
}

/**
 * @brief Get Status of I2C
 *
 * @param I2Cx : I2C1, I2C2
 * @return I2C_Status : Status
 */
uint32_t I2C_Get_Status(I2Cx_t *I2Cx)
{
    uint32_t flags = 0;
    flags = I2Cx->SR1;
    flags |= (I2Cx->SR2 << 16);
    return flags;
}

/**
 * @brief Set Acknowledge State
 *
 * @param I2Cx : I2C1, I2C2
 * @param Ack : Specifies the Acknowledge Enable of I2C
 *              Must be set by @ref I2C_ACKNOWLEDGE_define
 */
void I2C_Set_Acknowledge(I2Cx_t *I2Cx, uint16_t Ack)
{
    if (Ack == I2C_ACKNOWLEDGE_ENABLE)
    {
        I2Cx->CR1 |= (1 << 10);
    }
    else if (Ack == I2C_ACKNOWLEDGE_DISABLE)
    {
        I2Cx->CR1 &= ~(1 << 10);
    }
}

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
void I2C_Send_Address(I2Cx_t *I2Cx, uint8_t Address, uint8_t Direction, uint8_t Polling_Enable)
{
    uint32_t status;
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        do
        {
            status = I2C_Get_Status(I2Cx);
        } while (!(status & (1 << 0)));
    }
    I2Cx->DR = ((Address << 1) + Direction);
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        do
        {
            status = I2C_Get_Status(I2Cx);
        } while (status & (1 << 1));
    }
}

/**
 * @brief Send Data
 *
 * @param I2Cx : I2C1, I2C2
 * @param Data : the data to be send
 * @param Polling_Enable : Specifies the Polling enable of I2C
 *                         Must be set by @ref I2C_POLLING_define
 */
void I2C_Send_Data(I2Cx_t *I2Cx, uint8_t Data, uint8_t Polling_Enable)
{
    uint32_t status;
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        do
        {
            status = I2C_Get_Status(I2Cx);
        } while (!(status & (1 << 7)));
    }
    I2Cx->DR = Data;
}

/**
 * @brief Receive Data
 * 
 * @param I2Cx : I2C1, I2C2
 * @param Polling_Enable : Specifies the Polling enable of I2C
 *                         Must be set by @ref I2C_POLLING_define
 * @return uint8_t : Received Data
 */
uint8_t I2C_Receive_Data(I2Cx_t *I2Cx, uint8_t Polling_Enable)
{
    uint32_t status;
    if (Polling_Enable == I2C_POLLING_ENABLE)
    {
        do
        {
            status = I2C_Get_Status(I2Cx);
        } while (!(status & (1 << 6)));
    }
    uint8_t data = I2Cx->DR;
    return data;
}