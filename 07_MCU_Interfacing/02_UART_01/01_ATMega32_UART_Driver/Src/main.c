/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 USART Driver
 *
 *
 */

#include "atmega32-gpio.h"
#include "atmega32-uart.h"
#include "lcd.h"

void wait_ms(uint8_t time);

int main(void)
{
    char buffer[20] = {0};
    lcd_init();
    lcd_Clear_Screen();

    /* Initialize USART */
    USART_Config_t usart_config;
    usart_config.Data = USART_DATA_8_BIT;
    usart_config.Mode = USART_MODE_ASYNC_RECEIVER_TRANSMITTER;
    usart_config.Parity = USART_PARITY_EVEN;
    usart_config.Speed_Mode = USART_NORMAL_SPEED_MODE;
    usart_config.Stop = USART_STOP_1_BIT;
    usart_config.UBRR_Value = 51;
    USART_Init(&usart_config);
    while (1)
    {
        uint8_t receved = (uint8_t)USART_Recive();

        switch (receved)
        {
        case 'c':
            lcd_Clear_Screen();
            break;
        case 'm':
            USART_SendString("Makram");
            lcd_Clear_Screen();
            lcd_Send_String("Makram");
            break;
        case '#':
            USART_ReadString(buffer, '#');
            USART_SendString(buffer);
            lcd_Clear_Screen();
            lcd_Send_String(buffer);
            break;
        case 'e':
            USART_SendString("Embedded System");
            lcd_Clear_Screen();
            lcd_Send_String("Embedded System");
            break;
        default:
            break;
        }
        wait_ms(30);
    }
    return 0;
}