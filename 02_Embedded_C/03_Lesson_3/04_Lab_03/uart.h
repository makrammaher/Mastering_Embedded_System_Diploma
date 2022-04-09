/*
 *           File: uart.h
 *     Created on: Saturday 02/04/2022 18:36
 *         Author: Makram Maher Makram
 *        Subject: Simple UART transmitter driver for ARM926EJ-S (Verstilebp)
 *
 *
 */

#ifndef _UART_H_
#define _UART_H_
	
	/* UART0 Data Register Address */
	#define UART0DR	*((volatile unsigned long *)(0x101f1000))

	/* void UART_Send_String(char * P_Tx_String)
	 * Inputs : 
	 *			P_TX_String -- Pointer to string to be send by UART.
	 * Outputs:
	 *			Nothing.
	 */
	void UART_Send_String(char * P_Tx_String);

#endif