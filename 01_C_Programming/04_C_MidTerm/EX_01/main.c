/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>
unsigned int sumDigits(unsigned int number);

int main(void)
{
	unsigned int number, sum;
	printf("Enter unsigned number: ");
	fflush(stdin);fflush(stdout);
	scanf("%u", &number);
	sum = sumDigits(number);
	printf("sum = %u\n", sum);
	return 0;
}

unsigned int sumDigits(unsigned int number)
{
	unsigned int sum = 0;

	while(number != 0)
	{
		sum += number % 10;
		number /= 10;
	}

	return sum;
}
