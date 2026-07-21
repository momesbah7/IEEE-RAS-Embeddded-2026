/*
 * SevenSegment.c
 *
 *  Author: Mohamed Mesbah
 *  Layer : HAL
 */ 
#define   F_CPU 8000000UL
#include "SevenSegment.h"
#include "DIO_interface.h"
#include "BIT_MATH.h"
#include <util/delay.h>

u8 SevSeg_Numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void SEVSEG_Init(void) {
	u8 i;
	for(i = 0; i < 7; i++) {
		DIO_SetPinDirection(DIO_PORTB_ID, i, DIO_PIN_OUTPUT);
	}
	DIO_SetPinDirection(DIO_PORTD_ID, 0, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD_ID, 1, DIO_PIN_OUTPUT);
}

void SEVSEG_Display(u8 number) {
	u8 units = number % 10;
	u8 tens = number / 10;
	u8 i;

	DIO_SetPinValue(DIO_PORTD_ID, 0, DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTD_ID, 1, DIO_PIN_HIGH);
	
	for(i = 0; i < 7; i++) {
		DIO_SetPinValue(DIO_PORTB_ID, i, GET_BIT(SevSeg_Numbers[units], i));
	}
	
	DIO_SetPinValue(DIO_PORTD_ID, 1, DIO_PIN_LOW);
	_delay_ms(5);

	DIO_SetPinValue(DIO_PORTD_ID, 0, DIO_PIN_HIGH);
	DIO_SetPinValue(DIO_PORTD_ID, 1, DIO_PIN_HIGH);
	
	for(i = 0; i < 7; i++) {
		DIO_SetPinValue(DIO_PORTB_ID, i, GET_BIT(SevSeg_Numbers[tens], i));
	}
	
	DIO_SetPinValue(DIO_PORTD_ID, 0, DIO_PIN_LOW);
	_delay_ms(5);
}