/*
 *           File: student.c
 *     Created on: Tuesday 03/05/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Student DataBase Using Circular Queue
 *
 *
 */

#include "student.h"

static student_t    studentBuffer[STUDENT_BUFFER_LENGTH];
static queue_t      studentQueue;


void student_Init(void)
{
    queue_Init(&studentQueue, studentBuffer, STUDENT_BUFFER_LENGTH, sizeof(student_t));
}

void Queue_print_student(void* ptr, uint16_t index)
{
    student_t* studentPTR = ptr;
    printf("\n Index: \t%d\n", index);
    printf(" RollNumber: \t%d\n", studentPTR->rollNumber);
    printf(" FirstName: \t%s\n", studentPTR->fName);
    printf(" LastName: \t%s\n", studentPTR->lName);
    printf(" GPA: \t\t%.2f\n", studentPTR->GPA);
    printf(" Courses: \t[ %d - %d - %d - %d - %d ]\n", studentPTR->CourseID[0], studentPTR->CourseID[1], studentPTR->CourseID[2], studentPTR->CourseID[3], studentPTR->CourseID[4]);
    printf("----------------------------------------------------\n");
}

static ADDST_Status_t student_add(student_t* new_student)
{
    /* check for all constrains before add new student to queue */
    uint8_t flag = 0;
    uint16_t i;
    student_t student;
    for (i = 0; i < studentQueue.count; i++)
    {
        /* loop in the queue using dequeue and enqueue */
        queue_Dequeue(&studentQueue, &student);
        if (student.rollNumber == new_student->rollNumber)
        {
            flag++;
        }
        queue_Enqueue(&studentQueue, &student);
    }
    if (flag)
    {
        return ADDST_rollNumber_error;
    }
    else if (queue_Enqueue(&studentQueue, new_student) == QUEUE_no_error)
    {
        return ADDST_no_error;
    }
    else
    {
        return ADDST_error;
    }
}

void student_Add_Manually(void)
{
    char temp_text[50];
    student_t new_student;

    printf("\n--------------------------");
    printf("\n  Add a Student Manually");
    printf("\n--------------------------");

    printf("\n Enter The RollNumber: ");
    gets(temp_text);
    new_student.rollNumber = atoi(temp_text);

    printf(" Enter The FirstName: ");
    gets(new_student.fName);

    printf(" Enter The LastName: ");
    gets(new_student.lName);

    printf(" Enter The GPA: ");
    gets(temp_text);
    new_student.GPA = atof(temp_text);

    printf(" Enter the course ID for each course: \n");
    uint8_t i;
    for (i = 0; i < 5; i++)
    {
        printf(" Course %d id :", i + 1);
        gets(temp_text);
        new_student.CourseID[i] = atoi(temp_text);
    }

    if (student_add(&new_student) == ADDST_no_error)
    {
        printf("\n [INFO]: Adding new student Successfully");
        printf("\n [INFO]: The total number of students is %d", studentQueue.count);
        printf("\n [INFO]: The maximum number of students can be added is %d", studentQueue.length);
        printf("\n [INFO]: The number of students can be addded is %d ", studentQueue.length - studentQueue.count);
    }
    else
    {
        printf("\n [ERROR]: New RollNumber is already taken");
    }
}

void student_Add_File(void)
{
    printf("\n-------------------------------");
    printf("\n  Add Students From Text File");
    printf("\n-------------------------------");
    FILE *fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    student_t student;
    fp = fopen("./students.txt", "r");
    if (fp == NULL)
        printf(" [ERROR]: File students.txt not found");

    while ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "%hu %s %s %f %hu %hu %hu %hu %hu", &student.rollNumber, student.fName, student.lName, &student.GPA, &student.CourseID[0],
               &student.CourseID[1], &student.CourseID[2], &student.CourseID[3], &student.CourseID[4]);
        if (student_add(&student) == ADDST_no_error)
        {
            printf("\n [INFO]: Adding new student Successfully with RollNumber %d", student.rollNumber);
        }
        else
        {
            printf("\n [ERROR]: RollNumber %d is already taken", student.rollNumber);
        }
    }

    fclose(fp);
    if (line)
        free(line);
}

