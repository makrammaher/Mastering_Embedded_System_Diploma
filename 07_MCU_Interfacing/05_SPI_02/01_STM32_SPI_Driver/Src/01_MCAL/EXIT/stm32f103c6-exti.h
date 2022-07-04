/*
 *           File: stm32f103c6-exti.h
 *     Created on: Saturday 4/06/2022 9:33
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 EXIT Driver
 *
 *
 */

#ifndef _STM32F103C6_EXTI_H_
#define _STM32F103C6_EXTI_H_

/* ======================= Includes ====================== */
#include "stm32f103c6.h"
#include "stm32f103c6-gpio.h"
/* ======================================================= */

typedef struct
{
    uint8_t     EXTIx;
    GPIOx_t*    GPIOx;
    uint16_t    GPIO_PIN;
    uint8_t     IVT_IRQx;
}EXTI_GPIO_Mapping_t;


typedef struct
{
    EXTI_GPIO_Mapping_t     EXTI_PIN;       /* Specifies the External interrupt GPIO mapping */
                                            /* Must be set by @ref EXTI_PIN_define */
    
    uint8_t                 Trigger_Case;   /* Specifies the Trigger case Falling, Rising, BOTH*/
                                            /* Must be set by @ref EXTI_Trigger_Case_define */

    uint8_t                 IRQ_Enable;     /* Enabled or Disable the external interrupt */
                                            /* Must be set by @ref EXTI_IRQ_define */

    void (* P_IRQ_Callback)(void);          /* Poiter to function callback Which will be called once the IRQ Happend */
}EXTI_PinConfig_t;

/** @defgroup EXTIx_define
 *  @brief EXTIx Define
 * @{
 */
#define EXTI0       0
#define EXTI1       1
#define EXTI2       2
#define EXTI3       3
#define EXTI4       4
#define EXTI5       5
#define EXTI6       6
#define EXTI7       7
#define EXTI8       8
#define EXTI9       9
#define EXTI10      10
#define EXTI11      11
#define EXTI12      12
#define EXTI13      13
#define EXTI14      14
#define EXTI15      15
/**
 * @}
 */



/** @defgroup EXTI_PIN_define
 *  @brief EXTI PIN Define
 * @{
 */
/* EXTI0 */
#define EXTI0_PA0   (EXTI_GPIO_Mapping_t){EXTI0, GPIOA, GPIO_PIN_0, IVT_EXTI0_IRQ}
#define EXTI0_PB0   (EXTI_GPIO_Mapping_t){EXTI0, GPIOB, GPIO_PIN_0, IVT_EXTI0_IRQ}
#define EXTI0_PC0   (EXTI_GPIO_Mapping_t){EXTI0, GPIOC, GPIO_PIN_0, IVT_EXTI0_IRQ}
#define EXTI0_PD0   (EXTI_GPIO_Mapping_t){EXTI0, GPIOD, GPIO_PIN_0, IVT_EXTI0_IRQ}
#define EXTI0_PE0   (EXTI_GPIO_Mapping_t){EXTI0, GPIOE, GPIO_PIN_0, IVT_EXTI0_IRQ}

/* EXTI1 */
#define EXTI1_PA1   (EXTI_GPIO_Mapping_t){EXTI1, GPIOA, GPIO_PIN_1, IVT_EXTI1_IRQ}
#define EXTI1_PB1   (EXTI_GPIO_Mapping_t){EXTI1, GPIOB, GPIO_PIN_1, IVT_EXTI1_IRQ}
#define EXTI1_PC1   (EXTI_GPIO_Mapping_t){EXTI1, GPIOC, GPIO_PIN_1, IVT_EXTI1_IRQ}
#define EXTI1_PD1   (EXTI_GPIO_Mapping_t){EXTI1, GPIOD, GPIO_PIN_1, IVT_EXTI1_IRQ}
#define EXTI1_PE1   (EXTI_GPIO_Mapping_t){EXTI1, GPIOE, GPIO_PIN_1, IVT_EXTI1_IRQ}

