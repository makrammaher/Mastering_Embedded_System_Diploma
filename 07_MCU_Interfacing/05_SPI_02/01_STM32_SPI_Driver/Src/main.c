/*
 *           File: main.c
 *     Created on: Thursday 19/05/2022 21:46
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx GPIO
 *
 *
 */

#include "lcd.h"
#include "stm32f103c6-usart.h"
#include "stm32f103c6-spi.h"

/* #define SPI_MASTER_MODE */
#define SPI_SLAVE_MODE

void SPI_Recive_Callback(void)
{
#ifdef SPI_SLAVE_MODE
    uint16_t data = 0xFF;
    if(SPI1->SR & (1<<0))
    {
        data = SPI_Send_Receive_Data(SPI1, data, SPI_POLLING_DISABLE);
        USART_Send_Data(USART1, data, USART_POLLING_ENABLE);
    }
#endif
}

void USART_Recive_Callback(void)
{
#ifdef SPI_MASTER_MODE
    uint16_t data;
    data = USART_Receive_Data(USART1, USART_POLLING_ENABLE);
    USART_Send_Data(USART1, data, USART_POLLING_ENABLE);
    GPIO_Write_Pin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    data = SPI_Send_Receive_Data(SPI1, data, SPI_POLLING_ENABLE);
    GPIO_Write_Pin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif
}

int main(void)
{
    /* Initialization */
    USART_Config_t USART_Config;
    USART_Config.Baudrate = 9600;
    USART_Config.Data_Width = USART_DATA_WIDTH_8_BITS;
    USART_Config.Interrupt_Enable = USART_INTERRUPT_RXNE;
    USART_Config.Mode = USART_MODE_TX_RX;
    USART_Config.P_IRQ_Callback = USART_Recive_Callback;
    USART_Config.Parity = USART_PARITY_NONE;
    USART_Config.Stop_Bits = USART_STOP_BITS__1;
    USART_Init(USART1, &USART_Config);

    SPI_Config_t SPI_Config;
    SPI_Config.CLK_Polarity_Phase = SPI_CLK_LOW_IDLE_SECOND_EDGE_DATA_CAPTURE;
    SPI_Config.CLK_Prescaler = SPI_PRESCALER_DIV_8;
    SPI_Config.Direction_Mode = SPI_DIRECTION_2LINES;
    SPI_Config.Frame_Formate = SPI_FRAME_8BIT_MSBF;

#ifdef SPI_MASTER_MODE
    SPI_Config.Mode = SPI_MODE_MASTER;
    SPI_Config.Interrupt_Enable = SPI_INTERRUPT_DISABLE;
    SPI_Config.NSS = SPI_NSS_SOFTWARE_SET;
    SPI_Config.P_IRQ_Callback = 0;
    /* Configure NSS as output */
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_4);
    GPIO_Write_Pin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
#endif

#ifdef SPI_SLAVE_MODE
    SPI_Config.Mode = SPI_MODE_SLAVE;
    SPI_Config.Interrupt_Enable = SPI_INTERRUPT_RXNE_ENABLE;
    SPI_Config.NSS = SPI_NSS_HARDWARE_MULTIMASTER;
    SPI_Config.P_IRQ_Callback = SPI_Recive_Callback;
#endif

    SPI_Init(SPI1, &SPI_Config);

    while (1)
    {
    }
    return 0;
}
