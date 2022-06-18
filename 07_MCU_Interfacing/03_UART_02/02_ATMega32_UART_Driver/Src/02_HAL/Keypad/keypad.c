/*
 *           File: keypad.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 LCD and Keypad
 *
 *
 */

#include "keypad.h"

char keypad_keys[KEYPAD_ROWS][KEYPAD_COLUMNS] = {{'7', '8', '9', '/'},
                                                 {'4', '5', '6', '*'},
                                                 {'1', '2', '3', '-'},
                                                 {'?', '0', '=', '+'}};

uint8_t keypad_rows[KEYPAD_ROWS] = {KEYPAD_R0_PIN, KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN};
uint8_t keypad_columns[KEYPAD_COLUMNS] = {KEYPAD_C0_PIN, KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN};

void keypad_init(void)
{
    /* Set rows pin as pullup input in MCU */
    GPIO_Init(KEYPAD_GPIOx, GPIO_MODE_INPUT_PULL_UP, KEYPAD_R0_PIN);
    GPIO_Init(KEYPAD_GPIOx, GPIO_MODE_INPUT_PULL_UP, KEYPAD_R1_PIN);
    GPIO_Init(KEYPAD_GPIOx, GPIO_MODE_INPUT_PULL_UP, KEYPAD_R2_PIN);
    GPIO_Init(KEYPAD_GPIOx, GPIO_MODE_INPUT_PULL_UP, KEYPAD_R3_PIN);

    /* Set column as an output and init it by ones */
    GPIO_Init(KEYPAD_GPIOx, GPIO_MODE_OUTPUT, KEYPAD_C0_PIN);
    GPIO_Init(KEYPAD_GPIOx, GPIO_MODE_OUTPUT, KEYPAD_C1_PIN);
    GPIO_Init(KEYPAD_GPIOx, GPIO_MODE_OUTPUT, KEYPAD_C2_PIN);
    GPIO_Init(KEYPAD_GPIOx, GPIO_MODE_OUTPUT, KEYPAD_C3_PIN);
    GPIO_Write_Pin(KEYPAD_GPIOx, KEYPAD_C0_PIN, GPIO_PIN_HIGH);
    GPIO_Write_Pin(KEYPAD_GPIOx, KEYPAD_C1_PIN, GPIO_PIN_HIGH);
    GPIO_Write_Pin(KEYPAD_GPIOx, KEYPAD_C2_PIN, GPIO_PIN_HIGH);
    GPIO_Write_Pin(KEYPAD_GPIOx, KEYPAD_C3_PIN, GPIO_PIN_HIGH);
}
char keypad_getkey(void)
{
    static uint8_t keyPressed = 0;
    uint8_t counter = 0;
    uint8_t row, column;
    char key = 0;
    for (column = 0; column < KEYPAD_COLUMNS; column++)
    {
        GPIO_Write_Pin(KEYPAD_GPIOx, KEYPAD_C0_PIN, GPIO_PIN_HIGH);
        GPIO_Write_Pin(KEYPAD_GPIOx, KEYPAD_C1_PIN, GPIO_PIN_HIGH);
        GPIO_Write_Pin(KEYPAD_GPIOx, KEYPAD_C2_PIN, GPIO_PIN_HIGH);
        GPIO_Write_Pin(KEYPAD_GPIOx, KEYPAD_C3_PIN, GPIO_PIN_HIGH);

        GPIO_Write_Pin(KEYPAD_GPIOx,  keypad_columns[column], GPIO_PIN_LOW);
        for (row = 0; row < KEYPAD_ROWS; row++)
        {
            if (GPIO_Read_Pin(KEYPAD_GPIOx, keypad_rows[row]) == GPIO_PIN_LOW)
            {
                counter++;
                if (keyPressed == 0)
                {
                    /* There is a key presed */
                    key = keypad_keys[row][column];
                    keyPressed = 1;
                }
                break;
            }
        }
    }
    if (counter == 0)
    {
        keyPressed = 0;
    }
    return key;
}