/*
 *           File: state.h
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create state machine more advanced level :)
 *
 *
 */
#ifndef _STATE_H_
#define _STATE_H_


#define STATE_HEADER(_STATE_NAME_)      void ST_##_STATE_NAME_(void)
#define STATE(_STATE_NAME_)             ST_##_STATE_NAME_

/*Connections*/
void DC_MOTOR_set_speed(unsigned int s);
unsigned int US_SENSOR_get_distance(void);


#endif