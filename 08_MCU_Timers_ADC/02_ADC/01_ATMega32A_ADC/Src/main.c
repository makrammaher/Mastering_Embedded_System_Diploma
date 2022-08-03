/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 ADC Driver Interfacing
 *
 *
 */
#include "atmega32-adc.h"
#include "lcd.h"

void wait_ms(uint8_t time);

int main(void)
{
    uint16_t ADC_Value = 0;
    uint8_t precentage = 0;
    uint8_t Slider = 0, i;
    ADC_Config_t Config;
    Config.Mode = ADC_MODE_SINGLE_CONVERSION;
    Config.Prescaller = ADC_PRESCALLER_2;
    Config.VRef = ADC_VREF_AREF;
    Config.Interrupt_Enable = ADC_INTERRUPT_DISABLE;
    Config.P_IRQ_Callback = 0;
    ADC_Init(&Config);
    wait_ms(100);
    lcd_init();
    while (1)
    {
        ADC_Start_Conversion(ADC_CHANNEL_ADC0);
        ADC_Value = ADC_Read(ADC_POLLING_ENABLE);
        precentage = (uint8_t)(((uint32_t)ADC_Value * 100) / 1023);
        lcd_Clear_Screen();
        lcd_Send_String("Volume = ");
        lcd_Send_Num(precentage);
        lcd_Send_Data('%');
        lcd_Goto_XY(1, 0);
        Slider = (uint8_t)(((uint32_t)ADC_Value * 16) / 1023);
        for (i = 0; i < Slider; i++)
        {
            lcd_Send_Data(255);
        }
        wait_ms(255);
        wait_ms(255);
        wait_ms(255);
        wait_ms(255);
        wait_ms(255);
        wait_ms(255);
    }
}
