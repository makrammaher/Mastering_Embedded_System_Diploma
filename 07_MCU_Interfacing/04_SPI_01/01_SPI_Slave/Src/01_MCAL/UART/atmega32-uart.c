/*
 *           File: atmega32-uart.c
 *     Created on: Sunday 12/06/2022 20:30
 *         Author: Makram Maher Makram
 *        Subject: ATMEGA32 UART Driver
 *
 *
 */

#include "atmega32-uart.h"
#include "math.h"

static volatile uint8_t USART_TX_Buf[USART_TX_BUFFER_SIZE];
static volatile uint8_t USART_RX_Buf[USART_RX_BUFFER_SIZE];

static volatile uint8_t USART_TX_Buf_Head;
static volatile uint8_t USART_TX_Buf_Tail;

static volatile uint8_t USART_RX_Buf_Head;
static volatile uint8_t USART_RX_Buf_Tail;

static volatile char USART_String_terminator;
static volatile uint8_t USART_Number_of_Strings;

/* ISR USART_UDRE_vect */
void __vector_14(void) __attribute__((signal, used, externally_visible));
void __vector_14(void)
{
    if (USART_TX_Buf_Head != USART_TX_Buf_Tail)
    {
        /* Calculate new Tail */
        USART_TX_Buf_Tail = (USART_TX_Buf_Tail + 1) % USART_TX_BUFFER_SIZE;
        /* Send Next Byte */
        UDR = USART_TX_Buf[USART_TX_Buf_Tail];
    }
    else
    {
        /* Disable UDRE Interrupt */
        CLEARBIT(UCSRB, 5);
    }
}

/* ISR USART_RXC_vect */
void __vector_13(void) __attribute__((signal, used, externally_visible));
void __vector_13(void)
{
    uint8_t tempHead;
    uint8_t data;
    data = UDR;
    if (data == USART_String_terminator)
    {
        USART_Number_of_Strings++;
    }
    tempHead = (USART_RX_Buf_Head + 1) % USART_RX_BUFFER_SIZE;
    /* Check Buffer is full or not */
    if (tempHead != USART_RX_Buf_Tail)
    {
        USART_RX_Buf_Head = tempHead;
        USART_RX_Buf[USART_RX_Buf_Head] = data;
    }
    /* Else the new data will be lost :( */
}

/**
 * @brief
 *
 * @param Config : is a poiner to USART_Config structure that hold the configuration of the USART
 */
void USART_Init(USART_Config_t *Config)
{
    /* Disable Global Interrupts Mask */
    CLEARBIT(SREG, 7);

    /* Initialize tail and head of circular queue */
    USART_TX_Buf_Head = 0;
    USART_TX_Buf_Tail = 0;
    USART_RX_Buf_Head = 0;
    USART_RX_Buf_Tail = 0;
    USART_Number_of_Strings = 0;
    USART_String_terminator = Config->String_Terminator;

    /* Set Baudrate first */
    UBRRL = (Config->UBRR_Value & 0xFF);
    UBRRH &= ~(0x0F);
    UBRRH |= ((Config->UBRR_Value >> 8) & 0x0F);
    /* Set Double speed or not */
    UCSRA &= ~(Config->Speed_Mode);

    /* Set UCSRB Register */
    UCSRB &= ~(0b10111100);
    UCSRB |= ((Config->Mode & 0b11000) | ((Config->Data & 0b1000) >> 1) | Config->Interrupt);

    /* Set UCSRC Register */
    UCSRC &= ~(0b01111110);
    UCSRC |= (((Config->Mode & 0b100000) << 1) | Config->Parity | Config->Stop | (Config->Data & 0b110));

    /* Enable Global Interrupts Mask */
    SETBIT(SREG, 7);
}

/**
 * @brief Flush Transmitter Buffer
 *
 */
void USART_Flush_TX_Buf(void)
{
    USART_TX_Buf_Head = USART_TX_Buf_Tail;
}

/**
 * @brief Flush Reciver Buffer
 *
 */
void USART_Flush_RX_Buf(void)
{
    USART_RX_Buf_Head = USART_RX_Buf_Tail;
}

/**
 * @brief get number or recived bytes in rx buffer
 *
 * @return uint8_t Number of bytes available in rx buffer
 */
