/*
 * main.c
 *
 *  Created on: Feb 8, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

int main(void)
{
	int number;

	printf("%s","Enter an integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &number);

	printf("You Entered: %d\n", number);
}
