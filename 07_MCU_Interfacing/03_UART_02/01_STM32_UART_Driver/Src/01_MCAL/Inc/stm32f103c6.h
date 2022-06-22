/*
 *           File: stm32f103c6.h
 *     Created on: Monday 30/05/2022 19:43
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 MCU Header
 *
 *
 */

#ifndef _STM32F103C6_H_
#define _STM32F103C6_H_

/* ======================= Includes ====================== */
#include <stdint.h>
/* ======================================================= */


/* ===================== Basic Macros ==================== */
#define SET_BIT(REG,N)       (REG |= (1 << (N)))
#define CLEAR_BIT(REG,N)     (REG &=~(1 << (N)))
#define TOGGLE_BIT(REG,N)    (REG ^= (1 << (N)))
/* ======================================================= */


/* ============= Base Addresses For Memories ============= */
#define FLASH_MEM_BASE              0x08000000
#define SYSTEM_MEM_BASE             0x1FFFF000
#define SRAM_MEM_BASE               0x20000000
#define PERIPHERALS_BASE            0x40000000
#define CORTEX_M3_PERIPHERALS_BASE  0x0E000000
/* ======================================================= */


/* ========================= NVIC ======================== */
#define NVIC_BASE_ADDRESS	0xE000E100UL
#define NVIC_ISER0			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x00)
#define NVIC_ISER1			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x04)
#define NVIC_ISER2			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x08)
#define NVIC_ICER0			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x80)
#define NVIC_ICER1			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x84)
#define NVIC_ICER2			*(volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x88)
/* ======================================================= */


/* =========== Base Addresses For Peripherals ============ */
/* AHB */
#define RCC_BASE                    0x40021000

/* APB2 */
#define GPIOE_BASE                  0x40011800
#define GPIOD_BASE                  0x40011400
#define GPIOC_BASE                  0x40011000
#define GPIOB_BASE                  0x40010C00
#define GPIOA_BASE                  0x40010800
#define EXTI_BASE                   0x40010400
#define AFIO_BASE                   0x40010000
#define USART1_BASE                 0x40013800

/* APB1 */
/* ======================================================= */
#define USART2_BASE                 0x40004400
#define USART3_BASE                 0x40004800


/* ================ Peripheral Registers ================= */
/* RCC */
typedef struct RCC
{
    volatile uint32_t CR;        /* 0x00 */
    volatile uint32_t CFGR;      /* 0x04 */
    volatile uint32_t CIR;       /* 0x08 */
    volatile uint32_t APB2RSTR;  /* 0x0C */
    volatile uint32_t APB1RSTR;  /* 0x10 */
    volatile uint32_t AHBENR;    /* 0x14 */
    volatile uint32_t APB2ENR;   /* 0x18 */
    volatile uint32_t APB1ENR;   /* 0x1C */
    volatile uint32_t BDCR;      /* 0x20 */
    volatile uint32_t CSR;       /* 0x24 */
}RCC_t;


/* GPIOx */
typedef struct GPIOx
{
    volatile uint32_t CRL;       /* 0x00 */
    volatile uint32_t CRH;       /* 0x04 */
    volatile uint32_t IDR;       /* 0x08 */
    volatile uint32_t ODR;       /* 0x0C */
    volatile uint32_t BSRR;      /* 0x10 */
    volatile uint32_t BRR;       /* 0x14 */
    volatile uint32_t LCKR;      /* 0x18 */
}GPIOx_t;

/* EXTI */
typedef struct EXTI
{
    volatile uint32_t IMR;       /* 0x00 */
    volatile uint32_t EMR;       /* 0x04 */
    volatile uint32_t RTSR;      /* 0x08 */
    volatile uint32_t FTSR;      /* 0x0C */
    volatile uint32_t SWIER;     /* 0x10 */
    volatile uint32_t PR;        /* 0x14 */
}EXTI_t;

/* AFIO */
typedef struct AFIO
{
    volatile uint32_t EVCR;      /* 0x00 */
    volatile uint32_t MAPR;      /* 0x04 */
    volatile uint32_t EXTICR[4]; /* 0x08 - 0x14 */
    volatile uint32_t reserved;  /* 0x18 */
    volatile uint32_t MAPR2;     /* 0x1C */
}AFIO_t;

/* USARTx */
typedef struct USARTx
{
    volatile uint32_t SR;       /* 0x00 */
    volatile uint32_t DR;       /* 0x04 */
    volatile uint32_t BRR;      /* 0x08 */
    volatile uint32_t CR1;      /* 0x0C */
    volatile uint32_t CR2;      /* 0x10 */
    volatile uint32_t CR3;      /* 0x14 */
    volatile uint32_t GTPR;     /* 0x18 */
}USARTx_t;

/* ======================================================= */



/* ================= Peripheral Instants ================= */
/* RCC */
#define RCC         ((RCC_t *) (RCC_BASE))

/* GPIO */
#define GPIOA       ((GPIOx_t *) (GPIOA_BASE))
#define GPIOB       ((GPIOx_t *) (GPIOB_BASE))
#define GPIOC       ((GPIOx_t *) (GPIOC_BASE))
#define GPIOD       ((GPIOx_t *) (GPIOD_BASE))
#define GPIOE       ((GPIOx_t *) (GPIOE_BASE))

/* EXTI */
#define EXTI        ((EXTI_t *) (EXTI_BASE))

/* AFIO */
#define AFIO        ((AFIO_t *) (AFIO_BASE))

/* USART */
#define USART1      ((USARTx_t *) (USART1_BASE))
#define USART2      ((USARTx_t *) (USART2_BASE))
#define USART3      ((USARTx_t *) (USART3_BASE))
/* ======================================================= */


