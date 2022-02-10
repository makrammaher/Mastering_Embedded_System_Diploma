/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	char str[100];
	unsigned int i;
	unsigned int length = 0;

	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);

	for (i = 0; i < 100 && str[i] != 0; i++)
	{
		length++;
	}

	printf("Length of string = %u\n", length);
}
