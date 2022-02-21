/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

int lastOccurence(int a[], int size, int num);

int main(void)
{
	int a[] = {1,2,3,4,5,6,4};
	printf("%d", lastOccurence(a, 7, 3));

	return 0;
}

int lastOccurence(int a[], int size, int num)
{
	int i;
	for(i = size-1;i>=0;i--)
	{
		if(a[i] == num)
			return i;
	}
	return 0;
}
