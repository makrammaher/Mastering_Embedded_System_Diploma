/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

unsigned long int factorial(unsigned int number);

int main(void)
{
	unsigned int number;
	unsigned long int result;
	printf("Enter a positive integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u", &number);
	result = factorial(number);
	printf("Factorial of %u = %lu\n", number, result);

	return 0;
}

unsigned long int factorial(unsigned int number)
{
	if(number<2)
		return number;
	else
		return number * factorial(number - 1);
}
