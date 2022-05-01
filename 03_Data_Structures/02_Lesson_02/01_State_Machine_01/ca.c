/*
 *           File: ca.c
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create a simple state machine (collision avoidance)
 *
 *
 */
#include "ca.h"

unsigned int CA_speed, CA_distance, CA_threshold;
CA_state_t CA_state_id;
void(*CA_state)();

/* Collision Avoidance State Machine initialization */
void CA_init(void)
{
    CA_state_id = CA_waiting;
    CA_state = STATE(CA_waiting);
    CA_speed = 0;
    CA_threshold = 50;
}

/* waiting state */
STATE_HEADER(CA_waiting)
{
    /* State Action */
    CA_state_id = CA_waiting;
    CA_speed = 0;

    /* Read From Ultasonic Sensor */
    CA_distance = generate_random(45, 55);

    /* Print State */
    printf("STATE: waiting \ndistance: %d - speed: %d\n------------\n", CA_distance, CA_speed);

    /* Check Event */
    (CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

}

/* driving state */
STATE_HEADER(CA_driving)
{
    /* State Action */
    CA_state_id = CA_driving;
    CA_speed = 30;

    /* Read From Ultasonic Sensor */
    CA_distance = generate_random(45, 55);

    /* Print State */
    printf("STATE: driving \ndistance: %d - speed: %d\n------------\n", CA_distance, CA_speed);

    /* Check Event */
    (CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
}

int generate_random(int low, int high)
{
    int rand_num = (rand() % ((high - low) + 1)) + low;
    return rand_num;
}
