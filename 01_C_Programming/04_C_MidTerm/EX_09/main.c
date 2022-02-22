/*
 * main.c
 *
 *  Created on: Feb 22, 2022
 *      Author: Makram Maher
 */

#include<stdio.h>
#include<string.h>

void reverseWords(char inStr[], char outStr[]);

int main(void)
{
	char strin[50] = "mohamed gamal";
	char strout[50];

	reverseWords(strin,strout);
	printf("%s", strout);

	return 0;
}

void reverseWords(char inStr[], char outStr[])
{
	unsigned int len = strlen(inStr);
	unsigned int i, j, outindex = 0;

	i = len - 1;
	while (i > 0)
	{
		while (inStr[i] != ' ' && i != 0)
		{
			i--;
		}
		if(i > 0)
		{
			j = i + 1;
			i--;
		}
		else
		{
			j = 0;
		}

		while (inStr[j] != 0 && inStr[j] != ' ')
		{
			outStr[outindex++] = inStr[j++];
		}
		if (i > 0)
		{
			outStr[outindex++] = ' ';
		}
		else
		{
			outStr[outindex++] = 0;
		}
	}
}
