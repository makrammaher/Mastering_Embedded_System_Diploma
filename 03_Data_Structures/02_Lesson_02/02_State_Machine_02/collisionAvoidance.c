/*
 *           File: collisionAvoidance.c
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create state machine more advanced level :)
 *
 *
 */
#include "collisionAvoidance.h"

/* Global variables */
void(*CA_state)(void);
CA_STATE_t CA_state_id;
unsigned int speed, distance, threshold;

void CA_init(void)
{
    printf("CA \t\t--> Initialization \n");
    CA_state_id = CA_waiting;
    CA_state = STATE(CA_waiting);
    speed = 0;
    distance = 0;
    threshold = 50;
}


STATE_HEADER(CA_waiting)
{
    CA_state_id = CA_waiting;

    /* Set Speed in DC_Motor */
    speed = 0;
    DC_MOTOR_set_speed(speed);
    /* Get new distance from US_Sensor */
    distance = US_SENSOR_get_distance();

    printf("CA(Waiting)\t--> speed = %u distance = %u\n", speed, distance);

    (distance <= threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
}

STATE_HEADER(CA_driving)
{
    CA_state_id = CA_driving;

    /* Set Speed in DC_Motor */
    speed = 30;
    DC_MOTOR_set_speed(speed);
    /* Get new distance from US_Sensor */
    distance = US_SENSOR_get_distance();

    printf("CA(Driving)\t--> speed = %u distance = %u\n", speed, distance);

    (distance <= threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
}
