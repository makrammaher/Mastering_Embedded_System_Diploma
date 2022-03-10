/*
 *           File: main.c
 *     Created on: Thursday 10/03/2022 17:28
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */

/* Includes files */
#include<stdio.h>

struct SEmployee
{
   char m_name[50];
   unsigned int m_id;
};

/* main function */
int main(void)
{
   struct SEmployee emp1 = {"Makram Maher", 1000}, emp2 = {"Keroles", 1001}, emp3 = {"Alex", 1002};
   struct SEmployee * arr[3] = {&emp1, &emp2, &emp3};
   struct SEmployee *(*ptr)[3] = &arr;


   printf("Exmployee Name : %s\n", (*ptr)[0] -> m_name);
   printf("Exmployee ID : %d\n\n", (*ptr)[0] -> m_id);

   printf("Exmployee Name : %s\n", (*ptr)[1] -> m_name);
   printf("Exmployee ID : %d\n\n", (*ptr)[1] -> m_id);

   printf("Exmployee Name : %s\n", (*ptr)[2] -> m_name);
   printf("Exmployee ID : %d\n\n", (*ptr)[2] -> m_id);



   return 0;
}/* end main */
