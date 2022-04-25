/*
 *           File: student.c
 *     Created on: Saturday 23/04/2022 21:09
 *         Author: Makram Maher Makram
 *        Subject: Create Student database using generic LinkedList
 *
 *
 */

#include "student.h"

static linked_list_t studentList;

uint8_t StudentConditionFun(void *studentPTR, void *IDPTR)
{
    if (((student_t *)studentPTR)->id == *((uint16_t *)IDPTR))
        return 1;
    else
        return 0;
}

void StudentPrintAll(void *studentPTR, uint16_t index)
{
    printf("\n Index: \t%d\n", index);
    printf(" ID: \t\t%d\n", ((student_t *)studentPTR)->id);
    printf(" Name: \t\t%s\n", ((student_t *)studentPTR)->name);
    printf(" Height:\t%.2f\n", ((student_t *)studentPTR)->height);
}

void studentList_Init(void)
{
    linked_list_Init(&studentList, sizeof(student_t));
}

void studentList_Add(void)
{
    char temp_text[40];
    student_t new_student;

    printf("\n Enter The ID: ");
    gets(temp_text);
    new_student.id = atoi(temp_text);

    printf(" Enter The Fullname: ");
    gets(new_student.name);

    printf(" Enter The Height: ");
    gets(temp_text);
    new_student.height = atof(temp_text);

    if (linked_list_Add(&studentList, &new_student) == LINKED_LIST_no_error)
    {
        printf(" Add New Student is Done\n");
    }
}

void studentList_Delete(void)
{
    uint16_t selectedID;
    char temp_text[10];

    printf("\n Enter The ID To Be Deleted: ");
    gets(temp_text);
    selectedID = atoi(temp_text);

    uint16_t index = linked_list_Search(&studentList, StudentConditionFun, &selectedID);
    if (((int16_t)index) == -1)
    {
        printf("\n Not Found !");
        return;
    }
    else
    {
        printf("\n Found in index = %d", index);
        if (linked_list_Delete_Index(&studentList, index) == LINKED_LIST_no_error)
            printf("\n Delete Student Is Done\n");
    }
}

void studentList_Delete_By_Index(void)
{
    uint16_t Index;
    char temp_text[10];

    printf("\n Enter The Index To Be Deleted: ");
    gets(temp_text);
    Index = atoi(temp_text);
    if (linked_list_Delete_Index(&studentList, Index) == LINKED_LIST_no_error)
        printf("\n Delete Student Is Done\n");
    else
    {
        printf("\n Not Found !");
    }
}

void studentList_Delete_All(void)
{
    if (linked_list_Delete_All(&studentList) == LINKED_LIST_no_error)
        printf("\n Delete all Students is Done\n");
}

void studentList_View_All(void)
{
    linked_list_Print(&studentList, StudentPrintAll);
}

void studentList_Get_By_Index(void)
{
    uint16_t index;
    student_t *studentPTR = NULL;
    char temp_text[10];

    printf("\n Enter The Index Of Student To Show: ");
    gets(temp_text);
    index = atoi(temp_text);
    if (linked_list_Get_By_Index(&studentList, index, (void**)&studentPTR) == LINKED_LIST_no_error)
    {
        printf("\n Index: \t%d\n", index);
        printf(" ID: \t\t%d\n", ((student_t *)studentPTR)->id);
        printf(" Name: \t\t%s\n", ((student_t *)studentPTR)->name);
        printf(" Height:\t%.2f\n", ((student_t *)studentPTR)->height);
    }
    else
    {
        printf("\n Not Found !");
    }
}

void studentList_Get_By_Index_End(void)
{
    uint16_t index;
    student_t *studentPTR = NULL;
    char temp_text[10];

    printf("\n Enter The Index From End Of Student To Show: ");
    gets(temp_text);
    index = atoi(temp_text);
    if (linked_list_Get_By_Index_From_End(&studentList, index, (void**)&studentPTR) == LINKED_LIST_no_error)
    {
        printf("\n Index(END): \t%d\n", index);
        printf(" ID: \t\t%d\n", ((student_t *)studentPTR)->id);
        printf(" Name: \t\t%s\n", ((student_t *)studentPTR)->name);
        printf(" Height:\t%.2f\n", ((student_t *)studentPTR)->height);
    }
    else
    {
        printf("\n Not Found !");
    }
}

void studentList_Get_By_ID(void)
{
    uint16_t selectedID;
    student_t *studentPTR = NULL;
    char temp_text[10];

    printf("\n Enter The ID Of Student To Show: ");
    gets(temp_text);
    selectedID = atoi(temp_text);

    uint16_t index = linked_list_Search(&studentList, StudentConditionFun, &selectedID);
    if (((int16_t)index) == -1)
    {
        printf("\n Not Found !");
        return;
    }
    else
    {
        printf("\n Found in index = %d", index);
        if (linked_list_Get_By_Index(&studentList, index, (void**)&studentPTR) == LINKED_LIST_no_error)
        {
            printf("\n Index: \t%d\n", index);
            printf(" ID: \t\t%d\n", studentPTR->id);
            printf(" Name: \t\t%s\n", studentPTR->name);
            printf(" Height:\t%.2f\n", studentPTR->height);
        }
        else
        {
            printf("\n Not Found !");
        }
    }
}

void studentList_View_Middle(void)
{
    student_t *studentPTR = NULL;
    if (linked_list_Get_Middle(&studentList, (void**)&studentPTR) == LINKED_LIST_no_error)
    {
        printf("\n The Middle Student in List is");
        printf("\n ID: \t\t%d\n", ((student_t *)studentPTR)->id);
        printf(" Name: \t\t%s\n", ((student_t *)studentPTR)->name);
        printf(" Height:\t%.2f\n", ((student_t *)studentPTR)->height);
    }
    else
    {
        printf("\n Not Found !");
    }
}

void studentList_Get_length_Method_1(void)
{
    uint16_t length;

    if (linked_list_Get_Length_count(&studentList, &length) == LINKED_LIST_no_error)
    {
        printf("\n The Length of Student List = %d", length);
    }
    else
    {
        printf("\n List is empty !");
    }
}

void studentList_Get_length_Method_2(void)
{
    uint16_t length;

    if (linked_list_Get_Length_Iterative(&studentList, &length) == LINKED_LIST_no_error)
    {
        printf("\n The Length of Student List = %d", length);
    }
    else
    {
        printf("\n List is empty !");
    }
}

void studentList_Check_Loop(void)
{
    switch (linked_list_Detect_Loop(&studentList))
    {
    case LINKED_LIST_loop_detected:
        printf("\n Student Linked List Has Loop!");
        break;
    case LINKED_LIST_empty:
        printf("\n Student Linked List Is Empty!");
        break;
    case LINKED_LIST_no_error:
        printf("\n Student Linked List Has no Loop!");
        break;
    default:
        break;
    }
}

void studentList_Reverse_List(void)
{
    switch (linked_list_Reverse(&studentList))
    {
    case LINKED_LIST_no_error:
        printf("\n Done Reverse Student Linked List");
        break;
    case LINKED_LIST_empty:
        printf("\n Student Linked List Is Empty!");
        break;
    default:
        break;
    }
}