/*
 *           File: aa.h [Alarm Actuator]
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx High-Pressure Detector System
 *
 *
 */

#ifndef _AA_H_
#define _AA_H_


#include <stdint.h>
#include "state.h"
#include "driver.h"

#define TIMER_NUMBER_COUNTS     10000

/* States */
typedef enum
{
    AA_init,
    AA_alarm_off,
    AA_alarm_on
} AA_STATE_t;

/* Prototypes */
STATE_HEADER(AA_init);
STATE_HEADER(AA_alarm_off);
STATE_HEADER(AA_alarm_on);

/* External Variables */
extern void(*AA_state)(void);

#endif