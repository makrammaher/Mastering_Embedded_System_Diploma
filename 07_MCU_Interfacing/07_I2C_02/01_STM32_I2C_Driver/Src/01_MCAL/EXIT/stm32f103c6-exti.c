/*
 *           File: stm32f103c6-exti.c
 *     Created on: Saturday 4/06/2022 9:33
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 EXIT Driver
 *
 *
 */

/* ======================= Includes ====================== */
#include "stm32f103c6-exti.h"
/* ======================================================= */

/* ==================== Generic Macros =================== */
#define AFIO_GPIO_EXTI_Value(x) ((x == GPIOA) ? 0x00 : (x == GPIOB) ? 0x01 \
                                                   : (x == GPIOC)   ? 0x02 \
                                                   : (x == GPIOD)   ? 0x03 \
                                                   : (x == GPIOE)   ? 0x04 \
                                                                    : 0x00)

/* ======================================================= */

/* ================== Generic Variables ==================*/

void (*GP_IRQ_CallBack[15])(void);

/* ======================================================= */

/* ============== Static Function Prototypes ============= */

static void Enable_NVIC(uint8_t EXTIx);
static void Disable_NVIC(uint8_t EXTIx);

/* ======================================================= */

/**
 * @brief initialaize the EXTIx
 *
 * @param PinConfig is a pointer to structure that holds the configration of the EXTIx
 */
void EXTI_GPIO_Init(EXTI_PinConfig_t *PinConfig)
{
    EXTI_GPIO_Update(PinConfig);
}

/**
 * @brief update EXTIx
 *
 * @param PinConfig is a pointer to structure that holds the configration of the EXTIx
 */
void EXTI_GPIO_Update(EXTI_PinConfig_t *PinConfig)
{
    /* Configure GPIO To Be Alternative Function Input (Floating Input) */
    GPIO_Init(PinConfig->EXTI_PIN.GPIOx, GPIO_MODE_INPUT_F, PinConfig->EXTI_PIN.GPIO_PIN);

    /* Route AFIO to Selected GPIOx */
    uint8_t AFIO_EXTICR_index = (uint8_t)PinConfig->EXTI_PIN.EXTIx / 4;
    uint8_t AFIO_EXTICR_position = (PinConfig->EXTI_PIN.EXTIx % 4) * 4;
    AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0x0F << AFIO_EXTICR_position);
    AFIO->EXTICR[AFIO_EXTICR_index] |= (AFIO_GPIO_EXTI_Value(PinConfig->EXTI_PIN.GPIOx) << AFIO_EXTICR_position);

    /* Select Trigger Rising, Falling, Logical Change */
    EXTI->RTSR &= ~(1 << PinConfig->EXTI_PIN.EXTIx);
    EXTI->FTSR &= ~(1 << PinConfig->EXTI_PIN.EXTIx);

    switch (PinConfig->Trigger_Case)
    {
    case EXTI_TRIGGER_RISING:
        EXTI->RTSR |= (1 << PinConfig->EXTI_PIN.EXTIx);
        break;
    case EXTI_TRIGGER_FALLING:
        EXTI->FTSR |= (1 << PinConfig->EXTI_PIN.EXTIx);
        break;
    case EXTI_TRIGGER_LOGIC_CHANGE:
        EXTI->FTSR |= (1 << PinConfig->EXTI_PIN.EXTIx);
        EXTI->RTSR |= (1 << PinConfig->EXTI_PIN.EXTIx);
        break;
    default:
        break;
    }

    /* Update Interrupt IRQ Callback */
    GP_IRQ_CallBack[PinConfig->EXTI_PIN.EXTIx] = PinConfig->P_IRQ_Callback;

    /* Enable or Disable IRQ EXTI & NVIC */
    if (PinConfig->IRQ_Enable == EXTI_IRQ_ENABLE)
    {
        EXTI->IMR |= (1 << PinConfig->EXTI_PIN.EXTIx);
        Enable_NVIC(PinConfig->EXTI_PIN.EXTIx);
    }
    else
    {
        EXTI->IMR &= ~(1 << PinConfig->EXTI_PIN.EXTIx);
        Disable_NVIC(PinConfig->EXTI_PIN.EXTIx);
    }
}

/**
 * @brief Reset the EXTIx
 *
 * @param EXTIx  must set by @ref EXTIx_define
 */
void EXTI_GPIO_Reset(uint8_t EXTIx)
{
    /* Disable Mask in EXTI */
    EXTI->IMR &= ~(1 << EXTIx);
    /* Disable Mask in NVIC */
    Disable_NVIC(EXTIx);

    /* Disable Trigger in Rising, Falling Registers */
    EXTI->RTSR &= ~(1 << EXTIx);
    EXTI->FTSR &= ~(1 << EXTIx);
    
    /* Update Interrupt IRQ Callback to be NULL */
    GP_IRQ_CallBack[EXTIx] = 0;

    /* Route AFIO to Default GPIOx */
    uint8_t AFIO_EXTICR_index = (uint8_t)EXTIx / 4;
    uint8_t AFIO_EXTICR_position = (EXTIx % 4) * 4;

    AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0x0F << AFIO_EXTICR_position);
}

