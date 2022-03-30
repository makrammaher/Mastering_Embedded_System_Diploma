/*
 *           File: main.c
 *     Created on: Wednesday 23/03/2022 18:34
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */

/* Includes files */
#include<stdio.h>

#include "a.h"
#include "b.h"

/* main function */
int main(void)
{  
   SmyStruct_t structx;
   structx.x = 100;
   structx.y = 200;

   function1(structx);
   puts("");
   function2(structx);

   return 0;
}/* end main */
