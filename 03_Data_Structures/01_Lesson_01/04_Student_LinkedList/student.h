/*
 *           File: student.h
 *     Created on: Saturday 23/04/2022 21:09
 *         Author: Makram Maher Makram
 *        Subject: Create Student database using generic LinkedList
 *
 *
 */

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdint.h>
#include <stdio.h>
#include "linked_list.h"


typedef struct SStudent
{
    uint16_t    id;
    char        name[40];
    float       height;
}student_t;



void studentList_Init(void);
void studentList_Add(void);
void studentList_Delete(void);
void studentList_Delete_By_Index(void);
void studentList_Delete_All(void);
void studentList_View_All(void);
void studentList_Get_By_Index(void);
void studentList_Get_By_ID(void);
void studentList_Get_By_Index_End(void);
void studentList_View_Middle(void);
void studentList_Get_length_Method_1(void);
void studentList_Get_length_Method_2(void);
void studentList_Check_Loop(void);
void studentList_Reverse_List(void);




#endif