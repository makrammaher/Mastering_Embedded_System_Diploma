/*
 *           File: main.c
 *     Created on: Wednesday 06/04/2022 19:09
 *         Author: Makram Maher Makram
 *        Subject: Testing Makefile
 *
 *
 */

#include "a.h"
#include "b.h"

int main (void)
{
    int x;
    double y;

    x = scanint();
    y = scanfloat();


    printf("The scaned values are:\n");
    printint(x);
    printfloat(y);

    
}