static void Enable_NVIC(uint8_t EXTIx)
{
    switch (EXTIx)
    {
    case EXTI0:
        NVIC_IRQ6_EXTI_0_EN();
        break;
    case EXTI1:
        NVIC_IRQ7_EXTI_1_EN();
        break;
    case EXTI2:
        NVIC_IRQ8_EXTI_2_EN();
        break;
    case EXTI3:
        NVIC_IRQ9_EXTI_3_EN();
        break;
    case EXTI4:
        NVIC_IRQ10_EXTI_4_EN();
        break;
    case EXTI5:
    case EXTI6:
    case EXTI7:
    case EXTI8:
    case EXTI9:
        NVIC_IRQ23_EXTI_5_9_EN();
        break;
    case EXTI10:
    case EXTI11:
    case EXTI12:
    case EXTI13:
    case EXTI14:
    case EXTI15:
        NVIC_IRQ40_EXTI_10_15_EN();
        break;
    default:
        break;
    }
}

static void Disable_NVIC(uint8_t EXTIx)
{
    switch (EXTIx)
    {
    case EXTI0:
        NVIC_IRQ6_EXTI_0_DIS();
        break;
    case EXTI1:
        NVIC_IRQ7_EXTI_1_DIS();
        break;
    case EXTI2:
        NVIC_IRQ8_EXTI_2_DIS();
        break;
    case EXTI3:
        NVIC_IRQ9_EXTI_3_DIS();
        break;
    case EXTI4:
        NVIC_IRQ10_EXTI_4_DIS();
        break;
    case EXTI5:
    case EXTI6:
    case EXTI7:
    case EXTI8:
    case EXTI9:
        NVIC_IRQ23_EXTI_5_9_DIS();
        break;
    case EXTI10:
    case EXTI11:
    case EXTI12:
    case EXTI13:
    case EXTI14:
    case EXTI15:
        NVIC_IRQ40_EXTI_10_15_DIS();
        break;
    default:
        break;
    }
}

/* ======================== ISRs =========================*/

void EXTI0_handler(void)
{
    /* Clear By Writing "1" into the bit Pending Register (EXTI_PR) */
    EXTI->PR |= (1 << EXTI0);
    /* Call IRQ_CallBack */
    GP_IRQ_CallBack[EXTI0]();
}

void EXTI1_handler(void)
{
    EXTI->PR |= (1 << EXTI1);
    GP_IRQ_CallBack[EXTI1]();
}

void EXTI2_handler(void)
{
    EXTI->PR |= (1 << EXTI2);
    GP_IRQ_CallBack[EXTI2]();
}

void EXTI3_handler(void)
{
    EXTI->PR |= (1 << EXTI3);
    GP_IRQ_CallBack[EXTI3]();
}

void EXTI4_handler(void)
{
    EXTI->PR |= (1 << EXTI4);
    GP_IRQ_CallBack[EXTI4]();
}

void EXTI5_9_handler(void)
{
    if (EXTI->PR & (1 << EXTI5))
    {
        EXTI->PR |= (1 << EXTI5);
        GP_IRQ_CallBack[EXTI5]();
    }
    if (EXTI->PR & (1 << EXTI6))
    {
        EXTI->PR |= (1 << EXTI6);
        GP_IRQ_CallBack[EXTI6]();
    }
    if (EXTI->PR & (1 << EXTI6))
    {
        EXTI->PR |= (1 << EXTI6);
        GP_IRQ_CallBack[EXTI6]();
    }
    if (EXTI->PR & (1 << EXTI7))
    {
        EXTI->PR |= (1 << EXTI7);
        GP_IRQ_CallBack[EXTI7]();
    }
    if (EXTI->PR & (1 << EXTI8))
    {
        EXTI->PR |= (1 << EXTI8);
        GP_IRQ_CallBack[EXTI8]();
    }
    if (EXTI->PR & (1 << EXTI9))
    {

        GP_IRQ_CallBack[EXTI9]();
        EXTI->PR |= (1 << EXTI9);
    }
}

void EXTI10_15_handler(void)
{
    if (EXTI->PR & (1 << EXTI10))
    {
        EXTI->PR |= (1 << EXTI10);
        GP_IRQ_CallBack[EXTI10]();
    }
    if (EXTI->PR & (1 << EXTI11))
    {
        EXTI->PR |= (1 << EXTI11);
        GP_IRQ_CallBack[EXTI11]();
    }
    if (EXTI->PR & (1 << EXTI12))
    {
        EXTI->PR |= (1 << EXTI12);
        GP_IRQ_CallBack[EXTI12]();
    }
    if (EXTI->PR & (1 << EXTI13))
    {
        EXTI->PR |= (1 << EXTI13);
        GP_IRQ_CallBack[EXTI13]();
    }
    if (EXTI->PR & (1 << EXTI14))
    {
        EXTI->PR |= (1 << EXTI14);
        GP_IRQ_CallBack[EXTI14]();
    }
    if (EXTI->PR & (1 << EXTI15))
    {
        EXTI->PR |= (1 << EXTI15);
        GP_IRQ_CallBack[EXTI15]();
    }
}

/* ======================================================= */