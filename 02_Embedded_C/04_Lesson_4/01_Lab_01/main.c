/*
 *           File: main.c
 *     Created on: Tuesday 12/04/2022 13:09
 *         Author: Makram Maher Makram
 *        Subject: Tiva-c Toggle Green LED
 *
 *
 */

#include<stdint.h>

#define SYSCTL_RCGC2		*((uint32_t*)(0x400FE108))
#define GPIO_PORTF_DIR		*((uint32_t*)(0x40025400))
#define GPIO_PORTF_DEN		*((uint32_t*)(0x4002551C))
#define GPIO_PORTF_DATA		*((uint32_t*)(0x400253FC))

int main(void)
{

	uint32_t i;
	SYSCTL_RCGC2 = 0x20;
	for (i = 0; i < 20000; i++);
	GPIO_PORTF_DIR |= (1 << 3);
	GPIO_PORTF_DEN |= (1 << 3);

	while (1)
	{

		GPIO_PORTF_DATA = 0x00000008;
		for (i = 0; i < 20000; i++);
		GPIO_PORTF_DATA = 0;
		for (i = 0; i < 20000; i++);
	}

}
