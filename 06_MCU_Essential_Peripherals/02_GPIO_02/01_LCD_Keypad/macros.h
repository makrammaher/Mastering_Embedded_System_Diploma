/*
 *           File: macros.h
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 LCD and Keypad
 *
 *
 */

#ifndef _MACROS_H_
#define _MACROS_H_

#include <stdint.h>

#define BASE   0x20

#define PINA        *((volatile uint8_t*)(BASE + 0x19))
#define DDRA        *((volatile uint8_t*)(BASE + 0x1A))
#define PORTA       *((volatile uint8_t*)(BASE + 0x1B))

#define PINB        *((volatile uint8_t*)(BASE + 0x16))
#define DDRB        *((volatile uint8_t*)(BASE + 0x17))
#define PORTB       *((volatile uint8_t*)(BASE + 0x18))

#define PINC        *((volatile uint8_t*)(BASE + 0x13))
#define DDRC        *((volatile uint8_t*)(BASE + 0x14))
#define PORTC       *((volatile uint8_t*)(BASE + 0x15))

#define PIND        *((volatile uint8_t*)(BASE + 0x10))
#define DDRD        *((volatile uint8_t*)(BASE + 0x11))
#define PORTD       *((volatile uint8_t*)(BASE + 0x12))

#define SETBIT(REG,N)       (REG |= (1 << (N)))
#define CLEARBIT(REG,N)     (REG &=~(1 << (N)))
#define TOGGLEBIT(REG,N)    (REG ^= (1 << (N)))


#endif