/*
 * 	 	  File: main.c
 *  Created on: Mar 7, 2022
 *      Author: Makram Maher
 *     Subject: Testing Gcc
 *				We can use powershell to compile this file by using this commands
 *				gcc -E main.c -o main.i  	--> Preprocessing stage only
 *				gcc -S main.c -o main.s 	--> Compile stage only
 *				gcc -c main.c -o main.o 	--> Assimble stage only but not linking
 *				gcc main.c -o main.exe		--> Full comniling process
 */



#include<stdio.h>

#define TEST_PREPROCESS 10
#define MACRO(x) x+10

int main(void)
{
	printf("Hello World\n");
	printf("TEST_PREPROCESS = %d\n", TEST_PREPROCESS);
    printf("Test Macro(10) = %d\n", MACRO(10));
	return 0;
}