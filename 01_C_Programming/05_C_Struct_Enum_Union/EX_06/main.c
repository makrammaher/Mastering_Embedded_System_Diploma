/*
 * main.c
 *
 *  Created on: Mar 5, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

union job{
	char name[32];
	float salary;
	int worker_no;
}u;

struct job1{
	char name[32];
	float salary;
	int worker_no;
}s;

int main(void)
{
	printf("size of union  = %d\n", sizeof(u));
	printf("size of struct = %d\n", sizeof(s));

	return 0;
}
