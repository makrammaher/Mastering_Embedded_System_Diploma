/*
 *           File: main.c
 *     Created on: Saturday 23/04/2022 21:09
 *         Author: Makram Maher Makram
 *        Subject: Create Student database using generic LinkedList
 *
 *
 */

#include <stdio.h>
#include "student.h"

int main(void)
{
    char temp_text[40];
    studentList_Init();
    while(1)
    {
        printf("\n======================================================");
        printf("\n\tChoose on of the following options\n");
        printf("\n 1:  Add New Student");
        printf("\n 2:  View Student by (ID)");
        printf("\n 3:  View Student by (Index)");
        printf("\n 4:  View Student by (Index From End)");
        printf("\n 5:  View Middle Student");
        printf("\n 6:  View All Students");
        printf("\n 7:  Get Length of List Method(1)");
        printf("\n 8:  Get Length of List Method(2)");
        printf("\n 9:  Check for List Loop");
        printf("\n 10: Reverse List");
        printf("\n 11: Delete Student by (ID)");
        printf("\n 12: Delete Student by (Index)");
        printf("\n 13: Delete All Students");
        printf("\n Enter Option Number: ");

        gets(temp_text);

        switch(atoi(temp_text))
        {
            case 1:
            studentList_Add();
            break;
            case 2:
            studentList_Get_By_ID();
            break;
            case 3:
            studentList_Get_By_Index();
            break;
            case 4:
            studentList_Get_By_Index_End();
            break;
            case 5:
            studentList_View_Middle();
            break;
            case 6:
            studentList_View_All();
            break;
            case 7:
            studentList_Get_length_Method_1();
            break;
            case 8:
            studentList_Get_length_Method_2();
            break;
            case 9:
            studentList_Check_Loop();
            break;
            case 10:
            studentList_Reverse_List();
            break;
            case 11:
            studentList_Delete();
            break;
            case 12:
            studentList_Delete_By_Index();
            break;
            case 13:
            studentList_Delete_All();
            break;
            default:
            break;

        }
    }
    

    return 0;
}