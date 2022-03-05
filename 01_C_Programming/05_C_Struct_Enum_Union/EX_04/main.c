/*
 * main.c
 *
 *  Created on: Mar 5, 2022
 *      Author: Makram Maher
 */


#include<stdio.h>

struct SStudent{
	char m_name[20];
	unsigned int m_roll;
	float m_marks;
};

int main(void)
{
	struct SStudent students[10];
	unsigned int i;

	//get information from user
	printf("\nEnter information of students:\n\n");
	for(i = 0;i<sizeof(students)/sizeof(students[0]);i++)
	{
		students[i].m_roll = i+1;
		printf("For roll number: %u\n", i+1);
		printf("Enter name: ");
		fflush(stdin);fflush(stdout);
		fgets(students[i].m_name, 20, stdin);
		printf("Enter marks: ");
		fflush(stdin);fflush(stdout);
		scanf("%f", &students[i].m_marks);
		printf("\n");
	}

	//printing information
	printf("\nDisplaying information of students:\n\n");
	for(i = 0;i<sizeof(students)/sizeof(students[0]);i++)
	{
		printf("Information for roll number: %u\n", students[i].m_roll);
		printf("Name: %s", students[i].m_name);
		printf("Marks: %.1f\n\n", students[i].m_marks);
	}

	return 0;
}
