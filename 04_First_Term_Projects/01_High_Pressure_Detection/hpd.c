/*
 *           File: hpd.c [High Pressure Detector]
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx High-Pressure Detector System
 *
 *
 */

#include "hpd.h"

void(*HPD_state)(void) = STATE(HPD_init);
HPD_STATE_t HPD_state_id;
uint8_t threshold, pressure, alarmStatus;

STATE_HEADER(HPD_init)
{
    /* HPD_init State */
    HPD_state_id = HPD_init;

    /* Action */
    threshold = 20;
    pressure = 0;
    alarmStatus = 0;

    /* Next State */
    HPD_state = STATE(HPD_normal_pressure);
}

STATE_HEADER(HPD_normal_pressure)
{
    /* HPD_normal_pressure State */
    HPD_state_id = HPD_normal_pressure;

    /* Action */
    pressure = PS_get_pressure();

    /* Next State */
    if (pressure > threshold)
    {
        HPD_state = STATE(HPD_high_pressure);
    }
    else
    {
        HPD_state = STATE(HPD_normal_pressure);
    }
}

STATE_HEADER(HPD_high_pressure)
{
    /* HPD_high_pressure State */
    HPD_state_id = HPD_high_pressure;

    /* Action */
    AA_start_alarm();
    pressure = PS_get_pressure();

    /* Next State */
    if (pressure > threshold)
    {
        HPD_state = STATE(HPD_high_pressure);
    }
    else
    {
        HPD_state = STATE(HPD_normal_pressure);
    }
}