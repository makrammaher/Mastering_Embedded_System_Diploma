/*
 *           File: student.h
 *     Created on: Tuesday 03/05/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Student DataBase Using Circular Queue
 *
 *
 */

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdint.h>
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"


#define STUDENT_BUFFER_LENGTH     50

typedef struct SStudent
{
    uint16_t    rollNumber;
    char        fName[50];
    char        lName[50];
    float       GPA;
    uint16_t    CourseID[5];
} student_t;

typedef enum
{
    ADDST_no_error,
    ADDST_rollNumber_error,
    ADDST_error
} ADDST_Status_t;


void student_Init(void);

void student_Add_Manually(void);
void student_Add_File(void);
void student_Save_File(void);
void student_Find_RollNumber(void);
void student_Find_FirstName(void);
void student_Find_CourseID(void);
void student_Print_All_Students(void);
void student_View_Number_Students(void);
void student_Update_RollNumber(void);
void student_Delete_RollNumber(void);


#endif