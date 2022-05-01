/*
 *           File: DC_Motor.c
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create state machine more advanced level :)
 *
 *
 */

#include "DC_Motor.h"


/* Global Variables */
void(*DC_MOTOR_state)(void);
unsigned int idelSpeed, speed;
DC_MOTOR_STATE_t DC_MOTOR_state_id;

/* Function Definitions */
void DC_MOTOR_init(void)
{
    /* Initialization of DC Motor */
    printf("DC_MOTOR \t--> Initialization \n");
    idelSpeed = 0;
    speed = 0;
    DC_MOTOR_state_id = DC_MOTOR_idel;
    DC_MOTOR_state = STATE(DC_MOTOR_idel);
}

STATE_HEADER(DC_MOTOR_idel)
{
    DC_MOTOR_state_id = DC_MOTOR_idel;
    printf("DC_MOTOR(Idel)\t--> idelSpeed = %u speed = %u\n", idelSpeed, speed);
    if (speed == idelSpeed)
    {
        DC_MOTOR_state = STATE(DC_MOTOR_idel);
    }
    else
    {
        DC_MOTOR_state = STATE(DC_MOTOR_busy);
    }
}

STATE_HEADER(DC_MOTOR_busy)
{
    DC_MOTOR_state_id = DC_MOTOR_busy;

    /* apply new speed */
    idelSpeed = speed;
    printf("DC_MOTOR(Busy)\t--> idelSpeed = %u speed = %u\n", idelSpeed, speed);

    /* Next State is DC_MOTOR_idel */
    DC_MOTOR_state = STATE(DC_MOTOR_idel);
}

void DC_MOTOR_set_speed(unsigned int s)
{
    /* set new speed */
    printf("\nCA\t\t---(speed = %u)------>\tDC_Motor\n", s);
    speed = s;
    if (speed == idelSpeed)
    {
        DC_MOTOR_state = STATE(DC_MOTOR_idel);
    }
    else
    {
        DC_MOTOR_state = STATE(DC_MOTOR_busy);
    }
}