/*
 *           File: main.c
 *     Created on: Thursday 17/03/2022 19:09
 *         Author: Makram Maher Makram
 *        Subject:
 *
 *
 */

/* Includes files */
#include<stdio.h>

#define SIZE 20

void swap(int * const ptrNum1, int * const ptrNum2);
void bubbleSort(int * const ptr, const unsigned int size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);
void printIntArray(const int * const ptr, const unsigned int size);

/* main function */
int main(void)
{
   int array[SIZE] = {12, 26, 43, 21, 1, 49, 634, 52, 71, 32, 15, 16, 7, 18, 2, 122, 23, 45, 234, 63};

   printf("%s\n", "Array in original order");
   printIntArray(array, SIZE);

   bubbleSort(array, SIZE, ascending);
   printf("\n%s\n", "Array in ascending order");
   printIntArray(array, SIZE);

   bubbleSort(array, SIZE, descending);
   printf("\n%s\n", "Array in descending order");
   printIntArray(array, SIZE);

   return 0;
}/* end main */


void printIntArray(const int * const ptr, const unsigned int size)
{
   unsigned int i;
   for (i = 0; i < size; i++)
   {
      printf("%5d", ptr[i]);
   }
   printf("\n");
}

void bubbleSort(int * const ptr, const unsigned int size, int (*compare)(int a, int b))
{
   unsigned int passes;
   unsigned int i;

   for (passes = 0; passes < size - 1; passes++)
   {
      for (i = 0; i < size - 1; i++)
      {
         if (compare(ptr[i], ptr[i + 1]))
            swap(&ptr[i], &ptr[i + 1]);
      }
   }
}

int ascending(int a, int b)
{
   return a > b;
}

int descending(int a, int b)
{
   return a < b;
}

void swap(int * const ptrNum1, int * const ptrNum2)
{
   int temp;
   temp = *ptrNum1;
   *ptrNum1 = *ptrNum2;
   *ptrNum2 = temp;
}

