/*
 *           File: keypad.c
 *     Created on: Tuesday 31/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: Keypad Driver HAL Layer
 *
 *
 */

#include "keypad.h"

char keypad_keys[KEYPAD_ROWS][KEYPAD_COLUMNS] = {{'7', '8', '9', '/'},
                                                 {'4', '5', '6', '*'},
                                                 {'1', '2', '3', '-'},
                                                 {'?', '0', '=', '+'}};

uint16_t keypad_rows[KEYPAD_ROWS] = {KEYPAD_R0_PIN, KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN};
uint16_t keypad_columns[KEYPAD_COLUMNS] = {KEYPAD_C0_PIN, KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN};

void keypad_init(void)
{
    /* Set rows pin as pullup input in MCU */
    GPIO_Init(KEYPAD_GPIO, GPIO_MODE_INPUT_PU, KEYPAD_R0_PIN);
    GPIO_Init(KEYPAD_GPIO, GPIO_MODE_INPUT_PU, KEYPAD_R1_PIN);
    GPIO_Init(KEYPAD_GPIO, GPIO_MODE_INPUT_PU, KEYPAD_R2_PIN);
    GPIO_Init(KEYPAD_GPIO, GPIO_MODE_INPUT_PU, KEYPAD_R3_PIN);

    /* Set column as an output and init it by ones */
    GPIO_Init(KEYPAD_GPIO, GPIO_MODE_OUTPUT_OD_10MHZ, KEYPAD_C0_PIN);
    GPIO_Init(KEYPAD_GPIO, GPIO_MODE_OUTPUT_OD_10MHZ, KEYPAD_C1_PIN);
    GPIO_Init(KEYPAD_GPIO, GPIO_MODE_OUTPUT_OD_10MHZ, KEYPAD_C2_PIN);
    GPIO_Init(KEYPAD_GPIO, GPIO_MODE_OUTPUT_OD_10MHZ, KEYPAD_C3_PIN);
    GPIO_Write_Pin(KEYPAD_GPIO, KEYPAD_C0_PIN, GPIO_PIN_SET);
    GPIO_Write_Pin(KEYPAD_GPIO, KEYPAD_C1_PIN, GPIO_PIN_SET);
    GPIO_Write_Pin(KEYPAD_GPIO, KEYPAD_C2_PIN, GPIO_PIN_SET);
    GPIO_Write_Pin(KEYPAD_GPIO, KEYPAD_C3_PIN, GPIO_PIN_SET);
}

char keypad_getkey(void)
{
    static uint8_t keyPressed = 0;
    uint8_t counter = 0;
    uint8_t row, column;
    char key = 0;
    for (column = 0; column < KEYPAD_COLUMNS; column++)
    {
        GPIO_Write_Pin(KEYPAD_GPIO, keypad_columns[column], GPIO_PIN_RESET);
        uint8_t i;
        for(i=0;i<200;i++);
        for (row = 0; row < KEYPAD_ROWS; row++)
        {
            uint16_t tempReg = GPIO_Read_Port(KEYPAD_GPIO);
            if ((tempReg & ((uint16_t)keypad_rows[row])) == 0)
            {
                counter++;
                if (keyPressed == 0)
                {
                    /* There is a key presed */
                    key = keypad_keys[row][column];
                    keyPressed = 1;
                }
            }
        }
        GPIO_Write_Pin(KEYPAD_GPIO, KEYPAD_C0_PIN, GPIO_PIN_SET);
        GPIO_Write_Pin(KEYPAD_GPIO, KEYPAD_C1_PIN, GPIO_PIN_SET);
        GPIO_Write_Pin(KEYPAD_GPIO, KEYPAD_C2_PIN, GPIO_PIN_SET);
        GPIO_Write_Pin(KEYPAD_GPIO, KEYPAD_C3_PIN, GPIO_PIN_SET);
    }
    if (counter == 0)
    {
        keyPressed = 0;
    }
    return key;
}