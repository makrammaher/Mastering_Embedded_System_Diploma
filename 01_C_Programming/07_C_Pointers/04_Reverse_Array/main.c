/*
 *           File: main.c
 *     Created on: Thursday 10/03/2022 17:16
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
   int array[15];
   int* ptr = array;
   int i, n;

   printf("%s\n", "Input the number of elements to store in the array (max 15): ");
   scanf("%d", &n);
   for(i = 0;i<n;i++)
   {
      printf("Element - %d: ", i+1);
      scanf("%d", ptr++);
   }

   printf("\nThe elements of array in reverse order are :\n");
   for(i = n;i>0;i--)
   {
      printf("Element - %d: %d\n", i, *--ptr);
   }



   return 0;
}/* end main */
