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
	char rstr[100];
	unsigned int i;
	unsigned int length = 0;

	printf("Enter the string: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);

	for (i = 0; i < 100 && str[i] != 0; i++)
	{
		length++;
	}
	for(i = 0;i<100&&length!=0;i++)
	{
		rstr[i] = str[--length];
	}
	rstr[i] = 0;

	printf("Reverse string is:%s\n", rstr);
}
