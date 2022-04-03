/*
 *           File: uart.h
 *     Created on: Saturday 02/04/2022 18:36
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */


#ifndef _UART_H_
#define _UART_H_
	
	#define UART0DR *((volatile unsigned long * const)(0x101f1000))

	void UART_Send_String(const char * P_tx_string);

#endif