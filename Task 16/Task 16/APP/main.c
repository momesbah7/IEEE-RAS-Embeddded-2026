/*
 * Task 16.c
 *
 * Created: 7/20/2026 2:51:13 PM
 * Author : HP
 */ 

#include "DIO_interface.h"
#include "SevenSegment.h"

int main(void) {
	u8 counter;
	u8 i;
	
	SEVSEG_Init();
	
	DIO_SetPinDirection(DIO_PORTA_ID, 0, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA_ID, 1, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA_ID, 2, DIO_PIN_OUTPUT);

	while (1) {
		DIO_SetPinValue(DIO_PORTA_ID, 0, DIO_PIN_HIGH);
		DIO_SetPinValue(DIO_PORTA_ID, 1, DIO_PIN_LOW);
		DIO_SetPinValue(DIO_PORTA_ID, 2, DIO_PIN_LOW);
		for(counter = 15; counter > 0; counter--) {
			for(i = 0; i < 100; i++) { SEVSEG_Display(counter); }
		}

		DIO_SetPinValue(DIO_PORTA_ID, 0, DIO_PIN_LOW);
		DIO_SetPinValue(DIO_PORTA_ID, 1, DIO_PIN_HIGH);
		DIO_SetPinValue(DIO_PORTA_ID, 2, DIO_PIN_LOW);
		for(counter = 5; counter > 0; counter--) {
			for(i = 0; i < 100; i++) { SEVSEG_Display(counter); }
		}

		DIO_SetPinValue(DIO_PORTA_ID, 0, DIO_PIN_LOW);
		DIO_SetPinValue(DIO_PORTA_ID, 1, DIO_PIN_LOW);
		DIO_SetPinValue(DIO_PORTA_ID, 2, DIO_PIN_HIGH);
		for(counter = 10; counter > 0; counter--) {
			for(i = 0; i < 100; i++) { SEVSEG_Display(counter); }
		}
	}
	return 0;
}

