/*
 *           File: lcd.c
 *     Created on: Tuesday 31/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: LCD Driver HAL Layer
 *
 *
 */

#include "lcd.h"

void wait_ms(uint8_t time)
{
    uint8_t i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 255; j++)
            ;
        for (j = 0; j < 255; j++)
            ;
        for (j = 0; j < 255; j++)
            ;
        for (j = 0; j < 255; j++)
            ;
        for (j = 0; j < 255; j++)
            ;
        for (j = 0; j < 255; j++)
            ;
        for (j = 0; j < 255; j++)
            ;
    }
}

void lcd_init(void)
{
    wait_ms(20);
    /* Set LCD Control pins as an output and init it with 0 */
    GPIO_Init(LCD_CTRL_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, LCD_EN_PIN);
    GPIO_Init(LCD_CTRL_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, LCD_RW_PIN);
    GPIO_Init(LCD_CTRL_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, LCD_RS_PIN);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_EN_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_RESET);

#ifdef LCD_EIGHT_BIT_MODE
    /* Set LCD Data PIns as an output */
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_0);
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_1);
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_2);
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_3);
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_4);
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_5);
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_6);
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_7);

    wait_ms(1);

    lcd_Send_Command(LCD_CMD_FUNCTION_8BIT_2LINE_5x8);
    lcd_Send_Command(LCD_CMD_DISP_ON_CURSOR);
    lcd_Send_Command(LCD_CMD_ENTRY_INC);
#endif

#ifdef LCD_FOUR_BIT_MODE
    /* Set LCD Data PIns as an output */
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, (GPIO_PIN_0 << LCD_DATA_SHIFT));
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, (GPIO_PIN_1 << LCD_DATA_SHIFT));
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, (GPIO_PIN_2 << LCD_DATA_SHIFT));
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, (GPIO_PIN_3 << LCD_DATA_SHIFT));
    wait_ms(1);

    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_RESET);

    uint16_t tempReg = GPIO_Read_Port(LCD_DATA_GPIO);
    tempReg = ((tempReg & ~(0x0F << LCD_DATA_SHIFT)) | (0x02 << LCD_DATA_SHIFT));
    GPIO_Write_Port(LCD_DATA_GPIO, tempReg);
    lcd_Enable_Signal();
    lcd_Send_Command(0x02);
    lcd_Send_Command(LCD_CMD_FUNCTION_4BIT_2LINE_5x8);
    lcd_Send_Command(LCD_CMD_DISP_ON_CURSOR);
    lcd_Send_Command(LCD_CMD_ENTRY_INC);
#endif
}

void lcd_Send_Command(uint8_t command)
{
    while (lcd_Is_Busy())
        ;

#ifdef LCD_EIGHT_BIT_MODE
    uint16_t tempReg = GPIO_Read_Port(LCD_DATA_GPIO);
    tempReg = ((tempReg & ~(0x00FF)) | (command));
    GPIO_Write_Port(LCD_DATA_GPIO, tempReg);

    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_RESET);
    lcd_Enable_Signal();
#endif

#ifdef LCD_FOUR_BIT_MODE
    uint16_t tempReg = GPIO_Read_Port(LCD_DATA_GPIO);
    tempReg = ((tempReg & ~(0x0F << LCD_DATA_SHIFT)) | (((command & 0xF0) >> 4) << LCD_DATA_SHIFT));
    GPIO_Write_Port(LCD_DATA_GPIO, tempReg);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_RESET);

    lcd_Enable_Signal();

    wait_ms(1);

    tempReg = GPIO_Read_Port(LCD_DATA_GPIO);
    tempReg = ((tempReg & ~(0x0F << LCD_DATA_SHIFT)) | ((command & 0x0F) << LCD_DATA_SHIFT));
    GPIO_Write_Port(LCD_DATA_GPIO, tempReg);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_RESET);

    lcd_Enable_Signal();

#endif
}

void lcd_Send_Data(uint8_t data)
{
    while (lcd_Is_Busy())
        ;
    
#ifdef LCD_EIGHT_BIT_MODE
    uint16_t tempReg = GPIO_Read_Port(LCD_DATA_GPIO);
    tempReg = ((tempReg & ~(0x00FF)) | (data));
    GPIO_Write_Port(LCD_DATA_GPIO, tempReg);

    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_SET);
    lcd_Enable_Signal();
#endif

#ifdef LCD_FOUR_BIT_MODE
    uint16_t tempReg = GPIO_Read_Port(LCD_DATA_GPIO);
    tempReg = ((tempReg & ~(0x0F << LCD_DATA_SHIFT)) | (((data & 0xF0) >> 4) << LCD_DATA_SHIFT));
    GPIO_Write_Port(LCD_DATA_GPIO, tempReg);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_SET);
    lcd_Enable_Signal();

    wait_ms(1);

    tempReg = GPIO_Read_Port(LCD_DATA_GPIO);
    tempReg = ((tempReg & ~(0x0F << LCD_DATA_SHIFT)) | ((data & 0x0F) << LCD_DATA_SHIFT));
    GPIO_Write_Port(LCD_DATA_GPIO, tempReg);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_RESET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_SET);
    lcd_Enable_Signal();

#endif
}

void swap(char* ptr1, char* ptr2)
{
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap((str+start), (str+end));
        start++;
        end--;
    }
}
 
/* Implementation of itoa()*/
char* itoa(int num, char* str, int base)
{
    int i = 0;
    uint8_t isNegative = 0;
 
    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    /* In standard itoa(), negative numbers are handled only with*/
    /* base 10. Otherwise numbers are considered unsigned.*/
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
 
    /* Process individual digits*/
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
 
    /* If number is negative, append '-'*/
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; /* Append string terminator*/
 
    /* Reverse the string*/
    reverse(str, i);
 
    return str;
}

void lcd_Send_Num(int number)
{
    char str[7];
    itoa(number, str, 10);
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

void lcd_Send_String(char *data)
{
    int count = 0;
    while (*data > 0)
    {
        count++;
        lcd_Send_Data((uint8_t)*data++);
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
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_EN_PIN, GPIO_PIN_SET);
    wait_ms(5);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_EN_PIN, GPIO_PIN_RESET);
}

void lcd_Clear_Screen(void)
{
    lcd_Send_Command(LCD_CMD_CLEAR_SCREEN);
}

uint8_t lcd_Is_Busy(void)
{
    volatile uint8_t isbusy;
#ifdef LCD_EIGHT_BIT_MODE
    /* Set D7 PIN to be an input PIN */
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_INPUT_F, GPIO_PIN_7);
    wait_ms(1);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_SET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_RESET);
    lcd_Enable_Signal();
    isbusy = GPIO_Read_Pin(LCD_DATA_GPIO, GPIO_PIN_7);
    /*  Set D7 PIN to be an output PIN */
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_7);
#endif

#ifdef LCD_FOUR_BIT_MODE
    /* Set D7 PIN to be an input PIN */
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_INPUT_F, GPIO_PIN_3 << LCD_DATA_SHIFT);
    wait_ms(1);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RW_PIN, GPIO_PIN_SET);
    GPIO_Write_Pin(LCD_CTRL_GPIO, LCD_RS_PIN, GPIO_PIN_RESET);
    lcd_Enable_Signal();
    isbusy = GPIO_Read_Pin(LCD_DATA_GPIO, GPIO_PIN_3 << LCD_DATA_SHIFT);
    lcd_Enable_Signal();
    GPIO_Init(LCD_DATA_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, GPIO_PIN_3 << LCD_DATA_SHIFT);
#endif

    /*return isbusy;*/
    return 0;
}