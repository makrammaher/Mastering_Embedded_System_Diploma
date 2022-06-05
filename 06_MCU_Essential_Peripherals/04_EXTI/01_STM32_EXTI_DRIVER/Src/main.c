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
#include "stm32f103c6-exti.h"

uint8_t G_IRQ_Flag = 0;

void EXTIPB9_IRQ_Handler(void)
{
    G_IRQ_Flag = 1;
    lcd_Send_String("IRQ EXTI9 is happened __|--");
    wait_ms(255);
}

int main(void)
{
    /* Initialization */
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_AFIO_CLK_EN();
    AFIO->MAPR |= 1<<26;
    lcd_init();
    lcd_Clear_Screen();
    keypad_init();
    EXTI_PinConfig_t EXTI_Config;
    EXTI_Config.EXTI_PIN = EXTI9_PB9;
    EXTI_Config.IRQ_Enable = EXTI_IRQ_ENABLE;
    EXTI_Config.Trigger_Case = EXTI_TRIGGER_FALLING;
    EXTI_Config.P_IRQ_Callback = &EXTIPB9_IRQ_Handler;
    EXTI_GPIO_Init(&EXTI_Config);

    
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
