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
	char ch;
	unsigned int i;
	unsigned int freq = 0;

	printf("Enter a string: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);
	printf("Enter a character to find frequency: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &ch);

	for (i = 0; i < 100 && str[i] != 0; i++)
	{
		if (str[i] == ch)
		{
			freq++;
		}
	}

	printf("Frequency of %c = %u\n", ch, freq);

}
