/*
 *           File: hpd.h [High Pressure Detector]
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx High-Pressure Detector System
 *
 *
 */

#ifndef _HPD_H_
#define _HPD_H_

#include <stdint.h>
#include "state.h"

/* States */
typedef enum
{
    HPD_init,
    HPD_normal_pressure,
    HPD_high_pressure
} HPD_STATE_t;

/* Prototypes */
STATE_HEADER(HPD_init);
STATE_HEADER(HPD_normal_pressure);
STATE_HEADER(HPD_high_pressure);

/* External Variables */
extern void(*HPD_state)(void);


#endif