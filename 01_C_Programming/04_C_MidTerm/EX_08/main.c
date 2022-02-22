/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

void reverseArray(int arr[], unsigned int size);

int main(void)
{
	int num[20];
	unsigned int i, size;
	printf("Enter a size of array: ");
	fflush(stdin);fflush(stdout);
	scanf("%u", &size);
	printf("Enter %u Elements of the array: ", size);
	for (i = 0; i < size; i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%u", &num[i]);
	}
	printf("Reverse Array : ");
	reverseArray(num, size);

	return 0;
}

void reverseArray(int arr[], unsigned int size)
{
	if (size > 0)
	{
		printf("%d  ", arr[size - 1]);
		reverseArray(arr, size - 1);
	}
}
