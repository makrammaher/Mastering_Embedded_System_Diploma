/*
 * main.c
 *
 *  Created on: Mar 5, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>

#define circleArea(r) r*r*3.14159

int main(void)
{
	unsigned int radius;
	printf("Enter the radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%u", &radius);
	printf("Area = %.2f\n", circleArea(radius));

	return 0;
}
