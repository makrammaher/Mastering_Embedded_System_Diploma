/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

unsigned int reverseNumber(unsigned int number);

int main(void)
{
	unsigned int num, rnum;
	printf("Enter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%u", &num);
	rnum = reverseNumber(num);
	printf("%u\n", rnum);

}

unsigned int reverseNumber(unsigned int number)
{
	unsigned int new = 0;
	unsigned int i;
	unsigned char flag = 0;
	unsigned int multiplier = 1;
	for (i = 1000000; i >= 1; i /= 10)
	{
		if (number / i != 0)
			flag = 1;

		if (flag)
		{
			new += ((number / i) % 10) * multiplier;
			multiplier *= 10;
		}
	}
	return new;
}
