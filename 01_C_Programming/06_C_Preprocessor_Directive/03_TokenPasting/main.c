/*
 *           File: main.c
 *     Created on: Monday 07/03/2022 22:50
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */


/* Includes files */
#include<stdio.h>

#define PRIMITIVE_CAT(a, ...) (a##__VA_ARGS__)
   
#define DEC(X) PRIMITIVE_CAT (DEC_, X)

#define DEC_0 0
#define DEC_1 1
#define DEC_2 2
#define DEC_3 3
#define DEC_4 4
#define DEC_5 5
#define DEC_6 6
#define DEC_7 7
#define DEC_8 8
#define DEC_9 9

/* main function */
int main(void)
{
   printf("DEC_0 = %d\n", DEC(0));
   printf("DEC_1 = %d\n", DEC(1));
   printf("DEC_2 = %d\n", DEC(2));
   printf("DEC_3 = %d\n", DEC(3));
   printf("DEC_4 = %d\n", DEC(4));
   printf("DEC_5 = %d\n", DEC(5));
   printf("DEC_6 = %d\n", DEC(6));
   printf("DEC_7 = %d\n", DEC(7));
   printf("DEC_8 = %d\n", DEC(8));
   printf("DEC_9 = %d\n", DEC(9));
   return 0;
}/* end main */
