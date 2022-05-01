/*
 *           File: US_Sensor.c
 *     Created on: Sunday 01/05/2022 00:29
 *         Author: Makram Maher Makram
 *        Subject: Create state machine more advanced level :)
 *
 *
 */
#include "US_Sensor.h"


/* Global Variables */
void(*US_SENSOR_state)(void);
unsigned int distance;
US_SENSOR_STATE_t US_SENSOR_state_id;


/* Prototypes */
int get_random(int low, int high);


/* Function Definitions */
void US_SENSOR_init(void)
{
    /* Initialization of Ultrasonic Sensor */
    printf("US_SENSOR \t--> Initialization \n");
    distance = 0;
    US_SENSOR_state_id = US_SENSOR_busy;
    US_SENSOR_state = STATE(US_SENSOR_busy);
}

STATE_HEADER(US_SENSOR_busy)
{
    /* US_SENSOR_busy STATE */
    US_SENSOR_state_id = US_SENSOR_busy;

    /* Read the sensor reading to get new distance */
    distance = get_random(45, 55);

    printf("US_SENSOR(Busy)\t--> New distance = %u \n", distance);

    /* Next State is US_SENSOR_busy also */
    US_SENSOR_state = STATE(US_SENSOR_busy);
}

int get_random(int low, int high)
{
    return (rand() % (high - low + 1)) + low;
}

unsigned int US_SENSOR_get_distance(void)
{
    printf("US_Sensor\t---(distance = %u)--->\tCA\n\n", distance);
    return distance;
}