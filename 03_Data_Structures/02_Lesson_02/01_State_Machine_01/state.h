/*
 *           File: state.h
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create a simple state machine (collision avoidance)
 *
 *
 */

#ifndef _STATE_H_
#define _STATE_H_

#define STATE_HEADER(_STATE_NAME_)  void STATE_##_STATE_NAME_(void)
#define STATE(_STATE_NAME_)         STATE_##_STATE_NAME_

#endif