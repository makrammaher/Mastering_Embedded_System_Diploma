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
                                                 {'?', '0', '=', '+'}
};

uint8_t keypad_rows[KEYPAD_ROWS] = {KEYPAD_R0_PIN, KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN};
uint8_t keypad_columns[KEYPAD_COLUMNS] = {KEYPAD_C0_PIN, KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN};

void keypad_init(void)
{
    /* Set rows pin as pullup input in MCU */
    CLEARBIT(KEYPAD_DDR, KEYPAD_R0_PIN);
    CLEARBIT(KEYPAD_DDR, KEYPAD_R1_PIN);
    CLEARBIT(KEYPAD_DDR, KEYPAD_R2_PIN);
    CLEARBIT(KEYPAD_DDR, KEYPAD_R3_PIN);
    SETBIT(KEYPAD_PORT, KEYPAD_R0_PIN);
    SETBIT(KEYPAD_PORT, KEYPAD_R1_PIN);
    SETBIT(KEYPAD_PORT, KEYPAD_R2_PIN);
    SETBIT(KEYPAD_PORT, KEYPAD_R3_PIN);

    /* Set column as an output and init it by ones */
    SETBIT(KEYPAD_DDR, KEYPAD_C0_PIN);
    SETBIT(KEYPAD_DDR, KEYPAD_C1_PIN);
    SETBIT(KEYPAD_DDR, KEYPAD_C2_PIN);
    SETBIT(KEYPAD_DDR, KEYPAD_C3_PIN);
    SETBIT(KEYPAD_PORT, KEYPAD_C0_PIN);
    SETBIT(KEYPAD_PORT, KEYPAD_C1_PIN);
    SETBIT(KEYPAD_PORT, KEYPAD_C2_PIN);
    SETBIT(KEYPAD_PORT, KEYPAD_C3_PIN);
}
char keypad_getkey(void)
{
    static uint8_t keyPressed = 0;
    uint8_t counter = 0;
    uint8_t row, column;
    char key = 0;
    for (column = 0; column < KEYPAD_COLUMNS; column++)
    {
        SETBIT(KEYPAD_PORT, KEYPAD_C0_PIN);
        SETBIT(KEYPAD_PORT, KEYPAD_C1_PIN);
        SETBIT(KEYPAD_PORT, KEYPAD_C2_PIN);
        SETBIT(KEYPAD_PORT, KEYPAD_C3_PIN);

        CLEARBIT(KEYPAD_PORT, keypad_columns[column]);
        for (row = 0; row < KEYPAD_ROWS; row++)
        {
            if ((KEYPAD_PIN & (1 << keypad_rows[row])) == 0)
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