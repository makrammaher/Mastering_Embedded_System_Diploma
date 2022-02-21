/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int isPrimeNumber(unsigned int num);

int main(void)
{
	unsigned int num1, num2;
	unsigned int i;
	printf("Enter two numbers(intervals): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u%u", &num1, &num2);
	printf("Prime numbers between %u and %u are: ", num1, num2);
	for(i = num1;i<num2;i++)
	{
		if(isPrimeNumber(i))
			printf("%u  ", i);
	}


	return 0;
}

int isPrimeNumber(unsigned int num)
{
	int counter = 0;
	int i;
	for(i=1;i<=num;i++)
	{
		if(num % i == 0)
			counter++;
	}
	if(counter>2)
		return 0;
	else
		return 1;
}
