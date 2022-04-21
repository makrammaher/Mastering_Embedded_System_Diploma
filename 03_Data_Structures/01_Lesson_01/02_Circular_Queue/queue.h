/*
 *           File: queue.h
 *     Created on: Wednesday 20/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Circular Queue (FIFO) Data structure
 *
 *
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdint.h>
#include <stdio.h>

typedef struct
{
    void*       base;         /* pointer to the base of the queue */
    void*       head;         /* pointer to the top of the queue */
    void*       tail;         /* pointer to the tail of the queue */
    uint8_t     element_Size; /* hold size of element in bytes */
    uint16_t    length;       /* queue max number of element */
    uint16_t    count;        /* number of element in queue right now */
} queue_t;

typedef enum
{
    QUEUE_no_error,
    QUEUE_full,
    QUEUE_not_full,
    QUEUE_empty,
    QUEUE_not_empty,
    QUEUE_null
} queue_status_t;

queue_status_t queue_Init(queue_t* stack, void* buffer, uint8_t length, uint8_t element_size);
queue_status_t queue_Enqueue(queue_t* stack, void* data);
queue_status_t queue_Dequeue(queue_t* stack, void* data);
queue_status_t queue_Top(queue_t* stack, void* data);
queue_status_t queue_Is_Full(queue_t* stack);
queue_status_t queue_Is_Empty(queue_t* stack);


#endif