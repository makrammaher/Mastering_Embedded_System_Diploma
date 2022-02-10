/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	int num[10];
	int newElement;
	unsigned int n;
	unsigned int loc;
	unsigned int i;

	printf("Enter no of element(Max 10): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u", &n);
	for (i = 0; i < n; i++)
	{
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &num[i]);
	}

	printf("Enter the element to be inserted: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &newElement);
	printf("Enter the location: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u", &loc);

	for (i = n; i > loc; i--)
	{
		num[i] = num[i - 1];
	}
	num[loc-1] = newElement;
	n++;
	for (i = 0; i < n; i++)
	{
		printf("%d ", num[i]);
	}

}
