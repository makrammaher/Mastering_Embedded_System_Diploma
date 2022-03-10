/*
 *           File: main.c
 *     Created on: Thursday 10/03/2022 17:00
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
   char str[100];
   char rstr[100];
   char* ptr = str;;
   char* rptr = rstr;
   int i;
   printf("Input a string: ");
   scanf("%s", str);

   i = 0;
   while(*(ptr+i))
   {
      i++;
   }
   i--;
   while(i>=0)
   {
      *(rptr++) = *(ptr+i--);
   }
   *rptr = '\0'; /* null Terminator */

   printf("Reverse of the string is: %s\n", rstr);

   return 0;
}/* end main */
