/*
 *           File: startup.c
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */
#include <stdint.h>
/* main Prototype */
int main(void);

void reset_handler(void);
void default_handler(void);
void NMI_handler(void)          __attribute__((weak, alias("default_handler")));
void hardFault_handler(void)    __attribute__((weak, alias("default_handler")));
void MM_handler(void)           __attribute__((weak, alias("default_handler")));
void busFault_handler(void)     __attribute__((weak, alias("default_handler")));
void usageFault_handler(void)   __attribute__((weak, alias("default_handler")));
void reserved_handler(void)     __attribute__((weak, alias("default_handler")));
void SVCall_handler(void)       __attribute__((weak, alias("default_handler")));
void debugMonitor_handler(void) __attribute__((weak, alias("default_handler")));
void PendSV_handler(void)       __attribute__((weak, alias("default_handler")));
void SysTick_handler(void)      __attribute__((weak, alias("default_handler")));
void WWDG_handler(void)         __attribute__((weak, alias("default_handler")));
void PVD_handler(void)          __attribute__((weak, alias("default_handler")));
void TAMPER_handler(void)       __attribute__((weak, alias("default_handler")));
void RTC_handler(void)          __attribute__((weak, alias("default_handler")));
void FLASH_handler(void)        __attribute__((weak, alias("default_handler")));
void RCC_handler(void)          __attribute__((weak, alias("default_handler")));
void EXTI0_handler(void)        __attribute__((weak, alias("default_handler")));
void EXTI1_handler(void)        __attribute__((weak, alias("default_handler")));
void EXTI2_handler(void)        __attribute__((weak, alias("default_handler")));
void EXTI3_handler(void)        __attribute__((weak, alias("default_handler")));
void EXTI4_handler(void)        __attribute__((weak, alias("default_handler")));


/* Stack 256 * 4 = 1024 BYTE */
static uint32_t Stack[256] __attribute__((section(".stack")));

void(* const g_p_Vectors[])(void) __attribute__((section(".vectors"))) =
{
    (void(*const)(void)) ((uint8_t*)Stack + sizeof(Stack)),
    &reset_handler,
    &NMI_handler,
    &hardFault_handler,
    &MM_handler,
    &busFault_handler,
    &usageFault_handler,
    &reserved_handler,
    &reserved_handler,
    &reserved_handler,
    &reserved_handler,
    &SVCall_handler,
    &debugMonitor_handler,
    &reserved_handler,
    &PendSV_handler,
    &SysTick_handler,
    &WWDG_handler,
    &PVD_handler,
    &TAMPER_handler,
    &RTC_handler,
    &FLASH_handler,
    &RCC_handler,
    &EXTI0_handler,
    &EXTI1_handler,
    &EXTI2_handler,
    &EXTI3_handler,
    &EXTI4_handler
};


extern uint32_t _E_TEXT_;
extern uint32_t _S_DATA_;
extern uint32_t _E_DATA_;
extern uint32_t _S_BSS_;
extern uint32_t _E_BSS_;


void reset_handler(void)
{
    /*copy .data sections from flash to sram*/
    uint8_t* ptr_src = (uint8_t*) &_E_TEXT_;
    uint8_t* ptr_dst = (uint8_t*) &_S_DATA_;
    uint32_t size = (uint8_t*) &_E_DATA_ - (uint8_t*) &_S_DATA_;
    uint32_t i;
    for (i = 0; i < size; i++)
    {
        *((uint8_t*)ptr_dst++) = *((uint8_t*)ptr_src++);
    }

    /*initialize .bss section in sram */
    ptr_dst = (uint8_t*) &_S_BSS_;
    size = (uint8_t*) &_E_BSS_ - (uint8_t*) &_S_BSS_;
    for (i = 0; i < size; i++)
    {
        *((uint8_t*)ptr_dst++) = (uint8_t)0;
    }

    /* Jump to main function */
    main();
}

void default_handler(void)
{
    reset_handler();
}