uint8_t USART_Available_Bytes(void)
{
    /* Disable Global Interrupts Mask */
    CLEARBIT(SREG, 7);
    uint8_t numOfBytes = (USART_RX_BUFFER_SIZE + USART_RX_Buf_Head - USART_RX_Buf_Tail) % USART_RX_BUFFER_SIZE;
    /* Enable Global Interrupts Mask */
    SETBIT(SREG, 7);
    return numOfBytes;
}

/**
 * @brief this is asychnronous function to send one byte using tx buffer
 *
 * @param Byte byte to be sent
 */
void USART_SendByte(uint8_t Byte)
{
    uint8_t tempHead;

    /* Calculate next Head index */
    tempHead = (USART_TX_Buf_Head + 1) % USART_TX_BUFFER_SIZE;

    if (tempHead != USART_TX_Buf_Tail)
    {
        USART_TX_Buf[tempHead] = Byte;
        USART_TX_Buf_Head = tempHead;
        SETBIT(UCSRB, 5);
    }
}

/**
 * @brief this is asychnronous function to send number of bytes using tx buffer
 *
 * @param Buffer pointer to buffer that holds bytes to be send
 * @param size size of the buffer that will be send
 */
void USART_SendBytes(uint8_t *Buffer, uint8_t size)
{
    uint8_t i = 0;
    for (i = 0; i < size; i++)
    {
        USART_SendByte(Buffer[i]);
    }
}

/**
 * @brief this is asychnronous function to send string using tx buffer
 *
 * @param Str : pointer to the first char of string
 * @param size : Maximum size of str
 */
void USART_SendString(const char *Str, uint8_t size)
{
    uint8_t i = 0;
    while (*(Str + i) && (i < size))
    {
        USART_SendByte(*(Str + i));
        i++;
    }
}

/**
 * @brief this is asychnronous function to send one byte using tx buffer
 *
 * @param Byte byte to be sent
 */
uint8_t USART_GetByte(void)
{
    uint8_t data;
    if (USART_RX_Buf_Head == USART_RX_Buf_Tail)
    {
        data = 0;
    }
    else
    {
        /* Disable Global Interrupts Mask */
        CLEARBIT(SREG, 7);
        USART_RX_Buf_Tail = (USART_RX_Buf_Tail + 1) % USART_RX_BUFFER_SIZE;
        data = USART_RX_Buf[USART_RX_Buf_Tail];
        /* Enable Global Interrupts Mask */
        SETBIT(SREG, 7);
    }
    return data;
}

/**
 * @brief this is asychnronous function to send number of bytes using tx buffer
 *
 * @param Buffer pointer to buffer that holds bytes to be send
 * @param size size of the buffer that will be send
 */
void USART_GetBytes(uint8_t *Buffer, uint8_t size)
{
    uint8_t i = 0;
    for (i = 0; i < size; i++)
    {
        Buffer[i] = USART_GetByte();
    }
}

/**
 * @brief this is asychnronous function to get string using rx buffer
 *
 * @param Str : pointer to the first char of string
 * @param size : Maximum size of str
 * @param terminator : Terminator character
 */
void USART_GetString(char *Str, uint8_t size)
{
    uint8_t i = 0;
    while (USART_Number_of_Strings <= 0)
        ;
    char tempChar = (char)USART_GetByte();
    while (i < size && tempChar != USART_String_terminator && tempChar != 0)
    {
        Str[i] = tempChar;
        tempChar = (char)USART_GetByte();
        i++;
    }
    USART_Number_of_Strings--;
}

/**
 * @brief
 *
 * @param Data : the data to be tansmitted
 */
void USART_Transmit(uint16_t Data)
{
    while (!(UCSRA & (1 << 5)))
        ;
    UCSRB &= ~(1 << 0);
    UCSRB |= ((Data & 0x100) >> 8);
    UDR = Data & 0xFF;
}

/**
 * @brief
 *
 * @return uint16_t : the recived data
 */
uint16_t USART_Recive(void)
{
    while (!(UCSRA & (1 << 7)))
        ;
    uint16_t Data = 0;
    Data = (uint16_t)(UCSRB & (1 << 1)) << 7;
    Data |= UDR;
    return Data;
}
