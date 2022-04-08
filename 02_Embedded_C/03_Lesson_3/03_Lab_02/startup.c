/*
 *           File: startup.c
 *     Created on: Thursday 07/04/2022 19:09
 *         Author: Makram Maher Makram
 *        Subject: Testing Makefile
 *
 *
 */

#include <stdint.h>


void Reset_handler(void);
void Default_handler(void);

void NMI_handler(void)          __attribute__((weak, alias("Default_handler")));
void HardFault_handler(void)    __attribute__((weak, alias("Default_handler")));
void MMFault_handler(void)      __attribute__((weak, alias("Default_handler")));
void BusFault_handler(void)     __attribute__((weak, alias("Default_handler")));
void UsageFault_handler(void)   __attribute__((weak, alias("Default_handler")));
void Reserved1_handler(void)    __attribute__((weak, alias("Default_handler")));
void Reserved2_handler(void)    __attribute__((weak, alias("Default_handler")));
void Reserved3_handler(void)    __attribute__((weak, alias("Default_handler")));
void Reserved4_handler(void)    __attribute__((weak, alias("Default_handler")));
/* and so on --> */

extern const uint32_t _STACK_TOP;

/* __attribute__((section(".vectors"))) tell the compiler that this array will be in (.vectors) Sections */
uint32_t vectors[20] __attribute__((section(".vectors"))) = 
{
    (uint32_t) &_STACK_TOP,
    (uint32_t) Reset_handler,
    (uint32_t) NMI_handler,
    (uint32_t) HardFault_handler,
    (uint32_t) MMFault_handler,
    (uint32_t) BusFault_handler,
    (uint32_t) UsageFault_handler,
    (uint32_t) Reserved1_handler,
    (uint32_t) Reserved2_handler,
    (uint32_t) Reserved3_handler,
    (uint32_t) Reserved4_handler
};

extern const uint32_t _E_TEXT;
extern const uint32_t _S_DATA;
extern const uint32_t _E_DATA;
extern const uint32_t _S_BSS;
extern const uint32_t _E_BSS;

void Reset_handler(void)
{
    uint32_t i;
    uint32_t DATA_SIZE = (uint8_t*)&_E_DATA - (uint8_t*)&_S_DATA;
    
    uint8_t* p_src = (uint8_t*)&_E_TEXT;
    uint8_t* p_dst = (uint8_t*)&_S_DATA;

    /* Copy .data Section From FLASH To SRAM */
    for(i = 0;i<DATA_SIZE;i++)
    {
        *((uint8_t*)p_dst++) = *((uint8_t*)p_src++);
    }

    /* Initialize .bss Section in SRAM by 0 (ZeroS) */
    uint32_t BSS_SIZE = (uint8_t*)&_E_BSS - (uint8_t*)&_S_BSS;
    p_dst = (uint8_t*)&_S_BSS;
    for(i = 0;i<BSS_SIZE;i++)
    {
        *((uint8_t*)p_dst++) = (uint8_t)0;
    }

    /* Jumb Main () */
    main();
}

void Default_handler(void)
{
    Reset_handler();
}