/*
 * SEVSEG_program.c
 *
 *  Author: Mohamed Mesbah
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SEVSEG_interface.h"

/* Common Cathode Values */
static u8 SevenSeg_Arr[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void SEVSEG_Init(void) {
	/* Set PORTA as Output for 7-Segment */
	DIO_SetPortDirection(DIO_PORTA_ID, 0xFF);
}

void SEVSEG_Display(u8 Copy_u8Number) {
	if(Copy_u8Number <= 9) {
		DIO_SetPortValue(DIO_PORTA_ID, SevenSeg_Arr[Copy_u8Number]);
	}
}