/*
 *           File: main.c
 *     Created on: Saturday 02/04/2022 18:36
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */

#include "uart.h"

char string_buff[100] = "Learn-in-depth:< Makram Maher >";

void main(void)
{
    UART_Send_String(string_buff);
}