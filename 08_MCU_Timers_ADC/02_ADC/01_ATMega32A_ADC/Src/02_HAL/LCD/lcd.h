/*
 *           File: lcd.h
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 LCD and Keypad
 *
 *
 */

#ifndef _LCD_H_
#define _LCD_H_

#include "atmega32.h"
#include "atmega32-gpio.h"
#include <stdio.h>

/*#define LCD_EIGHT_BIT_MODE*/
#define LCD_FOUR_BIT_MODE 


#define LCD_DATA_GPIOx      GPIOC
#define LCD_DATA_DDR        (LCD_DATA_GPIOx)->DDRx
#define LCD_DATA_PORT       (LCD_DATA_GPIOx)->PORTx
#define LCD_DATA_PIN        (LCD_DATA_GPIOx)->PINx
#define LCD_DATA_SHIFT      3


#define LCD_CTRL_GPIOx      GPIOC
#define LCD_EN_PIN          GPIO_PIN_2
#define LCD_RW_PIN          GPIO_PIN_1
#define LCD_RS_PIN          GPIO_PIN_0


#define LCD_RS_DATA         0
#define LCD_RS_COMMAND      1
#define LCD_RW_WRITE        0
#define LCD_RW_READ         1

#define LCD_CMD_CLEAR_SCREEN                0x01
#define LCD_CMD_ENRTY_MODE                  0x06
#define LCD_CMD_BEGIN_AT_FIRST_RAW          0x80
#define LCD_CMD_BEGIN_AT_SECOND_RAW         0x80
#define LCD_CMD_ENTRY_INC                   0x06
#define LCD_CMD_ENTRY_INC_SHIFT             0x07
#define LCD_CMD_ENTRY_DEC                   0x04
#define LCD_CMD_ENTRY_DEC_SHIFT             0x05
#define LCD_CMD_DISP_ON                     0x0C
#define LCD_CMD_DISP_ON_BLINK               0x0D
#define LCD_CMD_DISP_ON_CURSOR_BLINK        0x0F
#define LCD_CMD_DISP_ON_CURSOR              0x0E
#define LCD_CMD_DISP_OFF                    0x08
#define LCD_CMD_MOVE_CURSOR_RIGHT           0x14
#define LCD_CMD_MOVE_CURSOR_LEFT            0x10
#define LCD_CMD_MOVE_DISP_RIGHT             0x1C
#define LCD_CMD_MOVE_DISP_LEFT              0x18
#define LCD_CMD_FUNCTION_8BIT_2LINE_5x8     0x38
#define LCD_CMD_FUNCTION_8BIT_1LINE_5x10    0x34
#define LCD_CMD_FUNCTION_4BIT_2LINE_5x8     0x28
#define LCD_CMD_FUNCTION_4BIT_1LINE_5x10    0x24

void lcd_init(void);
void lcd_Send_Command(uint8_t command);
void lcd_Send_Data(uint8_t data);
void lcd_Send_String(char* data);
void lcd_Send_Num(int number);
void lcd_Send_Real_Num(double number);
void lcd_Goto_XY(uint8_t x, uint8_t y);
void lcd_Enable_Signal(void);
void lcd_Clear_Screen(void);
uint8_t lcd_Is_Busy(void);
void wait_ms(uint8_t time);


#endif