/* EXTI2 */
#define EXTI2_PA2   (EXTI_GPIO_Mapping_t){EXTI2, GPIOA, GPIO_PIN_2, IVT_EXTI2_IRQ}
#define EXTI2_PB2   (EXTI_GPIO_Mapping_t){EXTI2, GPIOB, GPIO_PIN_2, IVT_EXTI2_IRQ}
#define EXTI2_PC2   (EXTI_GPIO_Mapping_t){EXTI2, GPIOC, GPIO_PIN_2, IVT_EXTI2_IRQ}
#define EXTI2_PD2   (EXTI_GPIO_Mapping_t){EXTI2, GPIOD, GPIO_PIN_2, IVT_EXTI2_IRQ}
#define EXTI2_PE2   (EXTI_GPIO_Mapping_t){EXTI2, GPIOE, GPIO_PIN_2, IVT_EXTI2_IRQ}

/* EXTI3 */
#define EXTI3_PA3   (EXTI_GPIO_Mapping_t){EXTI3, GPIOA, GPIO_PIN_3, IVT_EXTI3_IRQ}
#define EXTI3_PB3   (EXTI_GPIO_Mapping_t){EXTI3, GPIOB, GPIO_PIN_3, IVT_EXTI3_IRQ}
#define EXTI3_PC3   (EXTI_GPIO_Mapping_t){EXTI3, GPIOC, GPIO_PIN_3, IVT_EXTI3_IRQ}
#define EXTI3_PD3   (EXTI_GPIO_Mapping_t){EXTI3, GPIOD, GPIO_PIN_3, IVT_EXTI3_IRQ}
#define EXTI3_PE3   (EXTI_GPIO_Mapping_t){EXTI3, GPIOE, GPIO_PIN_3, IVT_EXTI3_IRQ}

/* EXTI4 */
#define EXTI4_PA4   (EXTI_GPIO_Mapping_t){EXTI4, GPIOA, GPIO_PIN_4, IVT_EXTI4_IRQ}
#define EXTI4_PB4   (EXTI_GPIO_Mapping_t){EXTI4, GPIOB, GPIO_PIN_4, IVT_EXTI4_IRQ}
#define EXTI4_PC4   (EXTI_GPIO_Mapping_t){EXTI4, GPIOC, GPIO_PIN_4, IVT_EXTI4_IRQ}
#define EXTI4_PD4   (EXTI_GPIO_Mapping_t){EXTI4, GPIOD, GPIO_PIN_4, IVT_EXTI4_IRQ}
#define EXTI4_PE4   (EXTI_GPIO_Mapping_t){EXTI4, GPIOE, GPIO_PIN_4, IVT_EXTI4_IRQ}

/* EXTI5 */
#define EXTI5_PA5   (EXTI_GPIO_Mapping_t){EXTI5, GPIOA, GPIO_PIN_5, IVT_EXTI5_IRQ}
#define EXTI5_PB5   (EXTI_GPIO_Mapping_t){EXTI5, GPIOB, GPIO_PIN_5, IVT_EXTI5_IRQ}
#define EXTI5_PC5   (EXTI_GPIO_Mapping_t){EXTI5, GPIOC, GPIO_PIN_5, IVT_EXTI5_IRQ}
#define EXTI5_PD5   (EXTI_GPIO_Mapping_t){EXTI5, GPIOD, GPIO_PIN_5, IVT_EXTI5_IRQ}
#define EXTI5_PE5   (EXTI_GPIO_Mapping_t){EXTI5, GPIOE, GPIO_PIN_5, IVT_EXTI5_IRQ}

/* EXTI6 */
#define EXTI6_PA6   (EXTI_GPIO_Mapping_t){EXTI6, GPIOA, GPIO_PIN_6, IVT_EXTI6_IRQ}
#define EXTI6_PB6   (EXTI_GPIO_Mapping_t){EXTI6, GPIOB, GPIO_PIN_6, IVT_EXTI6_IRQ}
#define EXTI6_PC6   (EXTI_GPIO_Mapping_t){EXTI6, GPIOC, GPIO_PIN_6, IVT_EXTI6_IRQ}
#define EXTI6_PD6   (EXTI_GPIO_Mapping_t){EXTI6, GPIOD, GPIO_PIN_6, IVT_EXTI6_IRQ}
#define EXTI6_PE6   (EXTI_GPIO_Mapping_t){EXTI6, GPIOE, GPIO_PIN_6, IVT_EXTI6_IRQ}

