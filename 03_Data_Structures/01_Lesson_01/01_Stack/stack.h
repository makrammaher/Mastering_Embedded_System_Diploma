/*
 *           File: stack.h
 *     Created on: Wednesday 20/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Stack(LIFO) Data structure
 *
 *
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>
#include <stdio.h>

typedef struct
{
    void*       base;         /* pointer to the base of the stack */
    void*       head;         /* pointer to the top of the stack */
    uint8_t     element_Size; /* hold size of element in bytes */
    uint16_t    length;       /* stack max number of element */
    uint16_t    count;        /* number of element in stack right now */
} stack_t;

typedef enum
{
    STACK_no_error,
    STACK_full,
    STACK_not_full,
    STACK_empty,
    STACK_not_empty,
    STACK_null
} stack_status_t;

stack_status_t stack_Init(stack_t* stack, void* buffer, uint8_t length, uint8_t element_size);
stack_status_t stack_Push(stack_t* stack, void* data);
stack_status_t stack_Pop(stack_t* stack, void* data);
stack_status_t stack_Top(stack_t* stack, void* data);
stack_status_t stack_Is_Full(stack_t* stack);
stack_status_t stack_Is_Empty(stack_t* stack);


#endif
