/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>
void printReverseArray(int a[], unsigned int size);

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	printReverseArray(a, 6);
}

void printReverseArray(int a[], unsigned int size)
{
	if (size > 0)
	{
		printf("%d  ", a[size - 1]);
		printReverseArray(a, size - 1);
	}
}
