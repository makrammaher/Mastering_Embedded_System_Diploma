/*
 *           File: queue.c
 *     Created on: Wednesday 20/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Circular Queue (FIFO) Data structure
 *
 *
 */

#include "queue.h"

queue_status_t queue_Init(queue_t* queue, void* buffer, uint8_t length, uint8_t element_size)
{
    if (queue == NULL || buffer == NULL)
        return QUEUE_null;

    queue->base = buffer;
    queue->head = buffer;
    queue->tail = buffer;
    queue->element_Size = element_size;
    queue->length = length;
    queue->count = 0;
    return QUEUE_no_error;
}

queue_status_t queue_Is_Full(queue_t* queue)
{
    if (queue == NULL || queue->base == NULL || queue->head == NULL || queue->tail == NULL)
        return QUEUE_null;
    if (queue->count == queue->length)
        return QUEUE_full;
    else
        return QUEUE_not_full;
}

queue_status_t queue_Is_Empty(queue_t* queue)
{
    if (queue == NULL || queue->base == NULL || queue->head == NULL || queue->tail == NULL)
        return QUEUE_null;
    if (queue->count == 0)
        return QUEUE_empty;
    else
        return QUEUE_not_empty;
}

queue_status_t queue_Enqueue(queue_t* queue, void* data)
{
    /* Check null pointers */
    if (queue == NULL || queue->base == NULL || queue->head == NULL || queue->tail == NULL)
        return QUEUE_null;

    /* Check if queue is aready full */
    if (queue_Is_Full(queue) == QUEUE_full)
        return QUEUE_full;

    /* Enqueue data to queue */
    uint8_t i;
    for (i = 0; i < queue->element_Size; i++)
    {
        /* Copy data byte by byte from data to queue */
        *((uint8_t*)queue->head + i) = *((uint8_t*)data + i);
    }

    /* increament queue head and count (circuler) */
    queue->head = (uint8_t*)queue->head + queue->element_Size;

    if (queue->head == ((uint8_t*)queue->base + (queue->length * queue->element_Size)))
    {
        queue->head = queue->base;
    }
    queue->count++;
    return QUEUE_no_error;
}

queue_status_t queue_Dequeue(queue_t* queue, void* data)
{
    /* Check null pointers */
    if (queue == NULL || queue->base == NULL || queue->head == NULL || queue->tail == NULL)
        return QUEUE_null;

    /* Check if queue is aready empty */
    if (queue_Is_Empty(queue) == QUEUE_empty)
        return QUEUE_empty;

    /* Dequeue data from queue */
    uint8_t i;
    for (i = 0; i < queue->element_Size; i++)
    {
        /* Copy data byte by byte from queue to data */
        *((uint8_t*)data + i) = *((uint8_t*)queue->tail + i);
    }

    /* increament queue tail and count (circuler) */
    queue->tail = (uint8_t*)queue->tail + queue->element_Size;

    if (queue->tail == ((uint8_t*)queue->base + (queue->length * queue->element_Size)))
    {
        queue->tail = queue->base;
    }
    queue->count--;
    return QUEUE_no_error;
}

queue_status_t queue_Top(queue_t* queue, void* data)
{
    /* Check null pointers */
    if (queue == NULL || queue->base == NULL || queue->head == NULL || queue->tail == NULL)
        return QUEUE_null;

    /* Check if queue is aready empty */
    if (queue_Is_Empty(queue) == QUEUE_empty)
        return QUEUE_empty;

    /* Dequeue data from queue */
    uint8_t i;
    for (i = 0; i < queue->element_Size; i++)
    {
        /* Copy data byte by byte from queue to data */
        *((uint8_t*)data + i) = *((uint8_t*)queue->tail + i);
    }

    return QUEUE_no_error;
}

queue_status_t queue_Print(queue_t* queue, char* printfSTR, queue_print_type_t type)
{
    typedef union
    {
        int8_t      int8;
        int16_t     int16;
        int32_t     int32;
        int64_t     int64;
        uint8_t     uint8;
        uint16_t    uint16;
        uint32_t    uint32;
        uint64_t    uint64;
        float       f32;
        double      f64;
    }dataHolder_t;

    /* Check null pointers */
    if (queue == NULL || queue->base == NULL || queue->head == NULL || queue->tail == NULL)
        return QUEUE_null;

    /* Check if queue is aready empty */
    if (queue_Is_Empty(queue) == QUEUE_empty)
        return QUEUE_empty;

    uint8_t i, j;
    uint8_t* tailPTR = queue->tail;
    dataHolder_t dataHolder;
    void* dataPTR = (uint8_t*)&dataHolder;
    printf("\n=============( Queue Print )=============\n");
    for (i = 0; i < queue->count; i++)
    {
        for (j = 0; j < queue->element_Size; j++)
        {
            /* Copy data byte by byte from queue to data */
            *((uint8_t*)dataPTR + j) = *((uint8_t*)tailPTR + j);
        }
        switch(type)
        {
            case PRINT_QUEUE_INT8:
            printf(printfSTR, dataHolder.int8);
            break;
            case PRINT_QUEUE_INT16:
            printf(printfSTR, dataHolder.int16);
            break;
            case PRINT_QUEUE_INT32:
            printf(printfSTR, dataHolder.int32);
            break;
            case PRINT_QUEUE_INT64:
            printf(printfSTR, dataHolder.int64);
            break;
            case PRINT_QUEUE_UINT8:
            printf(printfSTR, dataHolder.uint8);
            break;
            case PRINT_QUEUE_UINT16:
            printf(printfSTR, dataHolder.uint16);
            break;
            case PRINT_QUEUE_UINT32:
            printf(printfSTR, dataHolder.uint32);
            break;
            case PRINT_QUEUE_UINT64:
            printf(printfSTR, dataHolder.uint64);
            break;
            case PRINT_QUEUE_F32:
            printf(printfSTR, dataHolder.f32);
            break;
            case PRINT_QUEUE_F64:
            printf(printfSTR, dataHolder.f64);
            break;
            default:
            break;
        }
        

        tailPTR = (uint8_t*)tailPTR + queue->element_Size;
        if (tailPTR == ((uint8_t*)queue->base + (queue->length * queue->element_Size)))
        {
            tailPTR = queue->base;
        }
    }
    printf("=========================================\n");
    return QUEUE_no_error;

}