/*
 *           File: Platform_Types.h
 *     Created on: Tuesday 29/03/2022 20:34
 *         Author: Makram Maher Makram
 *        Subject: Platform Types depends on AUTOSAR Standard for STMicroelectronics ST30
 *
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
	
	#define CPU_TYPE_8			8
	#define CPU_TYPE_16			16
	#define CPU_TYPE_32			32
	
	#define MSB_FIRST			0
	#define LSB_FIRST			1

	#define HIGHT_BYTR_FIRST	0
	#define LOW_BYTE_FIRST		1
	
	#ifndef TRUE
		#define TRUE 	((boolean) 1)
	#endif
	#ifndef FALSE
		#define FALSE	((boolean) 0)
	#endif

	#define CPU_TYPE			CPU_TYPE_16
	#define CPU_BIT_ORDER		LSB_FIRST
	#define CPU_BYTE_ORDER		LOW_BYTE_FIRST
	
	typedef unsigned short		boolean;		/* 0 --> 1 (Optimized) */

	typedef unsigned char		uint8;			/* 0 --> 255 */
	typedef unsigned short		uint16;			/* 0 --> 65535 */
	typedef unsigned long		uint32;			/* 0 --> 4294967295 */
	typedef signed char			sint8;			/* -128 --> 127 */
	typedef signed short		sint16;			/* -32768 --> 32767 */
	typedef signed long			sint32;			/* -2147483648 --> 2147483647 */
	
	typedef unsigned short		uint8_least;	/* 0 --> 255 (Optimized) */
	typedef unsigned short		uint16_least;	/* 0 --> 65535 */
	typedef unsigned long		uint32_least;	/* 0 --> 4294967295 */
	typedef signed short		sint8_least;	/* -128 --> 127 (Optimized) */
	typedef signed short		sint16_least;	/* -32768 --> 32767 */
	typedef signed long			sint32_least;	/* -2147483648 --> 2147483647 */

	typedef float			 	float32;
	typedef double				float64;
	
#endif