/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	float number;

	for (int i = 0; i < 3; i++)
	{
		printf("%s", "Enter a number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f", &number);
		if (number < 0)
		{
			printf("%.2f is Negative\n", number);
		}
		else if (number > 0)
		{
			printf("%.2f is Positive\n", number);
		}
		else
		{
			printf("You Entered ZERO\n");
		}
	}
}
