

#include "driver.h"

void Delay(uint32_t nCount)
{
	for (; nCount != 0; nCount--);
}

uint8_t getPressureVal()
{
	return (GPIOA_IDR & 0xFF);
}

void Set_Alarm_actuator(uint8_t i)
{
	if (i == 1) {
		SET_BIT(GPIOA_ODR, 13);
	}
	else if (i == 0) {
		RESET_BIT(GPIOA_ODR, 13);
	}
}

void GPIO_INITIALIZATION ()
{
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
