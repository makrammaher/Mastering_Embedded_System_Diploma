/*
 *           File: stack.c
 *     Created on: Wednesday 20/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Stack(LIFO) Data structure
 *
 *
 */

#include "stack.h"

stack_status_t stack_Init(stack_t* stack, void* buffer, uint8_t length, uint8_t element_size)
{
    if (stack == NULL || buffer == NULL)
        return STACK_null;

    stack->base = buffer;
    stack->head = buffer;
    stack->element_Size = element_size;
    stack->length = length;
    stack->count = 0;
    return STACK_no_error;
}

stack_status_t stack_Is_Full(stack_t* stack)
{
    if (stack->count == stack->length)
        return STACK_full;
    else
        return STACK_not_full;
}

stack_status_t stack_Is_Empty(stack_t* stack)
{
    if (stack->count == 0)
        return STACK_empty;
    else
        return STACK_not_empty;
}

stack_status_t stack_Push(stack_t* stack, void* data)
{
    /* Check null pointers */
    if (stack == NULL || stack->base == NULL || stack->head == NULL)
        return STACK_null;

    /* Check if stack is aready full */
    if (stack_Is_Full(stack) == STACK_full)
        return STACK_full;

    /* push data to stack */
    uint8_t i;
    for (i = 0; i < stack->element_Size; i++)
    {
        /* Copy data byte by byte from data to stack */
        *(stack->head + i) = *((uint8_t*)data + i);
    }
    /* increament stack head and count */
    stack->head += stack->element_Size;
    stack->count++;
    return STACK_no_error;
}

stack_status_t stack_Pop(stack_t* stack, void* data)
{
    /* Check null pointers */
    if (stack == NULL || stack->base == NULL || stack->head == NULL)
        return STACK_null;

    /* Check if stack is aready empty */
    if (stack_Is_Empty(stack) == STACK_empty)
        return STACK_empty;

    /* decreament stack head*/
    stack->head -= stack->element_Size;
    /* Pop data from stack */
    uint8_t i;
    for (i = 0; i < stack->element_Size; i++)
    {
        /* Copy data byte by byte from stack to data */
        *((uint8_t*)data + i) = *(stack->head + i);
    }

    /* decreament stack head and count */
    stack->count--;
    return STACK_no_error;

}

stack_status_t stack_Top(stack_t* stack, void* data)
{
    /* Check null pointers */
    if (stack == NULL || stack->base == NULL || stack->head == NULL)
        return STACK_null;

    /* Check if stack is aready empty */
    if (stack_Is_Empty(stack) == STACK_empty)
        return STACK_empty;

    uint8_t* temp = stack->head - stack->element_Size;
    uint8_t i;
    for (i = 0; i < stack->element_Size; i++)
    {
        /* Copy data byte by byte from stack to data */
        *((uint8_t*)data + i) = *(temp + i);
    }
    return STACK_no_error;
}