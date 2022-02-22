/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>
#include<math.h>
float squareRoot(int number);

int main(void)
{
	unsigned int number;
	float result;
	printf("Enter number: ");
	fflush(stdin);fflush(stdout);
	scanf("%u", &number);
	result = squareRoot(number);
	printf("result = %.3f\n", result);
	return 0;
}

float squareRoot(int number)
{
	return sqrt(number);
}