/* ================= Clock Enable Macros ================= */
#define RCC_GPIOA_CLK_EN()      (RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()      (RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()      (RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()      (RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()      (RCC->APB2ENR |= (1<<6))
#define RCC_AFIO_CLK_EN()       (RCC->APB2ENR |= (1<<0))
#define RCC_USART1_CLK_EN()     (RCC->APB2ENR |= (1<<14))
#define RCC_USART2_CLK_EN()     (RCC->APB1ENR |= (1<<17))
#define RCC_USART3_CLK_EN()     (RCC->APB1ENR |= (1<<18))
/* ======================================================= */

/* =============== Reset Peripheral Macros =============== */
#define RCC_GPIOA_RST()         (RCC->APB2RSTR |= (1<<2))
#define RCC_GPIOB_RST()         (RCC->APB2RSTR |= (1<<3))
#define RCC_GPIOC_RST()         (RCC->APB2RSTR |= (1<<4))
#define RCC_GPIOD_RST()         (RCC->APB2RSTR |= (1<<5))
#define RCC_GPIOE_RST()         (RCC->APB2RSTR |= (1<<6))
#define RCC_AFIO_RST()          (RCC->APB2RSTR |= (1<<0))
#define RCC_USART1_RST()        (RCC->APB2RSTR |= (1<<14))
#define RCC_USART2_RST()        (RCC->APB1RSTR |= (1<<17))
#define RCC_USART3_RST()        (RCC->APB1RSTR |= (1<<18))
/* ======================================================= */

/* =============== Interrupt Vector Table ================ */
/* EXIT */
#define IVT_EXTI0_IRQ           6
#define IVT_EXTI1_IRQ           7
#define IVT_EXTI2_IRQ           8
#define IVT_EXTI3_IRQ           9
#define IVT_EXTI4_IRQ           10
#define IVT_EXTI5_IRQ           23
#define IVT_EXTI6_IRQ           23
#define IVT_EXTI7_IRQ           23
#define IVT_EXTI8_IRQ           23
#define IVT_EXTI9_IRQ           23
#define IVT_EXTI10_IRQ          40
#define IVT_EXTI11_IRQ          40
#define IVT_EXTI12_IRQ          40
#define IVT_EXTI13_IRQ          40
#define IVT_EXTI14_IRQ          40
#define IVT_EXTI15_IRQ          40
/* USART */
#define IVT_USART1_IRQ          37
#define IVT_USART2_IRQ          38
#define IVT_USART3_IRQ          39
/* ======================================================= */


/* ============== Enable Interrupt Macros ================ */
/* EXTI */
#define NVIC_IRQ6_EXTI_0_EN()        (NVIC_ISER0 |= 1<<IVT_EXTI0_IRQ)
#define NVIC_IRQ7_EXTI_1_EN()        (NVIC_ISER0 |= 1<<IVT_EXTI1_IRQ)
#define NVIC_IRQ8_EXTI_2_EN()        (NVIC_ISER0 |= 1<<IVT_EXTI2_IRQ)
#define NVIC_IRQ9_EXTI_3_EN()        (NVIC_ISER0 |= 1<<IVT_EXTI3_IRQ)
#define NVIC_IRQ10_EXTI_4_EN()       (NVIC_ISER0 |= 1<<IVT_EXTI4_IRQ)
#define NVIC_IRQ23_EXTI_5_9_EN()     (NVIC_ISER0 |= 1<<IVT_EXTI5_IRQ)
#define NVIC_IRQ40_EXTI_10_15_EN()   (NVIC_ISER1 |= 1<<(IVT_EXTI10_IRQ - 32))
#define NVIC_IRQ37_USART1_EN()       (NVIC_ISER1 |= 1<<(IVT_USART1_IRQ - 32))
#define NVIC_IRQ38_USART2_EN()       (NVIC_ISER1 |= 1<<(IVT_USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_EN()       (NVIC_ISER1 |= 1<<(IVT_USART3_IRQ - 32))
/* ======================================================= */

/* ============== Disable Interrupt Macros ================ */
#define NVIC_IRQ6_EXTI_0_DIS()        (NVIC_ICER0 |= 1<<IVT_EXTI0_IRQ)
#define NVIC_IRQ7_EXTI_1_DIS()        (NVIC_ICER0 |= 1<<IVT_EXTI1_IRQ)
#define NVIC_IRQ8_EXTI_2_DIS()        (NVIC_ICER0 |= 1<<IVT_EXTI2_IRQ)
#define NVIC_IRQ9_EXTI_3_DIS()        (NVIC_ICER0 |= 1<<IVT_EXTI3_IRQ)
#define NVIC_IRQ10_EXTI_4_DIS()       (NVIC_ICER0 |= 1<<IVT_EXTI4_IRQ)
#define NVIC_IRQ23_EXTI_5_9_DIS()     (NVIC_ICER0 |= 1<<IVT_EXTI5_IRQ)
#define NVIC_IRQ40_EXTI_10_15_DIS()   (NVIC_ICER1 |= 1<<(IVT_EXTI10_IRQ - 32))
#define NVIC_IRQ37_USART1_DIS()       (NVIC_ICER1 |= 1<<(IVT_USART1_IRQ - 32))
#define NVIC_IRQ38_USART2_DIS()       (NVIC_ICER1 |= 1<<(IVT_USART2_IRQ - 32))
#define NVIC_IRQ39_USART3_DIS()       (NVIC_ICER1 |= 1<<(IVT_USART3_IRQ - 32))
/* ======================================================= */


#endif