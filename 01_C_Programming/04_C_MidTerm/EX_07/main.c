/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

unsigned int sumFunction(unsigned int number);

int main(void)
{
	unsigned int num, sum;
	printf("Enter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%u", &num);
	sum = sumFunction(num);
	printf("%u\n", sum);
	return 0;
}

unsigned int sumFunction(unsigned int number)
{
	if(number > 0)
		return number + sumFunction(number - 1);
	else
		return 0;
}
