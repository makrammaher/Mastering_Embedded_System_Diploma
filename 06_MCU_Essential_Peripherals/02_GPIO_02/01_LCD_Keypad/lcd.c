/*
 *           File: lcd.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 LCD and Keypad
 *
 *
 */

#include "lcd.h"

void wait_ms(uint8_t time)
{
    uint8_t i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 255; j++);
    }
}

void lcd_init(void)
{
    wait_ms(20);
    /* Set LCD Control pins as an output and init it with 0 */
    LCD_CTRL_DDR |= ((1 << LCD_EN_PIN) | (1 << LCD_RW_PIN) | (1 << LCD_RS_PIN));
    LCD_CTRL_PORT &= ~ ((1 << LCD_EN_PIN) | (1 << LCD_RW_PIN) | (1 << LCD_RS_PIN));

#ifdef LCD_EIGHT_BIT_MODE
    /* Set LCD Data PIns as an output */
    LCD_DATA_DDR = 0xFF;
    wait_ms(1);

    lcd_Send_Command(LCD_CMD_FUNCTION_8BIT_2LINE_5x8);
    lcd_Send_Command(LCD_CMD_DISP_ON_CURSOR);
    lcd_Send_Command(LCD_CMD_ENTRY_INC);
#endif

#ifdef LCD_FOUR_BIT_MODE
    /* Set LCD Data PIns as an output */
    LCD_DATA_DDR |= (0x0F << LCD_DATA_SHIFT);
    wait_ms(1);

    CLEARBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    LCD_DATA_PORT = ((LCD_DATA_PORT & ~(0x0F << LCD_DATA_SHIFT)) | (0x02 << LCD_DATA_SHIFT)) ;
    lcd_Enable_Signal();
    lcd_Send_Command(0x02);
    lcd_Send_Command(LCD_CMD_FUNCTION_4BIT_2LINE_5x8);
    lcd_Send_Command(LCD_CMD_DISP_ON_CURSOR);
    lcd_Send_Command(LCD_CMD_ENTRY_INC);
#endif
}

void lcd_Send_Command(uint8_t command)
{
    while (lcd_Is_Busy());

#ifdef LCD_EIGHT_BIT_MODE
    LCD_DATA_PORT = command;
    CLEARBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    lcd_Enable_Signal();
#endif

#ifdef LCD_FOUR_BIT_MODE
    CLEARBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    LCD_DATA_PORT = ((LCD_DATA_PORT & ~(0x0F << LCD_DATA_SHIFT)) | (((command & 0xF0) >> 4) << LCD_DATA_SHIFT)) ;
    lcd_Enable_Signal();

    wait_ms(1);

    CLEARBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    LCD_DATA_PORT = ((LCD_DATA_PORT & ~(0x0F << LCD_DATA_SHIFT)) | ((command & 0x0F) << LCD_DATA_SHIFT)) ;
    lcd_Enable_Signal();

#endif
}

void lcd_Send_Data(uint8_t data)
{
    while (lcd_Is_Busy());

#ifdef LCD_EIGHT_BIT_MODE
    LCD_DATA_PORT = data;
    SETBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    lcd_Enable_Signal();
#endif

#ifdef LCD_FOUR_BIT_MODE
    SETBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    LCD_DATA_PORT = ((LCD_DATA_PORT & ~(0x0F << LCD_DATA_SHIFT)) | (((data & 0xF0) >> 4) << LCD_DATA_SHIFT)) ;
    lcd_Enable_Signal();

    wait_ms(1);

    SETBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    LCD_DATA_PORT = ((LCD_DATA_PORT & ~(0x0F << LCD_DATA_SHIFT)) | ((data & 0x0F) << LCD_DATA_SHIFT)) ;
    lcd_Enable_Signal();

#endif
}

void lcd_Send_Num(int number)
{
    char str[7];
    sprintf(str, "%d", number);
    lcd_Send_String(str);
}

void lcd_Send_Real_Num(double number)
{
    char str[16];
    char *tmpSign = (number < 0) ? "-" : "";
    float tmpVal = (number < 0) ? -number : number;
    int tmpInt1 = tmpVal;
    float tmpFrac = tmpVal - tmpInt1;
    int tmpInt2 = tmpFrac * 100 + 1; 
    sprintf(str, "%s%d.%d", tmpSign, tmpInt1, tmpInt2);
    lcd_Send_String(str);
}

void lcd_Goto_XY(uint8_t x, uint8_t y)
{
    if (x == 0)
    {
        /* First line */
        if (y < 16 && y >= 0)
        {
            lcd_Send_Command(0x80 + y);
        }
    }
    else if (x == 1)
    {
        if (y < 16 && y >= 0)
        {
            lcd_Send_Command(0xC0 + y);
        }
    }
}

void lcd_Send_String(char* data)
{
    int count = 0;
    while (*data > 0)
    {
        count++;
        lcd_Send_Data((uint8_t) *data++);
        if (count == 16)
        {
            lcd_Goto_XY(1, 0);
        }
        else if (count == 32)
        {
            lcd_Clear_Screen();
            lcd_Goto_XY(0, 0);
            count = 0;
        }
    }
}


void lcd_Enable_Signal(void)
{
    LCD_CTRL_PORT |= (1 << LCD_EN_PIN);
    wait_ms(5);
    LCD_CTRL_PORT &= ~ (1 << LCD_EN_PIN);
}

void lcd_Clear_Screen(void)
{
    lcd_Send_Command(LCD_CMD_CLEAR_SCREEN);
}

uint8_t lcd_Is_Busy(void)
{
    uint8_t isbusy;
#ifdef LCD_EIGHT_BIT_MODE
    /* Set D7 PIN to be an input PIN */
    CLEARBIT(LCD_DATA_DDR, 7);
    wait_ms(1);
    SETBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    lcd_Enable_Signal();

    isbusy = ((LCD_DATA_PIN & 0x80) >> 7);
    SETBIT(LCD_DATA_DDR, 7);
#endif

#ifdef LCD_FOUR_BIT_MODE
    /* Set LCD Data PIns as an output */
    CLEARBIT(LCD_DATA_DDR, 3 + LCD_DATA_SHIFT);
    wait_ms(1);
    SETBIT(LCD_CTRL_PORT, LCD_RW_PIN);
    CLEARBIT(LCD_CTRL_PORT, LCD_RS_PIN);
    lcd_Enable_Signal();

    isbusy = ((LCD_DATA_PIN & (0x8 << LCD_DATA_SHIFT)) >> 3 >> LCD_DATA_SHIFT);
    SETBIT(LCD_DATA_DDR, 3 + LCD_DATA_SHIFT);
    lcd_Enable_Signal();
#endif

    /*return isbusy;*/
    return 0;
}