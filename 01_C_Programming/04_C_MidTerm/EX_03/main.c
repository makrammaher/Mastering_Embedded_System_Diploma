/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>
#include<math.h>
void printPrimeNumbers(int num1, int num2);
int checkPrime(unsigned int number);

int main(void)
{
	unsigned int num1, num2;
	printf("Enter 2 number(intervals): ");
	fflush(stdin);fflush(stdout);
	scanf("%u%u", &num1, &num2);
	printPrimeNumbers(num1,num2);
	return 0;
}

void printPrimeNumbers(int num1, int num2)
{
	int i;
	if(num1>num2)
	{
		int temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	for(i = num1;i<=num2;i++)
	{
		if(checkPrime(i))
			printf("%d  ", i);
	}

}

int checkPrime(unsigned int number)
{
	int i,counter = 0;
	for(i = 2;i<number;i++)
	{
		if(number%i == 0)
		{
			counter++;
		}
	}
	return counter>=1?0:1;
}

