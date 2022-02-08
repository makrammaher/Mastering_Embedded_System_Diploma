/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void) {
	char input;

	for (int i = 0; i < 2; i++) { //for two test cases
		printf("Enter an alphabet: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c", &input);
		if (input == 'a' || input == 'e' || input == 'i'
				|| input == 'o' || input == 'u') {
			printf("%c is vowel.\n", input);
		} else {
			printf("%c is consonant.\n", input);
		}
	}
}
