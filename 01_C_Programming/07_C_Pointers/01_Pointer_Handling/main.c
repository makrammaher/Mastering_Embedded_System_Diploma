/*
 *           File: main.c
 *     Created on: Thursday 10/03/2022 16:36
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */

/* Includes files */
#include<stdio.h>

/* main function */
int main(void)
{
   int m = 29;
   int *ab;

   printf("Address of m: 0x%x\n", &m);
   printf("Value of m: %d\n", m);
   ab = &m;
   printf("\nnow ab is assgined with the adress of m.\n");
   printf("Address of pointer ab: 0x%x\n", ab);
   printf("Content of pointer ab: %d\n", *ab);
   m = 34;
   printf("\nThe value of m assigned to 34 now\n");
   printf("Address of pointer ab: 0x%x\n", ab);
   printf("Content of pointer ab: %d\n", *ab);
   *ab = 7;
   printf("\nThe pointer variable ab is assigned with the value 7 now:\n");
   printf("Address of m: 0x%x\n", &m);
   printf("value of m: %d\n", m);

   return 0;
}/* end main */
