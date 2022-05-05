#ifndef _DRIVER_H_
#define _DRIVER_H_

#include <stdint.h>

#define SET_BIT(ADDRESS,BIT)   		ADDRESS |=  (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) 		ADDRESS &=~ (1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT) 	ADDRESS ^=  (1<<BIT)
#define READ_BIT(ADDRESS,BIT) 		((ADDRESS) & (1<<(BIT)))

#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(volatile uint32_t *)(BASE_RCC + 0x18)

#define GPIOA_CRL *(volatile uint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile uint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

void Delay(uint32_t nCount);
uint8_t getPressureVal();
void Set_Alarm_actuator(uint8_t i);
void GPIO_INITIALIZATION ();

#endif