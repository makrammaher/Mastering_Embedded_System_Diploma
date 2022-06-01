/*
 *           File: bcd_7seg.c
 *     Created on: Monday 30/05/2022 19:43
 *         Author: Makram Maher Makram
 *        Subject: STM32F103C6 7seg Driver
 *
 *
 */

#include "bcd_7seg.h"

void bcd_7seg_Init(void)
{
    GPIO_Init(BCD_7SEG_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, BCD_7SEG_P0);
    GPIO_Init(BCD_7SEG_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, BCD_7SEG_P1);
    GPIO_Init(BCD_7SEG_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, BCD_7SEG_P2);
    GPIO_Init(BCD_7SEG_GPIO, GPIO_MODE_OUTPUT_PP_2MHZ, BCD_7SEG_P3);
    GPIO_Write_Pin(BCD_7SEG_GPIO, BCD_7SEG_P0, GPIO_PIN_RESET);
    GPIO_Write_Pin(BCD_7SEG_GPIO, BCD_7SEG_P1, GPIO_PIN_RESET);
    GPIO_Write_Pin(BCD_7SEG_GPIO, BCD_7SEG_P2, GPIO_PIN_RESET);
    GPIO_Write_Pin(BCD_7SEG_GPIO, BCD_7SEG_P3, GPIO_PIN_RESET);
}
void bcd_7deg_Write(uint8_t num)
{
    GPIO_Write_Pin(BCD_7SEG_GPIO, BCD_7SEG_P0, ((num & (0x01))>>0));
    GPIO_Write_Pin(BCD_7SEG_GPIO, BCD_7SEG_P1, ((num & (0x02))>>1));
    GPIO_Write_Pin(BCD_7SEG_GPIO, BCD_7SEG_P2, ((num & (0x04))>>2));
    GPIO_Write_Pin(BCD_7SEG_GPIO, BCD_7SEG_P3, ((num & (0x08))>>3));
}