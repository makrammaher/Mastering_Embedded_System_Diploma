/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>
#include<string.h>

void reverse(char* str, unsigned int len);
int main(void)
{
	char str[100];
	printf("Enter a sentence: ");
	fflush(stdin);
	fflush(stdout);
	gets(str);
	reverse(str, strlen(str));
	return 0;
}

void reverse(char* str, unsigned int len)
{
	if(len > 0)
	{
		printf("%c", str[len-1]);
		reverse(str,len-1);
	}
}
