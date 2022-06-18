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
    usart_config.Interrupt = USART_INTERRUPT_ENABLE;
    usart_config.UBRR_Value = 51;
    usart_config.String_Terminator = '#';
    USART_Init(&usart_config);
    USART_SendString("Learn in depth: Makram Maher", 29);
    while (1)
    {
        uint8_t receved = (uint8_t)USART_GetByte();

        switch (receved)
        {
        case 'c':
            lcd_Clear_Screen();
            break;
        case 'm':
            USART_SendString("Makram", 7);
            lcd_Clear_Screen();
            lcd_Send_String("Makram");
            break;
        case 'e':
            USART_SendString("Embedded System", 16);
            lcd_Clear_Screen();
            lcd_Send_String("Embedded System");
            break;
        case 's':
            USART_GetString(buffer, 20);
            USART_SendString(buffer, 20);
            lcd_Clear_Screen();
            lcd_Send_String(buffer);
        default:
            break;
        }
        wait_ms(30);
    }
    return 0;
}