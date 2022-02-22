/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

unsigned int maxNumberOnes(int number);

int main(void)
{
	int number;
	printf("Enter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &number);
	printf("Max number of ones = %u\n", maxNumberOnes(number));

	return 0;
}

unsigned int maxNumberOnes(int number)
{
	unsigned int count = 0;

	while(number != 0)
	{
		number &= (number<<1);
		count++;
	}
	return count;
}
