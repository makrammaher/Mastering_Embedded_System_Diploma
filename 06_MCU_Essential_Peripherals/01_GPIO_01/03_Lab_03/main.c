/*
 *           File: main.c
 *     Created on: Saturday 21/05/2022 14:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 MCU Interrupts
 *
 *
 */
#include <stdint.h>

#define BASE   0x20

#define PIND        *((volatile uint8_t*)(BASE + 0x10))
#define DDRD        *((volatile uint8_t*)(BASE + 0x11))
#define PORTD       *((volatile uint8_t*)(BASE + 0x12))



void init_GPIO(void);
void wait_ms(uint8_t time);


int main(void)
{
    uint8_t i = 1;
    uint8_t flag = 0;
    init_GPIO();
    while (1)
    {
        if ((PIND & 0x01) > 0)
        {

            if (flag == 0)
            {
                PORTD &= ~ (0xf << 4);
                PORTD |= (1 << (i + 4));
                if (i > 2)
                    i = 0;
                else
                    i++;
                flag = 1;
            }

        }
        else
        {
            flag = 0;
        }
    }
}

void init_GPIO(void)
{
    /* Set GPIO PINS of _PORTA (PIN0 - PIN1 - PIN2) */
    DDRD |= (1 << 4);
    DDRD |= (1 << 5);
    DDRD |= (1 << 6);
    DDRD |= (1 << 7);
    DDRD &= ~(1 << 0);
    /* Initialize them with zero */
    PORTD &= ~ (1 << 4);
    PORTD &= ~ (1 << 5);
    PORTD &= ~ (1 << 6);
    PORTD &= ~ (1 << 7);
}

void wait_ms(uint8_t time)
{
    uint8_t i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 255; j++);
    }
}