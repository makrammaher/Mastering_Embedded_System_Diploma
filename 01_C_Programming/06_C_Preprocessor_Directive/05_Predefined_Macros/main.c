/*
 *           File: main.c
 *     Created on: Tuesday 08/03/2022 13:04
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
   printf("__STDC__ = %d\n", __STDC__);
   printf("__STDC_HOSTED__ = %d\n", __STDC_HOSTED__);
   printf("__STDC_VERSION__ = %ld\n", __STDC_VERSION__);
   printf("__FILE__ = %s\n", __FILE__);
   printf("__LINE__ = %d\n", __LINE__);
   printf("__DATE__ = %s\n", __DATE__);
   printf("__func__ = %s\n", __func__);
   return 0;
}/* end main */
