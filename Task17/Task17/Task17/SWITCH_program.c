/*
 * SWITCH_interface.c
 *
 *  Author: Mohamed Mesbah
 *  Layer : HAL
 */ 


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SWITCH_interface.h"

void SWITCH_Init(void) {
	/* Configure Switch pins as Input */
	DIO_SetPinDirection(SWITCH_PORT, SWITCH_FWD_PIN, DIO_PIN_INPUT);
	DIO_SetPinDirection(SWITCH_PORT, SWITCH_BWD_PIN, DIO_PIN_INPUT);
	DIO_SetPinDirection(SWITCH_PORT, SWITCH_RIGHT_PIN, DIO_PIN_INPUT);
	DIO_SetPinDirection(SWITCH_PORT, SWITCH_LEFT_PIN, DIO_PIN_INPUT);
	DIO_SetPinDirection(SWITCH_PORT, SWITCH_STOP_PIN, DIO_PIN_INPUT);
	
	/* Enable Internal Pull-up Resistors */
	DIO_SetPinValue(SWITCH_PORT, SWITCH_FWD_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(SWITCH_PORT, SWITCH_BWD_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(SWITCH_PORT, SWITCH_RIGHT_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(SWITCH_PORT, SWITCH_LEFT_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(SWITCH_PORT, SWITCH_STOP_PIN, DIO_PIN_HIGH);
}

u8 SWITCH_GetState(u8 copy_pin_num) {
	/* Return the current state of the specified switch pin */
	return DIO_GetPinValue(SWITCH_PORT, copy_pin_num);
}
