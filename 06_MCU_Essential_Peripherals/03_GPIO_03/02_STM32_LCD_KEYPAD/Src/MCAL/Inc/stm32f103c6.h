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

/* APB1 */
/* ======================================================= */



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
    volatile uint32_t AHBSTR;    /* 0x28 */
    volatile uint32_t CFGR2;     /* 0x2C */
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
    volatile uint32_t EXTICR1;   /* 0x08 */
    volatile uint32_t EXTICR2;   /* 0x0C */
    volatile uint32_t EXTICR3;   /* 0x10 */
    volatile uint32_t EXTICR4;   /* 0x14 */
    volatile uint32_t reserved;  /* 0x14 */
    volatile uint32_t MAPR2;     /* 0x1C */
}AFIO_t;
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
/* ======================================================= */


/* ================= Clock Enable Macros ================= */
#define RCC_GPIOA_CLK_EN()      (RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()      (RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()      (RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()      (RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN()      (RCC->APB2ENR |= (1<<6))
#define RCC_AFIO_CLK_EN()       (RCC->APB2ENR |= (1<<0))
/* ======================================================= */



#endif