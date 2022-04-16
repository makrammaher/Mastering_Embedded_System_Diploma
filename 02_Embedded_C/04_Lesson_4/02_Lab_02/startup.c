/*
 *           File: startup.c
 *     Created on: Friday 15/04/2022 23:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx Toggle P13 LED
 *
 *
 */
#include<stdint.h>

/* main Prototype */
int main(void);

void reset_handler(void);
void default_handler(void);
void NMI_handler(void) 			__attribute__((weak, alias("default_handler")));
void hardFault_handler(void) 	__attribute__((weak, alias("default_handler")));
void MM_handler(void)			__attribute__((weak, alias("default_handler")));
void busFault_handler(void)		__attribute__((weak, alias("default_handler")));
void usageFault_handler(void)	__attribute__((weak, alias("default_handler")));


/* Stack 256 * 4 = 1024 BYTE */
static uint32_t Stack[256] __attribute__((section(".stack")));

void(* const g_p_Vectors[])(void) __attribute__((section(".vectors"))) =
{
	(void(* const)(void)) ((uint32_t)Stack + sizeof(Stack)),
	&reset_handler,
	&NMI_handler,
	&hardFault_handler,
	&MM_handler,
	&busFault_handler,
	&usageFault_handler
};


extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;


void reset_handler(void)
{
	/* Copy .data section from flash to sram */
	uint8_t * ptr_src = (uint8_t*)&_E_TEXT;
	uint8_t * ptr_dst = (uint8_t*)&_S_DATA;
	uint32_t size = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
	uint32_t i;
	for (i = 0; i < size; i++)
	{
		*((uint8_t*)ptr_dst++) = *((uint8_t*)ptr_src++);
	}

	/* initialize .bss section */
	ptr_dst = (uint8_t*)&_S_BSS;
	size = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS;
	for (i = 0; i < size; i++)
	{
		*((uint8_t*)ptr_dst++) = (uint8_t)0;
	}

	/* Jumb to main() */
	main();
}

void default_handler(void)
{
	reset_handler();
}