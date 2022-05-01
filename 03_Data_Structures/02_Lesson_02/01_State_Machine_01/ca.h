/*
 *           File: ca.h
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create a simple state machine (collision avoidance)
 *
 *
 */
#ifndef _CA_H_
#define _CA_H_

#include <stdio.h>
#include <stdlib.h>
#include "state.h"

/* external variables */
extern void(*CA_state)();

/* collision avoidance states */
typedef enum
{
    CA_waiting,
    CA_driving
} CA_state_t;


/* prototypes */
STATE_HEADER(CA_waiting);
STATE_HEADER(CA_driving);
void CA_init(void);
int generate_random(int low, int high);


#endif