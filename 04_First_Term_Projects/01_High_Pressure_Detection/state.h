/*
 *           File: state.h
 *     Created on: Wednesday 04/05/2022 20:42
 *         Author: Makram Maher Makram
 *        Subject: STM32F103Cx High-Pressure Detector System
 *
 *
 */

#ifndef _STATE_H_
#define _STATE_H_

#define STATE_HEADER(_STATE_NAME_)      void ST_##_STATE_NAME_(void)
#define STATE(_STATE_NAME_)              ST_##_STATE_NAME_

/* Connections */
uint8_t PS_get_pressure(void);
void AA_start_alarm(void);

#endif