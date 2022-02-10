/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	int matrix[10][10];
	int tMatrix[10][10];
	int r, c, i, j;

	printf("Enter rows and columns of matrix(Max 10): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d%d", &r, &c);

	printf("Enter elements of matrix:\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("Enter Element[%d][%d]: ", i, j);
			fflush(stdin);
			fflush(stdout);
			scanf("%d", &matrix[i][j]);
			tMatrix[j][i] = matrix[i][j];
		}
	}

	printf("Entered Matrix:\n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}

	printf("\nTranspose Matrix:\n");
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			printf("%d\t", tMatrix[i][j]);
		}
		printf("\n");
	}

}
