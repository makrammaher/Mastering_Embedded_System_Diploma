/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 Master I2C Interfacing
 *
 *
 */

#include "atmega32-i2c.h"
#include "atmega32-gpio.h"

#define I2C_MASTER

//#define I2C_SLAVE

void wait_ms(uint8_t time);

int main(void)
{
#ifdef I2C_MASTER
    uint8_t number = 0;
    I2C_Config_t Config;
    Config.ACK_Enable = I2C_ACK_ENABLE;
    Config.Interrupt_Enable = I2C_INTERRUPT_DISABLE;
    Config.P_IRQ_Callback = 0;
    Config.My_Address = 0b0001110;
    Config.SCL_Frequency = 30000;
    Config.SCL_Prescaler = I2C_PRESCALER_1;
    I2C_Init(&Config);

    while (1)
    {
        wait_ms(200);
        I2C_Send_Start_Condition(I2C_POLLING_ENABLE);
        I2C_Send_Slave_Address(0b1110001, I2C_SLA_WRITE, I2C_POLLING_ENABLE);
        I2C_Send_Data(number++, I2C_POLLING_ENABLE);
        I2C_Send_Stop_Condition(I2C_POLLING_DISABLE);
    }
    return 0;
#endif
#ifdef I2C_SLAVE
    DDRA = 0xFF;
    uint8_t number = 0;
    I2C_Config_t Config;
    Config.ACK_Enable = I2C_ACK_ENABLE;
    Config.Interrupt_Enable = I2C_INTERRUPT_DISABLE;
    Config.P_IRQ_Callback = 0;
    Config.My_Address = 0b1110001;
    Config.SCL_Frequency = 30000;
    Config.SCL_Prescaler = I2C_PRESCALER_1;
    I2C_Init(&Config);
    while (1)
    {
        I2C_Receive_Data(I2C_POLLING_ENABLE);
        number = I2C_Receive_Data(I2C_POLLING_ENABLE);
        PORTA = number;
    }
#endif
}
