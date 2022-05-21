/*
 *           File: main.c
 *     Created on: Saturday 21/05/2022 14:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 MCU Interrupts
 *
 *
 */

#include <avr/interrupt.h>

#define BASE   0x20

#define _PINA        *((volatile uint8_t*)(BASE + 0x19))
#define _DDRA        *((volatile uint8_t*)(BASE + 0x1A))
#define _PORTA       *((volatile uint8_t*)(BASE + 0x1B))

#define _MCUCR       *((volatile uint8_t*)(BASE + 0x35))
#define _MCUCSR      *((volatile uint8_t*)(BASE + 0x34))
#define _GICR        *((volatile uint8_t*)(BASE + 0x3B))
#define _GIFR        *((volatile uint8_t*)(BASE + 0x3A))
#define _SREG        *((volatile uint8_t*)(BASE + 0x3F))

void init_EINT(void);
void init_GPIO(void);

#define DELAY       20000
uint32_t I0,I1,I2;

int main(void)
{
    init_GPIO();
    init_EINT();
    while(1)
    {
        if(_PORTA & (1<<0))
        {
            I0--;
            if(I0 == 0)
                _PORTA &=~ (1<<0);
        }
        if(_PORTA & (1<<1))
        {
            I1--;
            if(I1 == 0)
                _PORTA &=~ (1<<1);
        }
        if(_PORTA & (1<<2))
        {
            I2--;
            if(I2 == 0)
                _PORTA &=~ (1<<2);
        }
    }
}

ISR(INT0_vect)
{
    _PORTA |= (1<<0);
    I0 = DELAY;
    /* Clear Flag */
    _GIFR |= (1<<6);
}

ISR(INT1_vect)
{
    _PORTA |= (1<<1);
    I1 = DELAY;
    /* Clear Flag */
    _GIFR |= (1<<7);
}

ISR(INT2_vect)
{
    _PORTA |= (1<<2);
    I2 = DELAY;
    /* Clear Flag */
    _GIFR |= (1<<5);
}

void init_EINT(void)
{
    /* The rising edge of INT0 generates an interrupt request */
    _MCUCR |= (1<<0);
    _MCUCR |= (1<<1);

    /* Any logical change on INT1 generates an interrupt request */
    _MCUCR |= (1<<2);
    _MCUCR &=~ (1<<3);

    /* The falling edge on INT2 generates an interrupt request */
    _MCUCSR &=~ (1<<6);

    /* Enable EINT0 EINT1 EINT2 */
    _GICR |= (1<<6);
    _GICR |= (1<<7);
    _GICR |= (1<<5);

    /* Enable Global Interrupt */
    _SREG |= (1<<7);
}

void init_GPIO(void)
{
    /* Set GPIO PINS of _PORTA (PIN0 - PIN1 - PIN2) */
    _DDRA |= (1<<0);
    _DDRA |= (1<<1);
    _DDRA |= (1<<2);
    /* Initialize them with zero */
    _PORTA &=~ (1<<0);
    _PORTA &=~ (1<<1);
    _PORTA &=~ (1<<2);
}