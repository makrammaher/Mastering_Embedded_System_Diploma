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
	int element;
	unsigned int n;
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

	printf("Enter the Element to be searched: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u", &element);

	for(i = 0;i<n;i++)
	{
		if(num[i] == element)
		{
			break;
		}
	}
	if(i<n)
	{
		printf("Number found at location = %u\n", i+1);
	}
	else
	{
		printf("Number not found\n");
	}

}
