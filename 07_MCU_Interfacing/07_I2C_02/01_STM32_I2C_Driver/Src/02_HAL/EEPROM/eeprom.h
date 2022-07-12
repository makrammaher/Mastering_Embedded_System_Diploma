/*
 *           File: eeprom.h
 *     Created on: Saturday 09/07/2022 02:38
 *         Author: Makram Maher Makram
 *        Subject: EEPROM Driver Using Polling
 *
 *
 */

#ifndef _EEPROM_H_
#define _EEPROM_H_

#include "stm32f103c6.h"
#include "stm32f103c6-i2c.h"

#define EEPROM_ADDRESS      0x2A

/**
 * @brief Initialize EEPROM
 * 
 * @param I2Cx : I2C1, I2C2
 */
void EEPROM_Init(I2Cx_t *I2Cx);

/**
 * @brief Write N-Bytes To EEPROM
 * 
 * @param Memory_Address : Memory Address in EEPROM
 * @param Data : Pointer to data to be Written in EEPROM
 * @param Length : The Data Length of the Data to be Written
 */
void EEPROM_Write_N_Data(uint16_t Memory_Address, uint8_t *Data, uint8_t Length);

/**
 * @brief Read N-Bytes From EEPROM
 * 
 * @param Memory_Address : Memory Address in EEPROM
 * @param Data : Pointer to data to Read from EEPROM to it
 * @param Length : The Data Length of the data to read it
 */
void EEPROM_Read_N_Data(uint16_t Memory_Address, uint8_t *Data, uint8_t Length);

#endif