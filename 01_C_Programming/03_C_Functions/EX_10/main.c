/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>
#include<string.h>

unsigned int str_to_uint(char a[], unsigned int len);

int main(void)
{
	unsigned int uint_num;
	char str[9] =
	{ 0 };

	printf("Enter a number as ASCII: ");
	fflush(stdin);
	fflush(stdout);
	fgets(str, 9, stdin);
	str[strlen(str) - 1] = 0;

	uint_num = str_to_uint(str, strlen(str));
	printf("the number is as unsigned int = %u\n\n", uint_num);
	return 0;
}

unsigned int str_to_uint(char a[], unsigned int len)
{
	unsigned int result = 0;
	unsigned int i,j;
	unsigned int tenth;
	for(i = 0;i<len;i++)
	{
		tenth = 1;
		for(j = 1;j<len-i;j++)
		{
			tenth *= 10;
		}
		result += (a[i] - '0') * tenth;
	}
	return result;
}