/* EXTI7 */
#define EXTI7_PA7   (EXTI_GPIO_Mapping_t){EXTI7, GPIOA, GPIO_PIN_7, IVT_EXTI7_IRQ}
#define EXTI7_PB7   (EXTI_GPIO_Mapping_t){EXTI7, GPIOB, GPIO_PIN_7, IVT_EXTI7_IRQ}
#define EXTI7_PC7   (EXTI_GPIO_Mapping_t){EXTI7, GPIOC, GPIO_PIN_7, IVT_EXTI7_IRQ}
#define EXTI7_PD7   (EXTI_GPIO_Mapping_t){EXTI7, GPIOD, GPIO_PIN_7, IVT_EXTI7_IRQ}
#define EXTI7_PE7   (EXTI_GPIO_Mapping_t){EXTI7, GPIOE, GPIO_PIN_7, IVT_EXTI7_IRQ}

/* EXTI8 */
#define EXTI8_PA8   (EXTI_GPIO_Mapping_t){EXTI8, GPIOA, GPIO_PIN_8, IVT_EXTI8_IRQ}
#define EXTI8_PB8   (EXTI_GPIO_Mapping_t){EXTI8, GPIOB, GPIO_PIN_8, IVT_EXTI8_IRQ}
#define EXTI8_PC8   (EXTI_GPIO_Mapping_t){EXTI8, GPIOC, GPIO_PIN_8, IVT_EXTI8_IRQ}
#define EXTI8_PD8   (EXTI_GPIO_Mapping_t){EXTI8, GPIOD, GPIO_PIN_8, IVT_EXTI8_IRQ}
#define EXTI8_PE8   (EXTI_GPIO_Mapping_t){EXTI8, GPIOE, GPIO_PIN_8, IVT_EXTI8_IRQ}

/* EXTI9 */
#define EXTI9_PA9   (EXTI_GPIO_Mapping_t){EXTI9, GPIOA, GPIO_PIN_9, IVT_EXTI9_IRQ}
#define EXTI9_PB9   (EXTI_GPIO_Mapping_t){EXTI9, GPIOB, GPIO_PIN_9, IVT_EXTI9_IRQ}
#define EXTI9_PC9   (EXTI_GPIO_Mapping_t){EXTI9, GPIOC, GPIO_PIN_9, IVT_EXTI9_IRQ}
#define EXTI9_PD9   (EXTI_GPIO_Mapping_t){EXTI9, GPIOD, GPIO_PIN_9, IVT_EXTI9_IRQ}
#define EXTI9_PE9   (EXTI_GPIO_Mapping_t){EXTI9, GPIOE, GPIO_PIN_9, IVT_EXTI9_IRQ}

/* EXTI10 */
#define EXTI10_PA10 (EXTI_GPIO_Mapping_t){EXTI10, GPIOA, GPIO_PIN_10, IVT_EXTI10_IRQ}
#define EXTI10_PB10 (EXTI_GPIO_Mapping_t){EXTI10, GPIOB, GPIO_PIN_10, IVT_EXTI10_IRQ}
#define EXTI10_PC10 (EXTI_GPIO_Mapping_t){EXTI10, GPIOC, GPIO_PIN_10, IVT_EXTI10_IRQ}
#define EXTI10_PD10 (EXTI_GPIO_Mapping_t){EXTI10, GPIOD, GPIO_PIN_10, IVT_EXTI10_IRQ}
#define EXTI10_PE10 (EXTI_GPIO_Mapping_t){EXTI10, GPIOE, GPIO_PIN_10, IVT_EXTI10_IRQ}

/* EXTI11 */
#define EXTI11_PA11 (EXTI_GPIO_Mapping_t){EXTI11, GPIOA, GPIO_PIN_11, IVT_EXTI11_IRQ}
#define EXTI11_PB11 (EXTI_GPIO_Mapping_t){EXTI11, GPIOB, GPIO_PIN_11, IVT_EXTI11_IRQ}
#define EXTI11_PC11 (EXTI_GPIO_Mapping_t){EXTI11, GPIOC, GPIO_PIN_11, IVT_EXTI11_IRQ}
#define EXTI11_PD11 (EXTI_GPIO_Mapping_t){EXTI11, GPIOD, GPIO_PIN_11, IVT_EXTI11_IRQ}
#define EXTI11_PE11 (EXTI_GPIO_Mapping_t){EXTI11, GPIOE, GPIO_PIN_11, IVT_EXTI11_IRQ}

