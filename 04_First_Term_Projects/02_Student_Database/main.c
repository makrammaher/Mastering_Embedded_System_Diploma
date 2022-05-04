/*
 *           File: main.c
 *     Created on: Tuesday 03/05/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Student DataBase Using Circular Queue
 *
 *
 */

#include <stdio.h>
#include "student.h"

int main(void)
{
    char temp_text[5];
    student_Init();
    printf("\n======================================================");
    printf("\n       Welcome to the student management system");
    while (1)
    {
        printf("\n======================================================");
        printf("\n\tChoose one of the following options\n");
        printf("\n 1 : Add a Student Manually");
        printf("\n 2 : Add Students From Text File");
        printf("\n 3 : View Students Details by (Roll Number)");
        printf("\n 4 : View Students Details by (First Name)");
        printf("\n 5 : View Students Details by (Course ID)");
        printf("\n 6 : View All Students Details");
        printf("\n 7 : View Total Number of Students");
        printf("\n 8 : Update a Student Details by (Roll Number)");
        printf("\n 9 : Delete a Student Details by (Roll Number)");
        printf("\n 10: Save Student Details To Text File");
        printf("\n Enter Option Number: ");

        gets(temp_text);

        printf("--------------------------------------\n");
        switch (atoi(temp_text))
        {
        case 1:
            student_Add_Manually();
            break;

        case 2:
            student_Add_File();
            break;

        case 3:
            student_Find_RollNumber();
            break;

        case 4:
            student_Find_FirstName();
            break;

        case 5:
            student_Find_CourseID();
            break;

        case 6:
            student_Print_All_Students();
            break;

        case 7:
            student_View_Number_Students();
            break;

        case 8:
            student_Update_RollNumber();
            break;

        case 9:
            student_Delete_RollNumber();
            break;

        case 10:
            student_Save_File();
            break;

        default:
            break;
        }
    }
    return 0;
}