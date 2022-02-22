/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

unsigned int countOnes(int number);

int main(void)
{
	unsigned int num, ones;
	printf("Enter a number: ");
	fflush(stdin);fflush(stdout);
	scanf("%u", &num);
	ones = countOnes(num);
	printf("%u\n", ones);

}

unsigned int countOnes(int number)
{
	unsigned int counter = 0;

	while(number>0)
	{
		if(number & 1)
			counter++;
		number>>=1;
	}
	return counter;
}
