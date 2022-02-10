/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

int main(void)
{
	float num[100];
	float sum = 0;
	float average;
	unsigned int n;
	unsigned int i;

	printf("Enter the number of data (Max 100): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%u", &n);

	for(i = 0;i<n;i++)
	{
		printf("%u. Enter number: ", i+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f", &num[i]);
		sum += num[i];
	}
	average = sum / n;
	printf("Average = %.2f\n", average);
}
