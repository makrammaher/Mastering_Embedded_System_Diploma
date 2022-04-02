/*
 *           File: main.c
 *     Created on: Wednesday 30/03/2022 9:57
 *         Author: Makram Maher Makram
 *        Subject: test create a static library
 *
 *
 */

#include <stdio.h>
#include "calculator.h"

int main(void)
{
    int a = 123;
    int b = 11;

    printf("a + b = %d\n", add_Two_Numbers(a, b));
    printf("a * b = %d\n", multipli_Two_Numbers(a, b));

    return 0;
}
