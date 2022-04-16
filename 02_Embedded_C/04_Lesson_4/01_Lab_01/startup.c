/*
 *           File: startup.c
 *     Created on: Tuesday 12/04/2022 13:09
 *         Author: Makram Maher Makram
 *        Subject: Tiva-c Toggle Green LED
 *
 *
 */
#include<stdint.h>

/* Prototype of main function */
int main(void);

void _reset_handler(void);
void _default_handler(void);

void _NMI_handler(void)         __attribute__((weak, alias("_default_handler")));
void _Hard_fault_handler(void)  __attribute__((weak, alias("_default_handler")));
void _MM_fault_handler(void)    __attribute__((weak, alias("_default_handler")));
void _BUS_fault_handler(void)   __attribute__((weak, alias("_default_handler")));
void _Usage_fault_handler(void) __attribute__((weak, alias("_default_handler")));
/* .
 * .
 * .    rest of vector table
 * .
 */


/* Global uninitialized variable --> .bss (Section) */
static uint32_t Stack[256] __attribute__((section(".stack"))); /* 256 * 4 = 1024 Byte = 1KB stack size */

void(* const g_p_Vectors[])(void) __attribute__((section(".vectors"))) =
{
    (void (*const)(void)) ((uint32_t)Stack + sizeof(Stack)),
    &_reset_handler,
    &_NMI_handler,
    &_Hard_fault_handler,
    &_MM_fault_handler,
    &_BUS_fault_handler,
    &_Usage_fault_handler
};

extern uint32_t _E_TEXT;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

void _reset_handler(void)
{
    /* Copy .data Section from FLASH to SRAM */
    uint32_t i;
    uint32_t DATA_SIZE = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
    uint8_t *ptr_src = (uint8_t*)&_E_TEXT;
    uint8_t *ptr_dst = (uint8_t*)&_S_DATA;
    for (i = 0; i < DATA_SIZE; i++)
    {
        *((uint8_t*) ptr_dst++) = *((uint8_t*) ptr_src++);
    }

    /* Initialize .bss Section in SRAM */
    uint32_t BSS_SIZE = (uint8_t*)& _E_BSS - (uint8_t*)& _S_BSS;
		
    ptr_dst = (uint8_t*)&_S_BSS;
    for (i = 0; i < BSS_SIZE; i++)
    {
        *((uint8_t*) ptr_dst++) = (uint8_t)0;
    }

    /* Jumb to main() function */
    main();
}


void _default_handler(void)
{
    _reset_handler();
}
