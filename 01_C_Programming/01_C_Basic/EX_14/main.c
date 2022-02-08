/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	int n;
	for (int i = 0; i < 2; i++)
	{
		unsigned long long factorial = 1;
		printf("Enter an integer: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &n);
		if (n >= 0)
		{
			for (int i = 1; i <= n; i++)
			{
				factorial *= i;
			}
			printf("Factorial = %lu\n", factorial);
		}
		else
		{
			printf("Error!!! Factorial of negative number doesn't exist.\n");
		}
	}
}
