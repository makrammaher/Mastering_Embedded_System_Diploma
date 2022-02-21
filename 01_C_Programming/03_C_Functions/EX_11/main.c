/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

int powerOfThree(int number);

int main(void)
{
	int num;
	int result;
	printf("Enter number:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &num);
	result = powerOfThree(num);
	printf("the result = %d", result);

	return 0;
}

int powerOfThree(int number)
{
	return !(number > 0 && 1162261467 % number == 0);
}
