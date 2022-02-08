/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	char input;

	for (int i = 0; i < 2; i++)
	{
		printf("%s", "Enter a character: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c", &input);
		if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		{
			printf("%c is an alphabet\n", input);
		}
		else
		{
			printf("%c is not alphabet\n", input);
		}
	}
}
