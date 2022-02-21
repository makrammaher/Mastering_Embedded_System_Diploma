/*
 * main.c
 *
 *  Created on: Feb 21, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>
#include<string.h>

int main(void)
{
	char USERNAME[] = "makram_maher";
	char inputString[20] = {0};

	printf("Enter the user_name of max 20 char: ");
	fflush(stdin);
	fflush(stdout);
	fgets(inputString, 20, stdin);
	inputString[strlen(inputString) - 1] = 0;
	if(strcmp(USERNAME, inputString) == 0)
	{
		printf("the same as USERNAME\n");
	}
	else
	{
		printf("Not same as USERNAME\n");
	}

}
