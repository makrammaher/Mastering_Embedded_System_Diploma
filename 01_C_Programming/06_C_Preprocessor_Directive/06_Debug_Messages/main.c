/*
 *           File: main.c
 *     Created on: Tuesday 08/03/2022 14:13
 *         Author: Makram Maher Makram
 *        Subject: 
 *
 *
 */

/* Includes files */
#include<stdio.h>

#define debug_enable

#define debub_message(debug_level,...) if(debug_level < 2)\
                                          printf(">> File: %s\n", __FILE__);\
                                       else if(debug_level < 3)\
                                          printf(">> File: %s  Func: %s\n", __FILE__, __func__);\
                                       else if(debug_level < 4)\
                                          printf(">> File: %s  Func: %s  Line: %d\n", __FILE__, __func__, __LINE__);\
                                       else\
                                          printf(">> File: %s  Func: %s  Line: %d  STD:%ld\n", __FILE__, __func__, __LINE__, __STDC_VERSION__);\
                                       printf(">> ");\
                                       printf(__VA_ARGS__);\
                                       printf("\n\n");


void function1(void);
void function2(void);
void function3(void);


/* main function */
int main(void)
{
   #ifdef debug_enable
      debub_message(1,"Test Debug level = %d", 1);
      debub_message(2,"Test Debug level = %d", 2);
      debub_message(3,"Test Debug level = %d", 3);
      debub_message(4,"Test Debug level = %d", 4);
   #endif

   function1();
   function2();
   function1();
   function3();

   #ifdef debug_enable
      debub_message(1,"Test Debug level = %d", 1);
      debub_message(2,"Test Debug level = %d", 2);
      debub_message(3,"Test Debug level = %d", 3);
      debub_message(4,"Test Debug level = %d", 4);
   #endif

   return 0;
}/* end main */

void function1(void)
{
   #ifdef debug_enable
      debub_message(1,"Test Debug level = %d", 1);
      debub_message(2,"Test Debug level = %d", 2);
      debub_message(3,"Test Debug level = %d", 3);
      debub_message(4,"Test Debug level = %d", 4);
   #endif
}
void function2(void)
{
   #ifdef debug_enable
      debub_message(1,"Test Debug level = %d", 1);
      debub_message(2,"Test Debug level = %d", 2);
      debub_message(3,"Test Debug level = %d", 3);
      debub_message(4,"Test Debug level = %d", 4);
   #endif
}
void function3(void)
{
   #ifdef debug_enable
      debub_message(1,"Test Debug level = %d", 1);
      debub_message(2,"Test Debug level = %d", 2);
      debub_message(3,"Test Debug level = %d", 3);
      debub_message(4,"Test Debug level = %d", 4);
   #endif
}