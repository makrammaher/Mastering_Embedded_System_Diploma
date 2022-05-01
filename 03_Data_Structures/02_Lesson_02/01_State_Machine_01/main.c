/*
 *           File: main.c
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create a simple state machine (collision avoidance)
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "ca.h"


void setup(void)
{
    CA_init();
}

int main(void)
{
    setup();
    while (1)
    {
        CA_state();
        unsigned long long int i;
        /* delay loop */
        for (i = 0 ; i < 2000000; i++);
    }
    return 0;
}