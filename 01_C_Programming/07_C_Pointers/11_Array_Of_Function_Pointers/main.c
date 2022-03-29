/*
 *           File: main.c
 *     Created on: Thursday 17/03/2022 19:35
 *         Author: Makram Maher Makram
 *        Subject:
 *
 *
 */

/* Includes files */
#include<stdio.h>
void func1(int a, int b);
void func2(int a, int b);
void func3(int a, int b);
void func4(int a, int b);

/* main function */
int main(void)
{
   void (*arr[4]) (int a, int b) = {func1, func2, func3, func4};

   unsigned int i;
   for (i = 0; i < 4; i++)
   {
      arr[i](i + 10, i + 20);
   }

   return 0;
}/* end main */


void func1(int a, int b)
{
   printf("You Called Function 1:\n");
   printf("func1(%d, %d);\n\n", a, b);
}

void func2(int a, int b)
{
   printf("You Called Function 2:\n");
   printf("func2(%d, %d);\n\n", a, b);
}

void func3(int a, int b)
{
   printf("You Called Function 3:\n");
   printf("func3(%d, %d);\n\n", a, b);
}

void func4(int a, int b)
{
   printf("You Called Function 4:\n");
   printf("func4(%d, %d);\n\n", a, b);
}