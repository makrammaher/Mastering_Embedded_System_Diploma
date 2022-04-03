/*
 *           File: uart.c
 *     Created on: Saturday 02/04/2022 18:36
 *         Author: Makram Maher Makram
 *        Subject: Simple UART transmitter driver for ARM926EJ-S (Verstilebp)
 *
 *
 */

#include "uart.h"

void UART_Send_String(char * P_Tx_String)
{
	while(*P_Tx_String != '\0')
	{
		/* Loop until end of string null terminator '\0' */
		/* Assign UART Data Register to pointed byte */
		UART0DR = (volatile unsigned long) (*P_Tx_String);
		/* Increment Pointer to next byte */
		P_Tx_String++;
	}
}