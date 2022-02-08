/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

int main(void)
{
	float a, b;
	printf("%s", "Enter value of a: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &a);
	printf("%s", "Enter value of b: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &b);
	//swapping Here
	a += b;
	b = a - b;
	a = a - b;

	printf("After swapping, value of a = %.2f\n", a);
	printf("After swapping, value of b = %.2f\n", b);
}
