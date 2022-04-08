/*
 *           File: main.c
 *     Created on: Thursday 07/04/2022 19:09
 *         Author: Makram Maher Makram
 *        Subject: Testing Makefile
 *
 *
 */

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800

#include <stdint.h>

/* Over Ride NMI_handler in startup.c */
void NMI_handler(void)
{

}

/* Over Ride HardFault_handler in startup.c */
void HardFault_handler(void)
{

}

typedef union
{
    /* data */
    uint32_t allBytes;
    struct
    {
        /* data */
        uint32_t reserved : 2;
        uint32_t IOPAEN : 1;
    } PIN;

} APB2ENR_t;

typedef union
{
    /* data */
    uint32_t allBytes;
    struct
    {
        /* data */
        uint32_t reserved : 20;
        uint32_t MODE : 4;
    } PIN;
} GPIOA_CRH_t;

typedef union
{
    /* data */
    uint32_t allBytes;
    struct
    {
        /* data */
        uint32_t reserved : 13;
        uint32_t P_13 : 1;
    } PIN;
} GPIOA_ODR_t;

#define APB2ENR ((volatile APB2ENR_t *)(RCC_BASE + 0x18))
#define GPIOACRH ((volatile GPIOA_CRH_t *)(GPIOA_BASE + 0x04))
#define GPIOAODR ((volatile GPIOA_ODR_t *)(GPIOA_BASE + 0x0C))

/* [uninitialized global variable] in .bss Section */
uint32_t array_1[500]; 

/* [initialized global variable] in .data Section */
uint32_t array_2[16] = {
    0x00000000,
    0x11111111,
    0x22222222,
    0x33333333,
    0x44444444,
    0x55555555,
    0x66666666,
    0x77777777,
    0x88888888,
    0x99999999,
    0xaaaaaaaa,
    0xbbbbbbbb,
    0xcccccccc,
    0xdddddddd,
    0xeeeeeeee,
    0xffffffff
};

/* [constant global variable] in .rodata Section */
char const myNameStr[] = "Makram Maher Makram"; 

int main(void)
{
    /* [local variable, local constant variable, ] in stack */
    uint32_t i;
    uint8_t a_Stack = 20;
    uint8_t const b_Stack = 10;

    /* [Local Static Constant] in .rodata Section */
    static const uint8_t str[] = {'A','B','C','D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', '\0'};

    /* Strings in .rodata section but arrsSTR in stack */
    char * arrSTR[6] = {"aaaaaa", "bbbbbb", "cccccc", "dddddd", "eeeeee", "aaaaaa"};

    /* [uninitialized local static variable] in .bss section */
    static uint8_t array_3[1000];

    /* [initialized local static variable ] in .data section */
    static uint8_t array_4[16] = 
    {
        0x00,
        0x11,
        0x22,
        0x33,
        0x44,
        0x55,
        0x66,
        0x77,
        0x88,
        0x99,
        0xaa,
        0xbb,
        0xcc,
        0xdd,
        0xee,
        0xff
    };
    

    /* initializing array_1 in .bss section in SRAM */
    for(i = 0;i<500;i++)
    {
        array_1[i] = i;
    }

    /* initializing array_3 in .bss section in SRAM */
    for(i = 0;i<1000;i++)
    {
        array_3[i] = i%255;
    }
    
    APB2ENR->PIN.IOPAEN = 1;
    GPIOACRH->PIN.MODE = 2;
    
    while (1)
    {
        GPIOAODR->PIN.P_13 = 1;
        for (i = 0; i < 150000; i++)
            ;
        GPIOAODR->PIN.P_13 = 0;
        for (i = 0; i < 150000; i++)
            ;
    }
    return 0;
}
