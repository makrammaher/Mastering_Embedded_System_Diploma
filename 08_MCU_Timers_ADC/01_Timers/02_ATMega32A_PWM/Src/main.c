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

void wait_ms(uint8_t time);

uint8_t OverFlowCount = 0;
void overFlow_Callback(void)
{
    TIMER0_Clear_OverFlow_Flag();
    OverFlowCount++;
}

int main(void)
{
    uint8_t PWM_Compare_Value, addValue = 1;
    TIMER0_Config Config;
    Config.Mode = TIMER0_MODE_PWM_FAST;
    Config.Clock = TIMER0_CLOCK_DIV_64;
    Config.Interrupt_Enable = TIMER0_INTERRUPT_OVERFLOW;
    Config.Compare_Match_Output = TIMER0_COMPARE_MATCH_OUTPUT_PWM_NON_INVERTING;
    Config.P_IRQ_Compare_Match_Callback = 0;
    Config.P_IRQ_Over_Flow_Callback = overFlow_Callback;
    
    GPIO_Init(GPIOB, GPIO_MODE_OUTPUT, GPIO_PIN_3);

    TIMER0_Init(&Config);
    PWM_Compare_Value = 14;
    TIMER0_Set_Compare_Value(PWM_Compare_Value);
    TIMER0_Start();

    while (1)
    {
        if(OverFlowCount == 3)
        {
            if(PWM_Compare_Value == 14)
            {
                addValue = 1;
            }
            else if(PWM_Compare_Value == 31)
            {
                addValue = -1;
            }
            PWM_Compare_Value += addValue;
            OverFlowCount = 0;
            TIMER0_Set_Compare_Value(PWM_Compare_Value);
        }
    }
}
