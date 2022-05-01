/*
 *           File: US_Sensor.h
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create state machine more advanced level :)
 *
 *
 */

#ifndef _US_SENSOR_H_
#define _US_SENSOR_H_

#include <stdio.h>
#include <stdlib.h>
#include "state.h"

/* States */
typedef enum
{
    US_SENSOR_busy
} US_SENSOR_STATE_t;


/* Prototypes */
void US_SENSOR_init(void);
STATE_HEADER(US_SENSOR_busy);


/* External Variables */
extern void(*US_SENSOR_state)(void);


#endif