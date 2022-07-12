/*
 *           File: stm32f103c6-spi.c
 *     Created on: Wednesday 29/06/2022 02:38
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 SPI Driver
 *
 *
 */

#include "stm32f103c6-spi.h"
#include "stm32f103c6-gpio.h"

void (*GP_SPI_IRQ_CallBack[2])(void);

void SPI_GPIO_Init(SPIx_t *SPIx, SPI_Config_t *Config)
{
    GPIOx_t *SPI_GPIOx;
    uint16_t SPI_MOSI_PIN;
    uint16_t SPI_MISO_PIN;
    uint16_t SPI_SCK_PIN;
    uint16_t SPI_NSS_PIN;

    if (SPIx == SPI1)
    {
        /* GPIOA */
        /* Enable CLK to GPIOx */
        SPI_GPIOx = GPIOA;
        RCC_GPIOA_CLK_EN();

        SPI_MOSI_PIN = GPIO_PIN_7;
        SPI_MISO_PIN = GPIO_PIN_6;
        SPI_SCK_PIN = GPIO_PIN_5;
        SPI_NSS_PIN = GPIO_PIN_4;
    }
    else if (SPIx == SPI2)
    {
        /* GPIOA */
        /* Enable CLK to GPIOx */
        SPI_GPIOx = GPIOB;
        RCC_GPIOA_CLK_EN();

        SPI_MOSI_PIN = GPIO_PIN_15;
        SPI_MISO_PIN = GPIO_PIN_14;
        SPI_SCK_PIN = GPIO_PIN_13;
        SPI_NSS_PIN = GPIO_PIN_12;
    }

    if (Config->Mode == SPI_MODE_MASTER)
    {
        /* Master */
        GPIO_Init(SPI_GPIOx, GPIO_MODE_AF_PP_2MHZ, SPI_SCK_PIN);
        GPIO_Init(SPI_GPIOx, GPIO_MODE_AF_PP_2MHZ, SPI_MOSI_PIN);
        if (Config->Direction_Mode == SPI_DIRECTION_2LINES)
        {
            GPIO_Init(SPI_GPIOx, GPIO_MODE_INPUT_F, SPI_MISO_PIN);
        }
    }
    else
    {
        /* Slave */
        GPIO_Init(SPI_GPIOx, GPIO_MODE_INPUT_F, SPI_SCK_PIN);
        GPIO_Init(SPI_GPIOx, GPIO_MODE_AF_PP_2MHZ, SPI_MISO_PIN);
        if (Config->Direction_Mode == SPI_DIRECTION_2LINES)
        {
            GPIO_Init(SPI_GPIOx, GPIO_MODE_INPUT_F, SPI_MOSI_PIN);
        }
    }
    switch (Config->NSS)
    {
    case SPI_NSS_HARDWARE_MASTER:
        /* Full Duplex */
        GPIO_Init(SPI_GPIOx, GPIO_MODE_AF_PP_2MHZ, SPI_NSS_PIN);
        break;
    case SPI_NSS_HARDWARE_MULTIMASTER:
        GPIO_Init(SPI_GPIOx, GPIO_MODE_INPUT_F, SPI_NSS_PIN);
        break;
    default:
        break;
    }
}

/**
 * @brief Initialize SPI
 *
 * @param SPIx : SPI1, SPI2
 * @param Config : Pointer to structure of SPI_Config_t that hold the configration of SPI
 */
void SPI_Init(SPIx_t *SPIx, SPI_Config_t *Config)
{
    /* Initialize GPIO */
    SPI_GPIO_Init(SPIx, Config);

    if (SPIx == SPI1)
    {
        GP_SPI_IRQ_CallBack[0] = Config->P_IRQ_Callback;
        /* Enable Clock to SPI */
        RCC_SPI1_CLK_EN();
    }
    else if (SPIx == SPI2)
    {
        GP_SPI_IRQ_CallBack[1] = Config->P_IRQ_Callback;
        /* Enable Clock to SPI */
        RCC_SPI2_CLK_EN();
    }

    uint16_t Temp_CR1 = 0;
    Temp_CR1 |= Config->Mode;
    Temp_CR1 |= Config->Direction_Mode;
    Temp_CR1 |= Config->Frame_Formate;
    Temp_CR1 |= Config->CLK_Polarity_Phase;
    Temp_CR1 |= Config->CLK_Prescaler;
    Temp_CR1 |= (Config->NSS & 0x0F00);
    /* Enable SPI */
    Temp_CR1 |= (1 << 6);

    uint16_t Temp_CR2 = 0;
    Temp_CR2 |= Config->Interrupt_Enable;
    Temp_CR2 |= (Config->NSS & 0x000F);

    if (Config->Interrupt_Enable != SPI_INTERRUPT_DISABLE)
    {
        if (SPIx == SPI1)
        {
            NVIC_IRQ35_SPI1_EN();
        }
        else if (SPIx == SPI2)
        {
            NVIC_IRQ36_SPI2_EN();
        }
    }
    SPIx->CR1 = Temp_CR1;
    SPIx->CR2 = Temp_CR2;
}

/**
 * @brief Reset SPIx
 *
 * @param SPIx : SPI1, SPI2
 */
void SPI_Reset(SPIx_t *SPIx)
{
    if (SPIx == SPI1)
    {
        NVIC_IRQ35_SPI1_DIS();
        RCC_SPI1_RST();
    }
    else if (SPIx == SPI2)
    {
        NVIC_IRQ36_SPI2_DIS();
        RCC_SPI2_RST();
    }
}

/**
 * @brief Transmit data throw SPI
 *
 * @param SPIx : SPI1, SPI2
 * @param Data : Data to be transmitted
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 */
void SPI_Send_Data(SPIx_t *SPIx, uint16_t Data, uint8_t Polling_Enable)
{
    if (Polling_Enable == SPI_POLLING_ENABLE)
    {
        while (!(SPIx->SR & (1 << 1)))
            ;
    }

    SPIx->DR = Data;
}

/**
 * @brief
 *
 * @param SPIx : SPI1, SPI2
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 * @return uint16_t : Received data
 */
uint16_t SPI_Receive_Data(SPIx_t *SPIx, uint8_t Polling_Enable)
{
    if (Polling_Enable == SPI_POLLING_ENABLE)
    {
        while (!(SPIx->SR & (1 << 0)))
            ;
    }
    return SPIx->DR;
}

/**
 * @brief
 *
 * @param SPIx : SPI1, SPI2
 * @param Data : Data to be transmitted
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 * @return uint16_t  : Received data
 */
uint16_t SPI_Send_Receive_Data(SPIx_t *SPIx, uint16_t Data, uint8_t Polling_Enable)
{
    if (Polling_Enable == SPI_POLLING_ENABLE)
    {
        while (!(SPIx->SR & (1 << 1)))
            ;
    }
    SPIx->DR = Data;
    
    if (Polling_Enable == SPI_POLLING_ENABLE)
    {
        while (!(SPIx->SR & (1 << 0)))
            ;
    }
    return SPIx->DR;
}

void SPI1_handler(void)
{
    GP_SPI_IRQ_CallBack[0]();
}

void SPI2_handler(void)
{
    GP_SPI_IRQ_CallBack[1]();
}