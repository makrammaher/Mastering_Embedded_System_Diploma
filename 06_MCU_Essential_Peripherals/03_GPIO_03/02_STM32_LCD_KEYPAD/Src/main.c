/*
 *           File: main.c
 *     Created on: Thursday 19/05/2022 21:46
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx GPIO
 *
 *
 */

#include "lcd.h"
#include "keypad.h"
#include "bcd_7seg.h"

int main(void)
{
    
    /* Initialization */
    RCC->CFGR |= (0b101 << 11);
    RCC->CFGR |= (0b100 << 8);
    RCC->CFGR &= ~(1 << 7);
    RCC->CFGR &= ~((uint32_t)2);
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_AFIO_CLK_EN();
    AFIO->MAPR |= 1<<26;
    lcd_init();
    lcd_Send_String("Embedded System:");
    wait_ms(255);
    lcd_Goto_XY(1, 0);
    lcd_Send_String("Eng.Makram Maher");
    wait_ms(255);
    lcd_Clear_Screen();
    lcd_Goto_XY(0, 0);
    uint8_t i;
    lcd_Send_Command(LCD_CMD_DISP_ON);
    for (i = 11; i > 0; i--)
    {
        lcd_Clear_Screen();
        lcd_Goto_XY(0, 0);
        lcd_Send_Num(i - 1);
        wait_ms(100);
    }
    keypad_init();
    bcd_7seg_Init();

    lcd_Clear_Screen();
    lcd_Goto_XY(0, 0);
    lcd_Send_String("Press Any key!");
    lcd_Send_Command(LCD_CMD_DISP_ON_BLINK);
    wait_ms(255);
    lcd_Clear_Screen();
    lcd_Goto_XY(0, 0);
    uint8_t bcd_num = 0;
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
            bcd_num = 0;
            bcd_7deg_Write(bcd_num);
            break;
        default:
            lcd_Send_Data(key);
            bcd_num++;
            bcd_7deg_Write(bcd_num);
            break;
        }
        wait_ms(3);
    }
    return 0;
}
