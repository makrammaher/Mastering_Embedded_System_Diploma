/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void) {
	float num1, num2;
	float resut;

	printf("%s", "Enter two numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f%f", &num1, &num2);
	resut = num1 * num2;
	printf("Product = %f\n", resut);
}
