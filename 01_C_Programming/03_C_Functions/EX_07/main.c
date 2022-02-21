/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

void swapArrays(int a[], int b[], unsigned int sizea, unsigned int sizeb);

int main(void)
{
	int a[5] =
	{ 1, 2, 3, 4, 5 };
	int b[3] =
	{ 3, 4, 5 };

	swapArrays(a,b,5,3);

	int i;
	for(i = 0;i<5;i++)
	{
		printf("%d  ", a[i]);
	}
	puts("");
	for(i = 0;i<3;i++)
	{
		printf("%d  ", b[i]);
	}

	return 0;
}


void swapArrays(int a[], int b[], unsigned int sizea, unsigned int sizeb)
{
	int size = sizea < sizeb ? sizea : sizeb;
	int i, temp;

	for(i = 0;i<size;i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}

}
