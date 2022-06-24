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
#define F_CPU   8000000UL

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

#define SREG        *((volatile uint8_t*)(BASE + 0x3F))
#define MCUCR       *((volatile uint8_t*)(BASE + 0x35))
#define MCUCSR      *((volatile uint8_t*)(BASE + 0x34))
#define GICR        *((volatile uint8_t*)(BASE + 0x3B))
#define GIFR        *((volatile uint8_t*)(BASE + 0x3A))

#define UDR         *((volatile uint8_t*)(BASE + 0x0C))
#define UCSRA       *((volatile uint8_t*)(BASE + 0x0B))
#define UCSRB       *((volatile uint8_t*)(BASE + 0x0A))
#define UBRRL       *((volatile uint8_t*)(BASE + 0x09))
#define UCSRC       (*((volatile uint8_t*)(BASE + 0x20)) |= 0x80);\
                    *((volatile uint8_t*)(BASE + 0x20))
#define UBRRH       (*((volatile uint8_t*)(BASE + 0x20)) &= 0x7F);\
                    *((volatile uint8_t*)(BASE + 0x20))

#define SPCR        *((volatile uint8_t*)(BASE + 0x0D))
#define SPSR        *((volatile uint8_t*)(BASE + 0x0E))
#define SPDR        *((volatile uint8_t*)(BASE + 0x0F))

#define SETBIT(REG,N)       (REG |= (1 << (N)))
#define CLEARBIT(REG,N)     (REG &=~(1 << (N)))
#define TOGGLEBIT(REG,N)    (REG ^= (1 << (N)))

#endif