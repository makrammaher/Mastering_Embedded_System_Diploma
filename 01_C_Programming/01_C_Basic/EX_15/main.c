/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	char opr;
	float num1, num2;
	float result;
	printf("Enter operator either + or - or * or /: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &opr);
	printf("Enter two operands: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f%f", &num1, &num2);
	switch (opr)
	{
	case '+':
		result = num1 + num2;
		printf("%.1f %c %.1f = %.1f\n", num1, opr, num2, result);
		break;
	case '-':
		result = num1 - num2;
		printf("%.1f %c %.1f = %.1f\n", num1, opr, num2, result);
		break;
	case '*':
		result = num1 * num2;
		printf("%.1f %c %.1f = %.1f\n", num1, opr, num2, result);
		break;
	case '/':
		result = num1 / num2;
		printf("%.1f %c %.1f = %.1f\n", num1, opr, num2, result);
		break;
	default:
		printf("Error!!! Wrong Operator\n");
		break;
	}
}
