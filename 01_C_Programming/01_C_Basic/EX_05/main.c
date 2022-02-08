/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void) {
	char input;
	printf("%s", "Enter a character: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &input);
	printf("ASCII value of %c = %d", input, input);
}
