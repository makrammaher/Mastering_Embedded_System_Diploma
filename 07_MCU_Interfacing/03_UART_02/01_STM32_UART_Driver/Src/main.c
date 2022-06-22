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

void USART_Recive_Callback(void)
{
    uint8_t data;
    data = (uint8_t)USART_Receive_Data(USART1, USART_POLLING_ENABLE);
    USART_Send_Data(USART1, data, USART_POLLING_ENABLE);
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

    while (1)
    {
    }
    return 0;
}
