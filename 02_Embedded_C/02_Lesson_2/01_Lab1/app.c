/*
 *           File: main.c
 *     Created on: Saturday 02/04/2022 18:36
 *         Author: Makram Maher Makram
 *        Subject: Simple application send string by UART of ARM926EJ-S (Verstilebp)
 *
 *
 */

#include "uart.h"

/* Global String hold the message to be send */
char gstring[100] = "Learn-In-Depth: Makram Maher Makram :)";

void main(void)
{
	/* Send message using UART */
	UART_Send_String(gstring);
}