/*
 *           File: main.c
 *     Created on: Thursday 10/03/2022 18:09
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */

/* Includes files */
#include<stdio.h>

struct SEmployee
{
   char data1;
   int data2;
   char data3;
   short data4;

};

void dump_memory(unsigned char * base, unsigned int size_in_bytes);

/* main function */
int main(void)
{
   unsigned short array[8] = {0x1100,0x3322,0x5544,0x7766,0x9988,0xbbaa,0xddcc,0xffee};
   struct SEmployee emp1 = {0xFF, 0xAABBCCDD, 0xAA, 0xEEEE};
   
   dump_memory((unsigned char *) &emp1, sizeof(emp1));
   printf("\n");
   dump_memory((unsigned char *) & array, sizeof(array));

   return 0;
}/* end main */


void dump_memory(unsigned char * base, unsigned int size_in_bytes)
{
   unsigned int i;
   printf("%-15s%-15s\n", "Address", "Value");

   for(i = 0;i<size_in_bytes;i++)
   {
      printf("0x%-13X0x%-13X\n", base+i, *(base+i));
   }
}