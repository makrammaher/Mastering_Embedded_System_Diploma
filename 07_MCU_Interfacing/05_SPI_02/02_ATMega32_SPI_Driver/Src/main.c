/*
 *           File: main.c
 *     Created on: Thursday 26/05/2022 20:46
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 Master SPI Interfacing
 *
 *
 */

#include "atmega32-spi.h"

void wait_ms(uint8_t time);

uint32_t i = 0;

void SevenSeg_SPI_Transmit(uint8_t cmd, uint8_t data)
{
    GPIO_Write_Pin(SPI_GPIO, SPI_SS_PIN, GPIO_PIN_LOW);
    SPI_Transmit(cmd, SPI_POLLING_ENABLE);
    SPI_Transmit(data, SPI_POLLING_ENABLE);
    GPIO_Write_Pin(SPI_GPIO, SPI_SS_PIN, GPIO_PIN_HIGH);
}

void SEND_NUM(uint32_t num)
{
    uint32_t i = 1;
    uint8_t deg = 0x08;
    uint32_t temp = num;
    while (temp && deg >= 0x01)
    {
        SevenSeg_SPI_Transmit(deg--, (temp / i) % 10);
        i = i * 10;
    }
}

volatile uint8_t dig = 7;
volatile static uint8_t n = 0;
volatile uint8_t state = 0;

void spi_CallBack(void)
{
    /* Disable Global Interrupts Mask */
    CLEARBIT(SREG, 7);

    state = (state + 1) % 2;
    if (state)
    {
        while(!SPI_Get_SPIF());
        GPIO_Write_Pin(SPI_GPIO, SPI_SS_PIN, GPIO_PIN_HIGH);
        wait_ms(10);
        GPIO_Write_Pin(SPI_GPIO, SPI_SS_PIN, GPIO_PIN_LOW);
        dig = ((dig + 1) % 8);
        SPI_Receive(SPI_POLLING_DISABLE);
        SPI_Transmit((dig + 1), SPI_POLLING_DISABLE);
    }
    else
    {
        if(dig == 7)
        {
            n = (n + 1) % 10;
            wait_ms(100);
        }
        while(!SPI_Get_SPIF());
        SPI_Receive(SPI_POLLING_DISABLE);
        SPI_Transmit(n, SPI_POLLING_DISABLE);
    }

    /* Enable Global Interrupts Mask */
    SETBIT(SREG, 7);

}

int main(void)
{
    /* Initialize SPI */
    SPI_Config spi_config;
    spi_config.Mode = SPI_MODE_MASTER;
    spi_config.Interrupt_Enable = SPI_INTERRUPT_ENABLE;
    spi_config.DataOrder = SPI_DATA_MSB_FIRST;
    spi_config.ClockRate = SPI_CLOCK_F_DIV_16;
    spi_config.P_IRQ_Callback = spi_CallBack;
    SPI_Init(&spi_config);

    wait_ms(100);

    /* Disable Global Interrupts Mask */
    CLEARBIT(SREG, 7);

    /* Shutdown Normal mode */
    SevenSeg_SPI_Transmit(0x0C, 0x01);

    /* Decode Mode for all digits */
    SevenSeg_SPI_Transmit(0x09, 0xFF);

    /* Set intensty as Maximum level */
    SevenSeg_SPI_Transmit(0x0A, 0xFF);

    /* Set Scan Limt as All digits */
    SevenSeg_SPI_Transmit(0x0B, 0x07);

    wait_ms(100);

    /* Enable Global Interrupts Mask */
    SETBIT(SREG, 7);

    
    while (1)
    {

    }
    return 0;
}
