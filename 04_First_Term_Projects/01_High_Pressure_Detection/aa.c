/*
 *           File: aa.c [Alarm Actuator]
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx High-Pressure Detector System
 *
 *
 */

#include "aa.h"


/* Global Variables */
void(*AA_state)(void) = STATE(AA_init);
AA_STATE_t AA_state_id;
uint32_t timer;

/* Function Definitions */
STATE_HEADER(AA_init)
{
    /* AA_init state */
    AA_state_id = AA_init;

    /* Action */
    timer = 0;
    Set_Alarm_actuator(1);

    /* Next state */
    AA_state = STATE(AA_alarm_off);
}


STATE_HEADER(AA_alarm_off)
{
    /* AA_alarm_off state */
    AA_state_id = AA_alarm_off;

    /* Action */
    /* set alarm off */
    Set_Alarm_actuator(1);

    /* Next State */
    AA_state = STATE(AA_alarm_off);
}


STATE_HEADER(AA_alarm_on)
{
    /* AA_alarm_off state */
    AA_state_id = AA_alarm_on;

    /* Action */
    /* set alarm on */
    Set_Alarm_actuator(0);

    /* Next State */
    if (timer != 0)
    {
        AA_state = STATE(AA_alarm_on);
        timer--;
    }
    else
    {
        /* timer expire turn off alarm */
        AA_state = STATE(AA_alarm_off);
    }

}

void AA_start_alarm(void)
{
    /* turn on alarm */
    AA_state = STATE(AA_alarm_on);
    /* set timer */
    timer = TIMER_NUMBER_COUNTS;
}