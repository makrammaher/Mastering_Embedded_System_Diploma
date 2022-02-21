/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>
int b4th_bit(int number);

int main(void)
{
	int num;
	int b4thbit;
	printf("Enter a number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);
	b4thbit = b4th_bit(num);
	printf("4th bit of number %d is %d", num, b4thbit);
	return 0;
}

int b4th_bit(int number)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		number = number / 2;
	}
	return number % 2;
}
