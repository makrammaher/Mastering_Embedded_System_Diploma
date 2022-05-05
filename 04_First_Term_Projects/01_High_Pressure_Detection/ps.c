/*
 *           File: ps.c [Pressure Sensor]
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx High-Pressure Detector System
 *
 *
 */

#include "ps.h"

/* Global Variables */
void(*PS_state)(void) = STATE(PS_init);
PS_STATE_t PS_state_id;
uint8_t AA_pressure;

/* Function Definitions */
STATE_HEADER(PS_init)
{
    /* PS_init state */
    PS_state_id = PS_init;

    /* Action */
    AA_pressure = 0;

    /* Next state */
    PS_state = STATE(PS_busy);
}

STATE_HEADER(PS_busy)
{
    /* PS_busy state */
    PS_state_id = PS_busy;

    /* Read AA_pressure from sensor */
    AA_pressure = getPressureVal();

    /* Next state is PS_busy state */
    PS_state = STATE(PS_busy);
}

uint8_t PS_get_pressure(void)
{
    return AA_pressure;
}