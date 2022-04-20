/*
 *           File: main.c
 *     Created on: Wednesday 20/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Stack(LIFO) Data structure
 *
 *
 */

#include <stdio.h>
#include "stack.h"

#define stack_uint16_size   10
#define stack_float_size    10

int main(void)
{
    /* create a stack of 20 uint16_t and initialize it */
    stack_t stack_uint16;
    uint16_t buffer_uint16[stack_uint16_size];
    stack_Init(&stack_uint16, buffer_uint16, stack_uint16_size, sizeof(uint16_t));
    /* ----------------------------------------------- */

    uint16_t i, data;
    
    for (i = 0; i < 12; i++)
    {
        stack_status_t status = stack_Push(&stack_uint16, &i);
        switch(status)
        {
            case STACK_no_error:
            printf("Done  --> Push %d to stack_uint16\n", i);
            break;
            case STACK_full:
            printf("Error --> stack is full\n");
            break;
            default:
            break;
        }
    }
    puts("");
    for (i = 0; i < 12; i++)
    {
        stack_status_t status = stack_Pop(&stack_uint16, &data);
        switch(status)
        {
            case STACK_no_error:
            printf("Done  --> Pop %d from stack_uint16\n", data);
            break;
            case STACK_empty:
            printf("Error --> stack is empty\n");
            break;
            default:
            break;
        }
    }
    puts("");

    /* create a stack of 10 float and initialize it */
    stack_t stack_float;
    float buffer_float[stack_float_size];
    stack_Init(&stack_float, buffer_float, stack_float_size, sizeof(float));
    /* -------------------------------------------- */

    float f, fdata;

    for (f = 1.0; f < 2.2; f += 0.1)
    {
        stack_status_t status = stack_Push(&stack_float, &f);
        switch(status)
        {
            case STACK_no_error:
            printf("Done  --> Push %.1f to stack_float\n", f);
            break;
            case STACK_full:
            printf("Error --> stack is full\n");
            break;
            default:
            break;
        }
    }
    puts("");
    
    for (i = 0; i < 12; i++)
    {
        stack_status_t status = stack_Pop(&stack_float, &fdata);
        switch(status)
        {
            case STACK_no_error:
            printf("Done  --> Pop %.1f from stack_float\n", fdata);
            break;
            case STACK_empty:
            printf("Error --> stack is empty\n");
            break;
            default:
            break;
        }
    }

    return 0;
}