/*
 * 	 	  File: main.c
 *  Created on: Mar 7, 2022
 *      Author: Makram Maher
 *     Subject: Testing anything else in macros and using __VA_ARGS__
 *				
 */


#include<stdio.h>

#define print(...)	printf(__VA_ARGS__)
#define printInt(a) printf("%d\n", a);
#define rprintf(a,...)	printf(__VA_ARGS__, a);

int main(void)
{

	print("I am printing from c program using\n print() function not printf()\nHere an example for using %%d %d\n", 10);
	printInt(1234);
	printInt(4213);
	rprintf(1,"%d\n");

	return 0;
}