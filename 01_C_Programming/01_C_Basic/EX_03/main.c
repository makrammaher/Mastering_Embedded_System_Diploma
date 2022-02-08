/*
 * main.c
 *
 *  Created on: Feb 8, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	unsigned int sum;
	unsigned int num1, num2;

	printf("%s", "Enter two integers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u%u", &num1, &num2);
	sum = num1 + num2;
	printf("sum: %u\n", sum);
}
