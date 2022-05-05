/*
 *           File: main.c
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx High-Pressure Detector System
 *
 *
 */

/* Pressure Sensor Module */
#include "ps.h"
/* High Pressure Detector Module */
#include "hpd.h"
/* Alarm Actuator Module */
#include "aa.h"

int main (void)
{
    GPIO_INITIALIZATION();
    while (1)
    {
        PS_state();
        HPD_state();
        AA_state();
    }
    return 0;
}
