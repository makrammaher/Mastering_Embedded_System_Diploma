/*
 * main.c
 *
 *  Created on: Mar 1, 2022
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
	struct SStudent student;
	printf("%s", "Enter information of students:\n\n");
	printf("Enter name:");
	fflush(stdin);fflush(stdout);
	scanf("%s", student.m_name);
	printf("Enter roll number:");
	fflush(stdin);fflush(stdout);
	scanf("%u", &student.m_roll);
	printf("Enter marks:");
	fflush(stdin);fflush(stdout);
	scanf("%f", &student.m_marks);
	printf("%s", "\nDisplaying Information\n");
	printf("Name:  %s\n", student.m_name);
	printf("Roll:  %u\n", student.m_roll);
	printf("Marks: %.2f\n", student.m_marks);

	return 0;
}
