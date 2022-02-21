/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int clearBit(int number, int position);

int main(void)
{
	int number;
	int position;
	printf("Enter a number and position: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d%d", &number, &position);
	number = clearBit(number, position);
	printf("result = %d", number);
	return 0;
}

int clearBit(int number, int position)
{
	number &= ~(1 << position);
	return number;
}
