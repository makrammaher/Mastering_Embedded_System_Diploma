/*
 *           File: main.c
 *     Created on: Thursday 10/03/2022 16:50
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
   char alphabets[26];
   char* ptr;
   unsigned int i;

   ptr = alphabets;

   /* Assign array for all alphabets */
   for(i = 0;i<26;i++)
   {
      *(ptr + i) = 'A' + i;
   }

   /* Print alphabets */
   for(i = 0;i<26;i++)
   {
      printf("%c  ", *(ptr+i));
   }
   printf("\n");



   return 0;
}/* end main */
