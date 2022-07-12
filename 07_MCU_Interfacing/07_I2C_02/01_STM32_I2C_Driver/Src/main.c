/*
 *           File: main.c
 *     Created on: Thursday 19/05/2022 21:46
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx GPIO
 *
 *
 */
#include "lcd.h"
#include "eeprom.h"
#include "stm32f103c6-i2c.h"

int main(void)
{
    uint8_t array1[10], array2[10],  i;
    EEPROM_Init(I2C1);
    wait_ms(255);
    for(i = 0;i<10;i++)
    {
        array1[i] = i;
    }
    EEPROM_Write_N_Data(0xAF, array1, 10);
    wait_ms(255);
    EEPROM_Read_N_Data(0xAF, array2, 10);

    wait_ms(255);

    EEPROM_Write_N_Data(0x0A, array1, 10);
    wait_ms(255);
    EEPROM_Read_N_Data(0xAF, array2, 10);

    wait_ms(255);

    EEPROM_Write_N_Data(0xA000, array1, 10);
    wait_ms(255);
    EEPROM_Read_N_Data(0xA000, array2, 10);
    while (1)
    {
    }
    return 0;
}
