/*
 *           File: collisionAvoidance.h
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create state machine more advanced level :)
 *
 *
 */

#ifndef _COLLISION_AVOIDANCE_H_
#define _COLLISION_AVOIDANCE_H_

#include <stdio.h>
#include "state.h"


/* States */
typedef enum
{
    CA_waiting,
    CA_driving
} CA_STATE_t;


/* Prototypes */
void CA_init(void);
STATE_HEADER(CA_waiting);
STATE_HEADER(CA_driving);

/* External Variables */
extern void(*CA_state)(void);

#endif