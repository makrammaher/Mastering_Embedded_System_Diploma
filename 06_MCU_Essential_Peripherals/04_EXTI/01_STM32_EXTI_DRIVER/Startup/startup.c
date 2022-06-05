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
void DMA1_C1_handler(void)      __attribute__((weak, alias("default_handler")));
void DMA1_C2_handler(void)      __attribute__((weak, alias("default_handler")));
void DMA1_C3_handler(void)      __attribute__((weak, alias("default_handler")));
void DMA1_C4_handler(void)      __attribute__((weak, alias("default_handler")));
void DMA1_C5_handler(void)      __attribute__((weak, alias("default_handler")));
void DMA1_C6_handler(void)      __attribute__((weak, alias("default_handler")));
void DMA1_C7_handler(void)      __attribute__((weak, alias("default_handler")));
void ADC1_2_handler(void)       __attribute__((weak, alias("default_handler")));
void CAN1_TX_handler(void)      __attribute__((weak, alias("default_handler")));
void CAN1_RX0_handler(void)     __attribute__((weak, alias("default_handler")));
void CAN1_RX1_handler(void)     __attribute__((weak, alias("default_handler")));
void CAN1_SCE_handler(void)     __attribute__((weak, alias("default_handler")));
void EXTI5_9_handler(void)      __attribute__((weak, alias("default_handler")));
void TIM1_BRK_handler(void)     __attribute__((weak, alias("default_handler")));
void TIM1_UP_handler(void)      __attribute__((weak, alias("default_handler")));
void TIM1_TRG_COM_handler(void) __attribute__((weak, alias("default_handler")));
void TIM1_CC_handler(void)      __attribute__((weak, alias("default_handler")));
void TIM2_handler(void)         __attribute__((weak, alias("default_handler")));
void TIM3_handler(void)         __attribute__((weak, alias("default_handler")));
void TIM4_handler(void)         __attribute__((weak, alias("default_handler")));
void I2C1_EV_handler(void)      __attribute__((weak, alias("default_handler")));
void I2C1_ER_handler(void)      __attribute__((weak, alias("default_handler")));
void I2C2_EV_handler(void)      __attribute__((weak, alias("default_handler")));
void I2C2_ER_handler(void)      __attribute__((weak, alias("default_handler")));
void SPI1_handler(void)         __attribute__((weak, alias("default_handler")));
void SPI2_handler(void)         __attribute__((weak, alias("default_handler")));
void USART1_handler(void)       __attribute__((weak, alias("default_handler")));
void USART2_handler(void)       __attribute__((weak, alias("default_handler")));
void USART3_handler(void)       __attribute__((weak, alias("default_handler")));
void EXTI10_15_handler(void)    __attribute__((weak, alias("default_handler")));
void RTCAlarm_handler(void)     __attribute__((weak, alias("default_handler")));
void OTG_FS_WKUP_handler(void)  __attribute__((weak, alias("default_handler")));



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
    &EXTI4_handler,
    &DMA1_C1_handler,
    &DMA1_C2_handler,
    &DMA1_C3_handler,
    &DMA1_C4_handler,
    &DMA1_C5_handler,
    &DMA1_C6_handler,
    &DMA1_C7_handler,
    &ADC1_2_handler,
    &CAN1_TX_handler,
    &CAN1_RX0_handler,
    &CAN1_RX1_handler,
    &CAN1_SCE_handler,
    &EXTI5_9_handler,
    &TIM1_BRK_handler,
    &TIM1_UP_handler,
    &TIM1_TRG_COM_handler,
    &TIM1_CC_handler,
    &TIM2_handler,
    &TIM3_handler,
    &TIM4_handler,
    &I2C1_EV_handler,
    &I2C1_ER_handler,
    &I2C2_EV_handler,
    &I2C2_ER_handler,
    &SPI1_handler,
    &SPI2_handler,
    &USART1_handler,
    &USART2_handler,
    &USART3_handler,
    &EXTI10_15_handler,
    &RTCAlarm_handler,
    &OTG_FS_WKUP_handler,
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