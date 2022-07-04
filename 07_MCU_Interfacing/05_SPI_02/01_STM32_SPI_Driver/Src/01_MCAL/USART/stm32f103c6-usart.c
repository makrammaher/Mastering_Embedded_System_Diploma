/*
 *           File: stm32f103c6-usart.c
 *     Created on: Monday 20/06/2022 02:38
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 USART Driver
 *
 *
 */

#include "stm32f103c6-usart.h"
#include "stm32f103c6-rcc.h"
#include "stm32f103c6-gpio.h"

#define USART_DIV(_PCLK, _BAUD) (uint32_t)(_PCLK / (16 * _BAUD))
#define USART_DIV_MUL100(_PCLK, _BAUD) (uint32_t)((25 * _PCLK) / (4 * _BAUD))
#define USART_MANTISSA(_PCLK, _BAUD) (uint32_t)(USART_DIV(_PCLK, _BAUD))
#define USART_MANTISSA_MUL100(_PCLK, _BAUD) (uint32_t)(USART_DIV(_PCLK, _BAUD) * 100)
#define USART_DIV_FRAC(_PCLK, _BAUD) (uint32_t)(((USART_DIV_MUL100(_PCLK, _BAUD) - USART_MANTISSA_MUL100(_PCLK, _BAUD)) * 16) / 100)
#define UASRT_BRR_REG(_PCLK, _BAUD) (uint32_t)(((USART_MANTISSA(_PCLK, _BAUD)) << 4) | ((USART_DIV_FRAC(_PCLK, _BAUD)) & 0x0F))

void (*GP_USART_IRQ_CallBack[3])(void);

static void USART_GPIO_Init(USARTx_t *USARTx, uint8_t Mode)
{
    /* USART1_TX        PA9 */
    /* USART1_RX        PA10 */

    /* USART2_TX        PA2  */
    /* USART2_RX        PA3  */

    /* USART3_TX        PB10 */
    /* USART3_RX        PB11 */
    GPIOx_t *USART_GPIOx;
    uint16_t USART_TX_PIN;
    uint16_t USART_RX_PIN;

    if (USARTx == USART1)
    {
        /* GPIOA */
        /* Enable CLK to GPIOx */
        USART_GPIOx = GPIOA;
        RCC_GPIOA_CLK_EN();

        USART_TX_PIN = GPIO_PIN_9;
        USART_RX_PIN = GPIO_PIN_10;
    }
    else if (USARTx == USART2)
    {
        /* GPIOA */
        /* Enable CLK to GPIOx */
        USART_GPIOx = GPIOA;
        RCC_GPIOA_CLK_EN();

        USART_TX_PIN = GPIO_PIN_2;
        USART_RX_PIN = GPIO_PIN_3;
    }
    else if (USARTx == USART3)
    {
        /* GPIOB */
        /* Enable CLK to GPIOx */
        USART_GPIOx = GPIOB;
        RCC_GPIOB_CLK_EN();

        USART_TX_PIN = GPIO_PIN_10;
        USART_RX_PIN = GPIO_PIN_11;
    }

    switch (Mode)
    {
    case USART_MODE_TX:
        /* Tx must be Alternate function push-pull */
        GPIO_Init(USART_GPIOx, GPIO_MODE_AF_PP_2MHZ, USART_TX_PIN);
        break;
    case USART_MODE_RX:
        /* Rx Must be Input pull-up or Input floating if not used */
        GPIO_Init(USART_GPIOx, GPIO_MODE_INPUT_PU, USART_RX_PIN);
        break;
    case USART_MODE_TX_RX:
        /* Tx must be Alternate function push-pull */
        GPIO_Init(USART_GPIOx, GPIO_MODE_AF_PP_2MHZ, USART_TX_PIN);
        /* Rx Must be Input pull-up or Input floating if not used */
        GPIO_Init(USART_GPIOx, GPIO_MODE_INPUT_PU, USART_RX_PIN);
        break;
    default:
        break;
    }
}

/**
 * @brief Initialaize the USARTx
 *
 * @param USARTx : USART1, UASRT2, UASRT3
 * @param USART_Config : Pointer to structure of USART_Config_t that hold the configration of USART
 */
