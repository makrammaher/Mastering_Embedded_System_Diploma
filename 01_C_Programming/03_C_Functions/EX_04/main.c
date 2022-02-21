/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

unsigned int long power(int number, unsigned int power);

int main(void)
{
	int number;
	unsigned int powernum;
	unsigned long int result;
	printf("Enter base number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &number);
	printf("Enter power number(positive integer): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u", &powernum);

	result = power(number, powernum);
	printf("%d^%u = %lu", number, powernum, result);

	return 0;
}

unsigned int long power(int number, unsigned int powernum)
{
	if (powernum == 1)
		return number;
	else
		return number * power(number, powernum - 1);
}