void student_Save_File(void)
{
    printf("\n-------------------------------------");
    printf("\n  Save Student Details To Text File");
    printf("\n-------------------------------------");
    FILE *fp;

    fp = fopen("./students.txt", "w");
    if (fp == NULL)
        printf(" [ERROR]: File students.txt not found");

    uint16_t i;
    student_t student;
    for (i = 0; i < studentQueue.count; i++)
    {
        /* loop in the queue using dequeue and enqueue */
        queue_Dequeue(&studentQueue, &student);
        fprintf(fp, "%hu\t%s\t%s\t%.2f\t%hu %hu %hu %hu %hu\n", student.rollNumber, student.fName, student.lName, student.GPA, student.CourseID[0], student.CourseID[1], student.CourseID[2], student.CourseID[3], student.CourseID[4]);
        queue_Enqueue(&studentQueue, &student);
    }

    fclose(fp);
}

void student_Find_RollNumber(void)
{
    char temp_text[10];
    uint16_t rollNumber;
    printf("\n------------------------------------------");
    printf("\n  View Students Details by (Roll Number)");
    printf("\n------------------------------------------");
    printf("\n Enter The RollNumber: ");
    gets(temp_text);
    rollNumber = atoi(temp_text);

    uint16_t i;
    uint8_t flag = 0;
    student_t student;
    for (i = 0; i < studentQueue.count; i++)
    {
        /* loop in the queue using dequeue and enqueue */
        queue_Dequeue(&studentQueue, &student);
        if (student.rollNumber == rollNumber)
        {
            printf("\n The Student details are:");
            Queue_print_student(&student, i);
            flag++;
        }
        queue_Enqueue(&studentQueue, &student);
    }
    if (!flag)
        printf("\n [ERROR]: RollNumber %d not found", rollNumber);
}

void student_Find_FirstName(void)
{
    char firstName[50];
    printf("\n-----------------------------------------");
    printf("\n  View Students Details by (First Name)");
    printf("\n-----------------------------------------");
    printf("\n Enter The FirstName: ");
    gets(firstName);

    uint16_t i;
    uint8_t flag = 0;
    student_t student;
    for (i = 0; i < studentQueue.count; i++)
    {
        /* loop in the queue using dequeue and enqueue */
        queue_Dequeue(&studentQueue, &student);
        if (strcmp(firstName, student.fName) == 0)
        {
            printf("\n The Student details are:");
            Queue_print_student(&student, i);
            flag++;
        }
        queue_Enqueue(&studentQueue, &student);
    }
    if (!flag)
        printf("\n [ERROR]: FirstName %s not found", firstName);
}

void student_Find_CourseID(void)
{

    char temp_text[10];
    uint16_t courseID;
    printf("\n----------------------------------------");
    printf("\n  View Students Details by (Course ID)");
    printf("\n----------------------------------------");
    printf("\n Enter The CourseID: ");
    gets(temp_text);
    courseID = atoi(temp_text);

    uint16_t i;
    uint8_t flag = 0;
    student_t student;
    for (i = 0; i < studentQueue.count; i++)
    {
        /* loop in the queue using dequeue and enqueue */
        queue_Dequeue(&studentQueue, &student);
        uint8_t j;
        for (j = 0; j < 5; j++)
        {
            /* loop on courses per each student */
            if (student.CourseID[j] == courseID)
            {
                printf("\n The Student details are:");
                Queue_print_student(&student, i);
                flag++;
            }
        }
        queue_Enqueue(&studentQueue, &student);
    }
    if (!flag)
        printf("\n [ERROR]: CourseID %d not found", courseID);
    else
        printf("\n [INFO]: %d Students Enrolled in CourseID %d", flag, courseID);
}

void student_Print_All_Students(void)
{
    printf("\n-----------------------------");
    printf("\n  View All Students Details");
    printf("\n-----------------------------");
    if (QUEUE_empty == queue_Print(&studentQueue, Queue_print_student))
    {
        printf("\n [ERROR]: Queue Is Empty");
    }
}


