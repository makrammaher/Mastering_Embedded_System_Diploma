/*
 *           File: stm32f103c6-gpio.h
 *     Created on: Monday 30/05/2022 19:43
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 GPIO Driver
 *
 *
 */


#ifndef _STM32F103C6_GPIO_H_
#define _STM32F103C6_GPIO_H_

#include "stm32f103c6.h"

/** @defgroup GPIO_pins_define GPIO pins define
  * @{
  */

#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */
#define GPIO_PIN_MASK              0x0000FFFFu /* PIN mask for assert test */

/**
  * @}
  */


/** @defgroup GPIO_mode_define GPIO mode define
 *  @brief GPIO Configuration Mode
 *        Elements values convention: 0b(0, 0, 0, PxODR, CNF1, CNF0, MODE1, MODE0)
 * @{
 */

#define  GPIO_MODE_INPUT_F              ((uint8_t)0b00000100u)     /*!< Input Floating Mode                      */

#define  GPIO_MODE_INPUT_A              ((uint8_t)0b00000000u)     /*!< Input Analog Mode                        */

#define  GPIO_MODE_INPUT_PU             ((uint8_t)0b00011000u)     /*!< Input Pull-up Mode                       */
#define  GPIO_MODE_INPUT_PD             ((uint8_t)0b00001000u)     /*!< Input Pull-down Mode                     */

#define  GPIO_MODE_OUTPUT_PP_10MHZ      ((uint8_t)0b00000001u)     /*!< Output Push Pull Mode 10MHZ              */
#define  GPIO_MODE_OUTPUT_PP_2MHZ       ((uint8_t)0b00000010u)     /*!< Output Push Pull Mode 2MHZ               */
#define  GPIO_MODE_OUTPUT_PP_50MHZ      ((uint8_t)0b00000011u)     /*!< Output Push Pull Mode 50MHZ              */

#define  GPIO_MODE_OUTPUT_OD_10MHZ      ((uint8_t)0b00000101u)     /*!< Output Open Drain Mode 10MHZ             */
#define  GPIO_MODE_OUTPUT_OD_2MHZ       ((uint8_t)0b00000110u)     /*!< Output Open Drain Mode 2MHZ              */
#define  GPIO_MODE_OUTPUT_OD_50MHZ      ((uint8_t)0b00000111u)     /*!< Output Open Drain Mode 50MHZ             */

#define  GPIO_MODE_AF_PP_10MHZ          ((uint8_t)0b00001001u)     /*!< Alternate Function Push Pull Mode 10MHZ  */
#define  GPIO_MODE_AF_PP_2MHZ           ((uint8_t)0b00001010u)     /*!< Alternate Function Push Pull Mode 2MHZ   */
#define  GPIO_MODE_AF_PP_50MHZ          ((uint8_t)0b00001011u)     /*!< Alternate Function Push Pull Mode 50MHZ  */

#define  GPIO_MODE_AF_OD_10MHZ          ((uint8_t)0b00001101u)     /*!< Alternate Function Open Drain Mode 10MHZ */
#define  GPIO_MODE_AF_OD_2MHZ           ((uint8_t)0b00001110u)     /*!< Alternate Function Open Drain Mode 2MHZ  */
#define  GPIO_MODE_AF_OD_50MHZ          ((uint8_t)0b00001111u)     /*!< Alternate Function Open Drain Mode 50MHZ */

#define  GPIO_MODE_AF_INPUT             GPIO_MODE_INPUT_F          /*!< Alternate Function Input Mode            */

/**
  * @}
  */


/** @defgroup GPIO_PIN_STATUS GPIO pin status
  * @brief  GPIO Bit SET and Bit RESET
  * @{
  */

#define GPIO_PIN_RESET          ((uint8_t)0x00u)    
#define GPIO_PIN_SET            ((uint8_t)0x01u)

/**
  * @}
  */

/** @defgroup GPIO_PIN_LOCK GPIO pin lock status
  * @brief  GPIO Bit locked done and Bit lock error
  * @{
  */

#define GPIO_PIN_LOCK_DONE          ((uint8_t)0x00u)    
#define GPIO_PIN_LOCK_ERROR         ((uint8_t)0x01u)

/**
  * @}
  */



/**
 * @brief Initialize GPIO Pin
 * 
 * @param GPIOx : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Mode  : Specifies the operating mode for the selected pins.
 *                This parameter can be a value of @ref GPIO_mode_define
 * @param Pin   : Specifies the GPIO pins to be configured.
 *                This parameter can be any value of @ref GPIO_pins_define 
 */
void GPIO_Init(GPIOx_t * GPIOx, uint8_t Mode, uint16_t Pin);


/**
 * @brief Deinitialize GPIO Port
 * 
 * @param GPIOx : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 */
void GPIO_Reset(GPIOx_t * GPIOx);


/**
 * @brief Read Pin Status 0 or 1 From GPIOx
 * 
 * @param GPIOx     : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Pin       : Specifies the GPIO pins to be configured.
 *                    This parameter can be any value of @ref GPIO_pins_define 
 * @return uint8_t  : GPIO Bit SET and Bit RESET
 */
uint8_t GPIO_Read_Pin(GPIOx_t * GPIOx, uint16_t Pin);


/**
 * @brief Read Port From GPIOx
 * 
 * @param GPIOx         : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @return uint16_t     : GPIO Port Value
 */
uint16_t GPIO_Read_Port(GPIOx_t * GPIOx);


/**
 * @brief Write Status to pin in GPIOx
 * 
 * @param GPIOx         : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Pin           : Specifies the GPIO pins to be configured.
 *                        This parameter can be any value of @ref GPIO_pins_define 
 * @param Pin_Status    : Specifies the GPIO pin status.
 *                        This parameter can be any value of @ref GPIO_PIN_STATUS 
 */
void GPIO_Write_Pin(GPIOx_t * GPIOx, uint16_t Pin, uint8_t Pin_Status);


/**
 * @brief Write Port Value in GPIOx
 * 
 * @param GPIOx         : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Port_Value    : Specifies the GPIO Port Value.
 */
void GPIO_Write_Port(GPIOx_t * GPIOx, uint16_t Port_Value);


/**
 * @brief Toggle Pin in GPIOx
 * 
 * @param GPIOx : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Pin   : Specifies the GPIO pin status.
 *                This parameter can be any value of @ref GPIO_PIN_STATUS 
 */
void GPIO_Toggle_Pin(GPIOx_t * GPIOx, uint16_t Pin);


/**
 * @brief Locks Pin in GPIOx
 * 
 * @param GPIOx     : Specifies which GPIO Instants GPIOA, GPIOB, GPIOC, ...
 * @param Pin       : Specifies the GPIO pin status.
 *                    This parameter can be any value of @ref GPIO_PIN_STATUS 
 * @return uint8_t  : GPIO Pin Lock done or error
*/
uint8_t GPIO_Lock_Pin(GPIOx_t * GPIOx, uint16_t Pin);






#endif