void USART_Init(USARTx_t *USARTx, USART_Config_t *USART_Config)
{
    /* Initialize GPIOx */
    USART_GPIO_Init(USARTx, USART_Config->Mode);

    /* Enable CLK for USARTx and set callback FN */
    if (USARTx == USART1)
    {
        RCC_USART1_CLK_EN();
        GP_USART_IRQ_CallBack[0] = USART_Config->P_IRQ_Callback;
    }
    else if (USARTx == USART2)
    {
        RCC_USART2_CLK_EN();
        GP_USART_IRQ_CallBack[1] = USART_Config->P_IRQ_Callback;
    }
    else if (USARTx == USART3)
    {
        RCC_USART3_CLK_EN();
        GP_USART_IRQ_CallBack[2] = USART_Config->P_IRQ_Callback;
    }

    /* Enable USART */
    USARTx->CR1 |= (1 << 13);

    /* Set CR1 Register */
    USARTx->CR1 &= ~(0x16CC);
    USARTx->CR1 |= USART_Config->Data_Width;
    USARTx->CR1 |= USART_Config->Interrupt_Enable;
    USARTx->CR1 |= USART_Config->Mode;
    USARTx->CR1 |= USART_Config->Parity;

    /* Enable NVIC */
    if (USART_Config->Interrupt_Enable)
    {
        if (USARTx == USART1)
            NVIC_IRQ37_USART1_EN();
        else if (USARTx == USART2)
            NVIC_IRQ38_USART2_EN();
        else if (USARTx == USART3)
            NVIC_IRQ39_USART3_EN();
    }

    /* Set CR2 Register */
    USARTx->CR2 &= ~0x3000;
    USARTx->CR2 |= USART_Config->Stop_Bits;

    /* Set Baudrate */
    if (USARTx == USART1)
    {
        USARTx->BRR = UASRT_BRR_REG(RCC_Get_PCLK2_Freq(), USART_Config->Baudrate);
    }
    else if (USARTx == USART2 || USARTx == USART3)
    {
        USARTx->BRR = UASRT_BRR_REG(RCC_Get_PCLK1_Freq(), USART_Config->Baudrate);
    }
}

/**
 * @brief Reset USARTx
 *
 * @param USARTx : USART1, UASRT2, UASRT3
 */
void USART_Reset(USARTx_t *USARTx)
{
    /* USART1_TX        PA9 */
    /* USART1_RX        PA10 */

    /* USART2_TX        PA2  */
    /* USART2_RX        PA3  */

    /* USART3_TX        PB10 */
    /* USART3_RX        PB11 */
    GPIOx_t *USART_GPIOx;
    uint16_t USART_TX_PIN;
    uint16_t USART_RX_PIN;

    if (USARTx == USART1)
    {
        /* GPIOA */
        /* Enable CLK to GPIOx */
        RCC_USART1_RST();
        NVIC_IRQ37_USART1_DIS();
        USART_GPIOx = GPIOA;
        USART_TX_PIN = GPIO_PIN_9;
        USART_RX_PIN = GPIO_PIN_10;
    }
    else if (USARTx == USART2)
    {
        /* GPIOA */
        /* Enable CLK to GPIOx */
        RCC_USART2_RST();
        NVIC_IRQ38_USART2_DIS();
        USART_GPIOx = GPIOA;
        USART_TX_PIN = GPIO_PIN_2;
        USART_RX_PIN = GPIO_PIN_3;
    }
    else if (USARTx == USART3)
    {
        /* GPIOB */
        /* Enable CLK to GPIOx */
        RCC_USART3_RST();
        NVIC_IRQ39_USART3_DIS();
        USART_GPIOx = GPIOB;
        USART_TX_PIN = GPIO_PIN_10;
        USART_RX_PIN = GPIO_PIN_11;
    }
    GPIO_Init(USART_GPIOx, GPIO_MODE_INPUT_F, USART_TX_PIN);
    GPIO_Init(USART_GPIOx, GPIO_MODE_INPUT_F, USART_RX_PIN);
}

/**
 * @brief Transmit data using USART
 *
 * @param USARTx : USART1, UASRT2, UASRT3
 * @param Data : the data to be send
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 */
void USART_Send_Data(USARTx_t *USARTx, uint16_t Data, uint8_t Polling_Enable)
{
    if (Polling_Enable)
    {
        while (!(USARTx->SR & (1 << 7)))
            ;
    }

    if (USARTx->CR1 & (1 << 12))
    {
        /* 9 bits */
        USARTx->DR = (Data & 0x01FF);
    }
    else
    {
        /* 8 bits */
        USARTx->DR = (Data & 0xFF);
    }
}

/**
 * @brief Receive Data using USART
 *
 * @param USARTx : USART1, UASRT2, UASRT3
 * @param Polling_Enable : Specifies the Polling enable of USART
 *                         Must be set by @ref USART_POLLING_define
 * @return uint16_t : the received data
 */
uint16_t USART_Receive_Data(USARTx_t *USARTx, uint8_t Polling_Enable)
{
    uint16_t data;
    if (Polling_Enable)
    {
        while (!(USARTx->SR & (1 << 5)))
            ;
    }

    if (USARTx->CR1 & (1 << 12))
    {
        /* 9 bits */
        if (USARTx->CR1 & (1 << 10))
        {
            /* Parity Disabled */
            data = USARTx->DR & 0x01FF;
        }
        else
        {
            /* Parity Enabled */
            data = USARTx->DR & 0xFF;
        }
    }
    else
    {
        /* 8 bits */
        if (USARTx->CR1 & (1 << 10))
        {
            /* Parity Disabled */
            data = USARTx->DR & 0xFF;
        }
        else
        {
            /* Parity Enabled */
            data = USARTx->DR & 0x7F;
        }
    }
    return data;
}

void USART1_handler(void)
{
    GP_USART_IRQ_CallBack[0]();
}

void USART2_handler(void)
{
    GP_USART_IRQ_CallBack[1]();
}

void USART3_handler(void)
{
    GP_USART_IRQ_CallBack[2]();
}