void student_View_Number_Students(void)
{
    printf("\n---------------------------------");
    printf("\n  View Total Number of Students");
    printf("\n---------------------------------");
    printf("\n [INFO]: The total number of students is %d", studentQueue.count);
    printf("\n [INFO]: The maximum number of students can be added is %d", studentQueue.length);
    printf("\n [INFO]: The number of students can be addded is %d ", studentQueue.length - studentQueue.count);
}

void student_Update_RollNumber(void)
{
    char temp_text[10];
    uint16_t rollNumber;
    printf("\n---------------------------------------------");
    printf("\n  Update a Student Details by (Roll Number)");
    printf("\n---------------------------------------------");
    printf("\n Enter The RollNumber: ");
    gets(temp_text);
    rollNumber = atoi(temp_text);

    uint16_t i;
    uint8_t flag = 0;
    student_t student;
    for (i = 0; i < studentQueue.count; i++)
    {
        /* loop in the queue using dequeue and enqueue */
        queue_Dequeue(&studentQueue, &student);
        if (student.rollNumber == rollNumber)
        {
            /* update this student */
            printf("\n The Student details are:");
            Queue_print_student(&student, i);
            printf("\n\tChoose one of the following options\n");
            printf("\n 1: Update RollNumber");
            printf("\n 2: Update FirstName");
            printf("\n 3: Update LastName");
            printf("\n 4: Update GPA");
            printf("\n 5: Update Courses");
            printf("\n Enter Option Number: ");
            gets(temp_text);
            student_t new_student = student;
            switch (atoi(temp_text))
            {
            case 1:
                printf("\n Enter The New RollNumber: ");
                gets(temp_text);
                new_student.rollNumber = atoi(temp_text);
                break;
            case 2:
                printf(" Enter The New FirstName: ");
                gets(new_student.fName);
                break;
            case 3:
                printf(" Enter The New LastName: ");
                gets(new_student.lName);
                break;
            case 4:
                printf(" Enter The New GPA: ");
                gets(temp_text);
                new_student.GPA = atof(temp_text);
                break;
            case 5:
                printf(" Enter the course ID for each course: \n");
                uint8_t i;
                for (i = 0; i < 5; i++)
                {
                    printf(" Course %d id :", i + 1);
                    gets(temp_text);
                    new_student.CourseID[i] = atoi(temp_text);
                }
                break;
            default:
                break;
            }
            if (student_add(&new_student) == ADDST_no_error)
            {
                printf("\n [INFO]: Update Student with rollNumber %d Successfully", rollNumber);
            }
            else
            {
                printf("\n [ERROR]: New RollNumber is already taken");
                queue_Enqueue(&studentQueue, &student);
            }
            flag++;
        }
        else
        {
            queue_Enqueue(&studentQueue, &student);
        }
    }
    if (!flag)
        printf("\n [ERROR]: RollNumber %d not found", rollNumber);
}


void student_Delete_RollNumber(void)
{
    char temp_text[10];
    uint16_t rollNumber;
    printf("\n---------------------------------------------");
    printf("\n  Delete a Student Details by (Roll Number)");
    printf("\n---------------------------------------------");
    printf("\n Enter The RollNumber: ");
    gets(temp_text);
    rollNumber = atoi(temp_text);

    uint16_t i;
    uint8_t flag = 0;
    student_t student;
    for (i = 0; i < studentQueue.count; i++)
    {
        /* loop in the queue using dequeue and enqueue */
        queue_Dequeue(&studentQueue, &student);
        if (student.rollNumber == rollNumber)
        {
            printf("\n [INFO]: The Student with rollNumber %d Deleted Successfully", rollNumber);
            i--;
            flag++;
        }
        else
        {
            queue_Enqueue(&studentQueue, &student);
        }
    }
    if (!flag)
        printf("\n [ERROR]: RollNumber %d not found", rollNumber);
}
