/*
 *           File: main.c
 *     Created on: Wednesday 20/04/2022 15:09
 *         Author: Makram Maher Makram
 *        Subject: Create Generic Circular Queue (FIFO) Data structure
 *
 *
 */

#include <stdio.h>
#include "queue.h"

#define queue_uint16_size   5
#define queue_float_size    5

int main(void)
{
    /* create a queue of 20 uint16_t and initialize it */
    queue_t queue_uint16;
    uint16_t buffer_uint16[queue_uint16_size];
    queue_Init(&queue_uint16, buffer_uint16, queue_uint16_size, sizeof(uint16_t));
    /* ----------------------------------------------- */

    uint16_t i, data;
    
    for (i = 0; i < 6; i++)
    {
        queue_status_t status = queue_Enqueue(&queue_uint16, &i);
        switch(status)
        {
            case QUEUE_no_error:
            printf("Done  --> Enqueue %d to queue_uint16\n", i);
            break;
            case QUEUE_full:
            printf("Error --> queue is full\n");
            break;
            default:
            break;
        }
    }

    puts("");

    queue_Print(&queue_uint16, "%d\n", PRINT_QUEUE_UINT16);

    puts("");
    for (i = 0; i < 6; i++)
    {
        queue_status_t status = queue_Dequeue(&queue_uint16, &data);
        switch(status)
        {
            case QUEUE_no_error:
            printf("Done  --> Dequeue %d from queue_uint16\n", data);
            break;
            case QUEUE_empty:
            printf("Error --> queue is empty\n");
            break;
            default:
            break;
        }
    }
    puts("");

    /* create a queue of 10 float and initialize it */
    queue_t queue_float;
    float buffer_float[queue_float_size];
    queue_Init(&queue_float, buffer_float, queue_float_size, sizeof(float));
    /* -------------------------------------------- */

    float f, fdata;

    for (f = 1.0; f < 1.6; f += 0.1)
    {
        queue_status_t status = queue_Enqueue(&queue_float, &f);
        switch(status)
        {
            case QUEUE_no_error:
            printf("Done  --> Enqueue %.1f to queue_float\n", f);
            break;
            case QUEUE_full:
            printf("Error --> queue is full\n");
            break;
            default:
            break;
        }
    }
    puts("");
    
    for (i = 0; i < 2; i++)
    {
        queue_status_t status = queue_Dequeue(&queue_float, &fdata);
        switch(status)
        {
            case QUEUE_no_error:
            printf("Done  --> Dequeue %.1f from queue_float\n", fdata);
            break;
            case QUEUE_empty:
            printf("Error --> queue is empty\n");
            break;
            default:
            break;
        }
    }

    puts("");

    queue_Print(&queue_float, "%.1f\n", PRINT_QUEUE_F32);

    puts("");

    for (f = 1.0; f < 1.6; f += 0.1)
    {
        queue_status_t status = queue_Enqueue(&queue_float, &f);
        switch(status)
        {
            case QUEUE_no_error:
            printf("Done  --> Enqueue %.1f to queue_float\n", f);
            break;
            case QUEUE_full:
            printf("Error --> queue is full\n");
            break;
            default:
            break;
        }
    }

    puts("");

    for (i = 0; i < 6; i++)
    {
        queue_status_t status = queue_Dequeue(&queue_float, &fdata);
        switch(status)
        {
            case QUEUE_no_error:
            printf("Done  --> Dequeue %.1f from queue_float\n", fdata);
            break;
            case QUEUE_empty:
            printf("Error --> queue is empty\n");
            break;
            default:
            break;
        }
    }

    return 0;
}