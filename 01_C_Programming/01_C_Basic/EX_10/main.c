/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	float input;
	float largest = 0;

	printf("%s", "Enter three number: ");
	for (int i = 0; i < 3; i++)
	{
		fflush(stdin);
		fflush(stdout);
		scanf("%f", &input);
		if (input > largest)
			largest = input;
	}
	printf("Largest number = %.2f", largest);
}
