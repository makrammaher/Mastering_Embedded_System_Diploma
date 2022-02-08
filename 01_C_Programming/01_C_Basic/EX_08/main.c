/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void) {
	unsigned int number;

	for (int i = 0; i <= 2; i++) {
		printf("Enter an integer you want to check: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%u", &number);
		if (number % 2 == 0) {
			printf("%u is Even.\n", number);
		} else {
			printf("%u is Odd.\n", number);
		}
	}
}
