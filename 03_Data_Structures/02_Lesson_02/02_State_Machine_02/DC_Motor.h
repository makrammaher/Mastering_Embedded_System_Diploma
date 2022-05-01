/*
 *           File: DC_Motor.h
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create state machine more advanced level :)
 *
 *
 */

#ifndef _DC_MOTOR_H_
#define _DC_MOTOR_H_

#include <stdio.h>
#include "state.h"

/* States */
typedef enum
{
    DC_MOTOR_idel,
    DC_MOTOR_busy
} DC_MOTOR_STATE_t;


/* Prototypes */
void DC_MOTOR_init(void);
STATE_HEADER(DC_MOTOR_idel);
STATE_HEADER(DC_MOTOR_busy);


/* External Variables */
extern void(*DC_MOTOR_state)(void);



#endif