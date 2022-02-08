/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	unsigned int n;
	unsigned int sum = 0;

	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u", &n);
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	printf("Sum = %u", sum);
}
