/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 Master I2C Interfacing
 *
 *
 */

#include "atmega32-gpio.h"
#include "atmega32-timer0.h"

uint8_t CompateMatchCount;
void wait_ms(uint8_t time);

void CompareMatch_Callback(void)
{
    TIMER0_Clear_Compare_Flag();
    CompateMatchCount++;
}

int main(void)
{
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_0);
    GPIO_Write_Pin(GPIOA, GPIO_PIN_0, GPIO_PIN_LOW);

    TIMER0_Config Config;
    Config.Mode = TIMER0_MODE_NORMAL;
    Config.Clock = TIMER0_CLOCK_DIV_256;
    Config.Interrupt_Enable = TIMER0_INTERRUPT_COMPARE_MATCH;
    Config.Compare_Match_Output = TIMER0_COMPARE_MATCH_OUTPUT_DISCONNECT_OC0;
    Config.P_IRQ_Compare_Match_Callback = CompareMatch_Callback;
    Config.P_IRQ_Over_Flow_Callback = 0;

    TIMER0_Init(&Config);
    TIMER0_Start();


    while (1)
    {
        if (CompateMatchCount == 8)
        {
            CompateMatchCount = 0;
            GPIO_Write_Pin(GPIOA, GPIO_PIN_0, !GPIO_Read_Pin(GPIOA, GPIO_PIN_0));
        }
    }
}
