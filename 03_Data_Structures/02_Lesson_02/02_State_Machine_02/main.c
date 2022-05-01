/*
 *           File: main.c
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create state machine more advanced level :)
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "US_Sensor.h"
#include "DC_Motor.h"
#include "collisionAvoidance.h"


void setup(void)
{
    DC_MOTOR_init();
    US_SENSOR_init();
    CA_init();
}

int main(void)
{
    setup();

    while (1)
    {
        DC_MOTOR_state();
        US_SENSOR_state();
        CA_state();
    }

    return 0;
}