/* EXTI12 */
#define EXTI12_PA12 (EXTI_GPIO_Mapping_t){EXTI12, GPIOA, GPIO_PIN_12, IVT_EXTI12_IRQ}
#define EXTI12_PB12 (EXTI_GPIO_Mapping_t){EXTI12, GPIOB, GPIO_PIN_12, IVT_EXTI12_IRQ}
#define EXTI12_PC12 (EXTI_GPIO_Mapping_t){EXTI12, GPIOC, GPIO_PIN_12, IVT_EXTI12_IRQ}
#define EXTI12_PD12 (EXTI_GPIO_Mapping_t){EXTI12, GPIOD, GPIO_PIN_12, IVT_EXTI12_IRQ}
#define EXTI12_PE12 (EXTI_GPIO_Mapping_t){EXTI12, GPIOE, GPIO_PIN_12, IVT_EXTI12_IRQ}

/* EXTI13 */
#define EXTI13_PA13 (EXTI_GPIO_Mapping_t){EXTI13, GPIOA, GPIO_PIN_13, IVT_EXTI13_IRQ}
#define EXTI13_PB13 (EXTI_GPIO_Mapping_t){EXTI13, GPIOB, GPIO_PIN_13, IVT_EXTI13_IRQ}
#define EXTI13_PC13 (EXTI_GPIO_Mapping_t){EXTI13, GPIOC, GPIO_PIN_13, IVT_EXTI13_IRQ}
#define EXTI13_PD13 (EXTI_GPIO_Mapping_t){EXTI13, GPIOD, GPIO_PIN_13, IVT_EXTI13_IRQ}
#define EXTI13_PE13 (EXTI_GPIO_Mapping_t){EXTI13, GPIOE, GPIO_PIN_13, IVT_EXTI13_IRQ}

/* EXTI14 */
#define EXTI14_PA14 (EXTI_GPIO_Mapping_t){EXTI14, GPIOA, GPIO_PIN_14, IVT_EXTI14_IRQ}
#define EXTI14_PB14 (EXTI_GPIO_Mapping_t){EXTI14, GPIOB, GPIO_PIN_14, IVT_EXTI14_IRQ}
#define EXTI14_PC14 (EXTI_GPIO_Mapping_t){EXTI14, GPIOC, GPIO_PIN_14, IVT_EXTI14_IRQ}
#define EXTI14_PD14 (EXTI_GPIO_Mapping_t){EXTI14, GPIOD, GPIO_PIN_14, IVT_EXTI14_IRQ}
#define EXTI14_PE14 (EXTI_GPIO_Mapping_t){EXTI14, GPIOE, GPIO_PIN_14, IVT_EXTI14_IRQ}

/* EXTI15 */
#define EXTI15_PA15 (EXTI_GPIO_Mapping_t){EXTI15, GPIOA, GPIO_PIN_15, IVT_EXTI15_IRQ}
#define EXTI15_PB15 (EXTI_GPIO_Mapping_t){EXTI15, GPIOB, GPIO_PIN_15, IVT_EXTI15_IRQ}
#define EXTI15_PC15 (EXTI_GPIO_Mapping_t){EXTI15, GPIOC, GPIO_PIN_15, IVT_EXTI15_IRQ}
#define EXTI15_PD15 (EXTI_GPIO_Mapping_t){EXTI15, GPIOD, GPIO_PIN_15, IVT_EXTI15_IRQ}
#define EXTI15_PE15 (EXTI_GPIO_Mapping_t){EXTI15, GPIOE, GPIO_PIN_15, IVT_EXTI15_IRQ}

/**
 * @}
 */

 
/** @defgroup EXTI_Trigger_Case_define
 *  @brief EXTI trigger case Define
 * @{
 */

#define EXTI_TRIGGER_RISING             0
#define EXTI_TRIGGER_FALLING            1
#define EXTI_TRIGGER_LOGIC_CHANGE       2

/**
 * @}
 */


/** @defgroup EXTI_IRQ_define
 *  @brief EXTI IRQ Enable or Disable Define
 * @{
 */

#define EXTI_IRQ_ENABLE     1
#define EXTI_IRQ_DISABLE    0

/**
 * @}
 */


/**
 * @brief initialaize the EXTIx
 * 
 * @param PinConfig is a pointer to structure that holds the configration of the EXTIx
 */
void EXTI_GPIO_Init(EXTI_PinConfig_t * PinConfig);

/**
 * @brief update EXTIx
 * 
 * @param PinConfig is a pointer to structure that holds the configration of the EXTIx
 */
void EXTI_GPIO_Update(EXTI_PinConfig_t * PinConfig);


/**
 * @brief Reset the EXTIx
 * 
 * @param EXTIx  must set by @ref EXTIx_define
 */
void EXTI_GPIO_Reset(uint8_t EXTIx);




#endif