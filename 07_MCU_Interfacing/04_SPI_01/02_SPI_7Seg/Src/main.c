/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 Master SPI - 7Seg
 *
 *
 */

#include "atmega32-gpio.h"

void wait_ms(uint8_t time);

void SPI_Init(void)
{
    GPIO_Init(GPIOB, GPIO_MODE_OUTPUT, GPIO_PIN_4);
    GPIO_Init(GPIOB, GPIO_MODE_OUTPUT, GPIO_PIN_5);
    GPIO_Init(GPIOB, GPIO_MODE_OUTPUT, GPIO_PIN_7);
    GPIO_Write_Pin(GPIOB, GPIO_PIN_4, GPIO_PIN_HIGH);
    GPIO_Init(GPIOB, GPIO_MODE_INPUT_FLOATING, GPIO_PIN_6);

    SETBIT(SPCR, 4);
    SETBIT(SPCR, 6);
}

void SPI_Transmit(uint8_t cmd, uint8_t data)
{
    GPIO_Write_Pin(GPIOB, GPIO_PIN_4, GPIO_PIN_LOW);
    SPDR = cmd;
    while (!(SPSR & (1 << 7)))
        ;
    SPDR = data;
    while (!(SPSR & (1 << 7)))
        ;
    GPIO_Write_Pin(GPIOB, GPIO_PIN_4, GPIO_PIN_HIGH);
}

void SEND_NUM(uint32_t num)
{
    uint32_t i = 1;
    uint8_t deg = 0x08;
    uint32_t temp = num;
    while (temp && deg >= 0x01)
    {
        SPI_Transmit(deg--, (temp / i) % 10);
        i = i * 10;
    }
}

int main(void)
{
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_0);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_1);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_2);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_3);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_4);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_5);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_6);
    GPIO_Init(GPIOA, GPIO_MODE_OUTPUT, GPIO_PIN_7);
    GPIO_Write_Port(GPIOA, 0);
    SPI_Init();
    wait_ms(100);

    /* Shutdown Normal mode */
    SPI_Transmit(0x0C, 0x01);

    /* Decode Mode for all digits */
    SPI_Transmit(0x09, 0xFF);

    /* Set intensty as Maximum level */
    SPI_Transmit(0x0A, 0xFF);

    /* Set Scan Limt as All digits */
    SPI_Transmit(0x0B, 0x07);
    SEND_NUM(00000000);
    wait_ms(255);
    SEND_NUM(11111111);
    wait_ms(255);
    SEND_NUM(22222222);
    wait_ms(255);
    SEND_NUM(33333333);
    wait_ms(255);
    SEND_NUM(44444444);
    wait_ms(255);
    SEND_NUM(55555555);
    wait_ms(255);
    SEND_NUM(66666666);
    wait_ms(255);
    SEND_NUM(77777777);
    wait_ms(255);
    SEND_NUM(88888888);
    wait_ms(255);
    SEND_NUM(99999999);
    wait_ms(255);

    uint32_t i = 1;
    while (1)
    {
        SEND_NUM(i++);
        wait_ms(100);
    }
    return 0;
}