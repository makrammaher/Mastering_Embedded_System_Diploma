/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

int uniqueNumber(int array[], unsigned int size);

int main(void)
{
	int num[20], unique;
	unsigned int i, size;
	printf("Enter a size of array: ");
	fflush(stdin);fflush(stdout);
	scanf("%u", &size);
	printf("Enter %u Elements of the array: ", size);
	for(i=0;i<size;i++)
	{
		fflush(stdin);fflush(stdout);
		scanf("%u", &num[i]);
	}

	unique = uniqueNumber(num, size);
	printf("Unique = %d\n", unique);

}

int uniqueNumber(int array[], unsigned int size)
{
	unsigned int result = 0;
	unsigned int i = 0;
	for(i = 0;i<size;i++)
	{
		result^=array[i];
	}

	return result;
}
