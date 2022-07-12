/*
 *           File: eeprom.c
 *     Created on: Saturday 09/07/2022 02:38
 *         Author: Makram Maher Makram
 *        Subject: EEPROM Driver Using Polling
 *
 *
 */
#include "eeprom.h"

I2Cx_t *I2C_x;

/**
 * @brief Initialize EEPROM
 *
 * @param I2Cx : I2C1, I2C2
 */
void EEPROM_Init(I2Cx_t *I2Cx)
{
    I2C_x = I2Cx;
    I2C_Config_t Config;
    Config.Acknowledge = I2C_ACKNOWLEDGE_ENABLE;
    Config.Address = 0x44;
    Config.Frequency = 100000;
    Config.Frequency_Mode = I2C_FREQUNCY_MODE_STANDERD;
    Config.GeneralCall = I2C_GENERAL_CALL_DISABLE;
    Config.Interrupt_Enable = I2C_INTERRUPT_DISABLE;
    Config.P_IRQ_Callback = 0;
    Config.Stretch = I2C_STRETCH_ENABLE;
    I2C_Init(I2C_x, &Config);
}

/**
 * @brief Write N-Bytes To EEPROM
 *
 * @param Memory_Address : Memory Address in EEPROM
 * @param Data : Pointer to data to be Written in EEPROM
 * @param Length : The Data Length of the Data to be Written
 */
void EEPROM_Write_N_Data(uint16_t Memory_Address, uint8_t *Data, uint8_t Length)
{
    I2C_Send_Start_Condition(I2C_x, I2C_POLLING_ENABLE);
    I2C_Send_Address(I2C_x, EEPROM_ADDRESS, I2C_DIRECTION_WRITE, I2C_POLLING_ENABLE);
    I2C_Send_Data(I2C_x, Memory_Address >> 8, I2C_POLLING_ENABLE);
    I2C_Send_Data(I2C_x, Memory_Address, I2C_POLLING_ENABLE);
    uint8_t i;
    for (i = 0; i < Length; i++)
    {
        I2C_Send_Data(I2C_x, *(Data + i), I2C_POLLING_ENABLE);
    }
    I2C_Send_Stop_Condition(I2C_x);
}

/**
 * @brief Read N-Bytes From EEPROM
 *
 * @param Memory_Address : Memory Address in EEPROM
 * @param Data : Pointer to data to Read from EEPROM to it
 * @param Length : The Data Length of the data to read it
 */
void EEPROM_Read_N_Data(uint16_t Memory_Address, uint8_t *Data, uint8_t Length)
{
    uint32_t status;
    I2C_Send_Start_Condition(I2C_x, I2C_POLLING_ENABLE);
    I2C_Send_Address(I2C_x, EEPROM_ADDRESS, I2C_DIRECTION_WRITE, I2C_POLLING_ENABLE);
    I2C_Send_Data(I2C_x, Memory_Address >> 8, I2C_POLLING_ENABLE);
    I2C_Send_Data(I2C_x, Memory_Address, I2C_POLLING_ENABLE);
    /*
    do
    {
        status = I2C_Get_Status();
    } while (status & (1 << 7));
    */
    I2C_Send_Start_Condition(I2C_x, I2C_POLLING_ENABLE);
    I2C_Set_Acknowledge(I2C_x ,I2C_ACKNOWLEDGE_ENABLE);
    I2C_Send_Address(I2C_x, EEPROM_ADDRESS, I2C_DIRECTION_READ, I2C_POLLING_ENABLE);
    uint8_t i;
    for (i = 0; i < Length; i++)
    {
        if(!(i < (Length - 1)))
        {
            I2C_Set_Acknowledge(I2C_x, I2C_ACKNOWLEDGE_DISABLE);
        }
        *(Data + i) = I2C_Receive_Data(I2C_x, I2C_POLLING_ENABLE);
    }
    I2C_Send_Stop_Condition(I2C_x);
}