/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 LCD and Keypad
 *
 *
 */

#include "lcd.h"
#include "keypad.h"

void wait_ms(uint8_t time);


int main(void)
{

    lcd_init();
    lcd_Send_String("Embedded System:");
    wait_ms(255);
    lcd_Goto_XY(1,0);
    lcd_Send_String("Eng.Makram Maher");
    wait_ms(255);
    lcd_Clear_Screen();
    lcd_Goto_XY(0,0);
    uint8_t i;
    lcd_Send_Command(LCD_CMD_DISP_ON);
    for(i = 11;i>0;i--)
    {
        lcd_Clear_Screen();
        lcd_Goto_XY(0,0);
        lcd_Send_Num(i - 1);
        wait_ms(100);
    }
    keypad_init();

    lcd_Clear_Screen();
    lcd_Goto_XY(0,0);
    lcd_Send_String("Press Any key!");
    lcd_Send_Command(LCD_CMD_DISP_ON_BLINK);
    wait_ms(255);
    lcd_Clear_Screen();
    lcd_Goto_XY(0,0);
    while (1)
    {
        char key;
        key = keypad_getkey();
        switch(key)
        {
            case 0:
            /* No key pressed */
            break;
            case '?':
            /* Clear screen */
            lcd_Clear_Screen();
            lcd_Goto_XY(0,0);
            break;
            default:
            lcd_Send_Data(key);
            break;

        }

    }
}
