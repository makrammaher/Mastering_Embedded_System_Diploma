/*
 *           File: uart.c
 *     Created on: Saturday 02/04/2022 18:36
 *         Author: Makram Maher Makram
 *        Subject:
 *
 *
 */

#include "uart.h"

void UART_Send_String(const char * P_tx_string)
{
	while (*P_tx_string != '\0')
	{
		UART0DR = (unsigned long)(*P_tx_string);
		P_tx_string++;
	}
}