/*
 *           File: main.c
 *     Created on: Tuesday 08/03/2022 12:25
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */

/* Includes files */
#include<stdio.h>

#define CREATE_FUN(name, factor) int fun_##name(int x)\
                                 {\
                                    return factor * x;\
                                 }

#define FUN_PROTOTYPE(returndata, name, ...) returndata name(__VA_ARGS__)

FUN_PROTOTYPE(int, fun_double, int x);
FUN_PROTOTYPE(int, fun_quadruple, int x);

/* main function */
int main(void)
{
   int x,y;
   x = fun_double(10);
   y = fun_quadruple(10);

   printf("fun_double(10) = %d\n", x);
   printf("fun_quadruple(10) = %d\n", y);

   return 0;
}/* end main */


CREATE_FUN(double, 2)
CREATE_FUN(quadruple, 4)