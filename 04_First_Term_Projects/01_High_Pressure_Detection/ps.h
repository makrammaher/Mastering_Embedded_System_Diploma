/*
 *           File: ps.c [Pressure Sensor]
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx High-Pressure Detector System
 *
 *
 */

#ifndef _PS_H_
#define _PS_H_

#include <stdint.h>
#include "state.h"
#include "driver.h"

/* States */
typedef enum
{
    PS_init,
    PS_busy
} PS_STATE_t;

/* Prototypes */
STATE_HEADER(PS_init);
STATE_HEADER(PS_busy);


/* External Variables */
extern void(*PS_state)(void);

#endif