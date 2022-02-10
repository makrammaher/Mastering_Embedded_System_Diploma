/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int main(void)
{
	float matrix1[2][2];
	float matrix2[2][2];
	float sum[2][2];
	int i, r, c;

	for (i = 0; i < 2; i++)
	{
		printf("Enter the elements of the 1st matrix\n");
		for (r = 0; r < 2; r++)
		{
			for (c = 0; c < 2; c++)
			{
				printf("Enter Matrix(%d)[%d][%d]:", i, r, c);
				fflush(stdin);
				fflush(stdout);
				if (i == 0)
					scanf("%f", &matrix1[r][c]);
				else
					scanf("%f", &matrix2[r][c]);
			}
		}
	}

	printf("\nSum of Matrix:\n");
	for (r = 0; r < 2; r++)
	{
		for (c = 0; c < 2; c++)
		{
			sum[r][c] = matrix1[r][c] + matrix2[r][c];
			printf("%.1f\t",sum[r][c]);
		}
		printf("\n");
	}
}
