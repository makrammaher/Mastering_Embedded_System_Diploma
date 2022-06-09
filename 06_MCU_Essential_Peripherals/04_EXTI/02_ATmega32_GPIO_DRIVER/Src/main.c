/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 LCD and Keypad
 *
 *
 */


#include "atmega32-gpio.h"
#include "atmega32-exti.h"
#include "keypad.h"
#include "lcd.h"

void wait_ms(uint8_t time);

void EXTIPB9_IRQ_Handler(void)
{
    lcd_Send_String("IRQ EXTI9 is happened __|--");
}

int main(void)
{
    lcd_init();
    lcd_Clear_Screen();
    keypad_init();
    EXTI_Init(EXTI0, EXTI_TRIGGER_RISING_EDGE, EXTIPB9_IRQ_Handler);
    while (1)
    {
        char key;
        key = keypad_getkey();
        switch (key)
        {
        case 0:
            /* No key pressed */
            break;
        case '?':
            /* Clear screen */
            lcd_Clear_Screen();
            lcd_Goto_XY(0, 0);
            break;
        default:
            lcd_Send_Data(key);
            break;
        }
        wait_ms(3);
    }
    return 0;
}