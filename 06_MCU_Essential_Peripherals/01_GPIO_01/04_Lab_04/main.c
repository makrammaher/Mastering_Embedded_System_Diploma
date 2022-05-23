/*
 *           File: main.c
 *     Created on: Saturday 21/05/2022 14:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 Multiplixing Seven Segmant
 *
 *
 */
#include <stdint.h>

#define BASE   0x20

#define PINC        *((volatile uint8_t*)(BASE + 0x13))
#define DDRC        *((volatile uint8_t*)(BASE + 0x14))
#define PORTC       *((volatile uint8_t*)(BASE + 0x15))

#define SETBIT(REG,N)       (REG |= (1 << N))
#define CLEARBIT(REG,N)     (REG &=~(1 << N))
#define TOGGLEBIT(REG,N)    (REG ^= (1 << N))


void init_GPIO(void);
void wait_ms(uint8_t time);


int main(void)
{
    uint8_t i , j, ms;
    init_GPIO();
    while (1)
    {
        /* Tenth */

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                for (ms = 0; ms < 60; ms++)
                {
                    PORTC = (0b1011 | (i << 4));
                    wait_ms(4);
                    PORTC = (0b0111 | (j << 4));
                    wait_ms(4);
                }
            }
        }
    }
}

void init_GPIO(void)
{
    /* Set GPIO PINS of _PORTA (PIN0 - PIN1 - PIN2) */
    DDRC |= (1 << 2);
    DDRC |= (1 << 3);
    DDRC |= (1 << 4);
    DDRC |= (1 << 5);
    DDRC |= (1 << 6);
    DDRC |= (1 << 7);
    /* Initialize them with zero */
    PINC &= ~(1 << 2);
    PINC &= ~(1 << 3);
    PINC &= ~(1 << 4);
    PINC &= ~(1 << 5);
    PINC &= ~(1 << 6);
    PINC &= ~(1 << 7);

}

void wait_ms(uint8_t time)
{
    uint8_t i, j;
    for (i = 0; i < time; i++)
    {
        for (j = 0; j < 255; j++);
    }
}