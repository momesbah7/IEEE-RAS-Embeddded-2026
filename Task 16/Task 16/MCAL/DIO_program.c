/*
 * Private.h
 *
 *  Author: Mohamed Mesbah
 *  Layer : MCAL
 *  SWC   : DIO
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void    DIO_SetPinDirection  (u8 port_num, u8 pin_num, u8 direction){
	
	if (direction == DIO_PIN_OUTPUT){
		
		switch (port_num)
		{
		case DIO_PORTA_ID: SET_BIT(DDRA, pin_num); break;
		case DIO_PORTB_ID: SET_BIT(DDRB, pin_num); break;
		case DIO_PORTC_ID: SET_BIT(DDRC, pin_num); break;
		case DIO_PORTD_ID: SET_BIT(DDRD, pin_num); break;
		}
	}
	 else if (direction == DIO_PIN_INPUT){
	    switch(port_num) {
		case DIO_PORTA_ID: CLR_BIT(DDRA, pin_num); break;
		case DIO_PORTB_ID: CLR_BIT(DDRB, pin_num); break;
		case DIO_PORTC_ID: CLR_BIT(DDRC, pin_num); break;
		case DIO_PORTD_ID: CLR_BIT(DDRD, pin_num); break;
    	}
    }
}

void    DIO_SetPinValue      (u8 port_num, u8 pin_num, u8 value){
	
	if (value == DIO_PIN_HIGH){
		
	    switch (port_num){
			case DIO_PORTA_ID: SET_BIT(PORTA, pin_num); break;
			case DIO_PORTB_ID: SET_BIT(PORTB, pin_num); break;
			case DIO_PORTC_ID: SET_BIT(PORTC, pin_num); break;
			case DIO_PORTD_ID: SET_BIT(PORTD, pin_num); break;
		}
	}
	  else if (value == DIO_PIN_LOW){
		    switch(port_num) {
			case DIO_PORTA_ID: CLR_BIT(PORTA, pin_num); break;
			case DIO_PORTB_ID: CLR_BIT(PORTB, pin_num); break;
			case DIO_PORTC_ID: CLR_BIT(PORTC, pin_num); break;
			case DIO_PORTD_ID: CLR_BIT(PORTD, pin_num); break;
		    }
	 }
}

u8 DIO_GetPinValue(u8 port_num, u8 pin_num) {
	u8 pin_value = 0; 
	
	switch(port_num) {
		case DIO_PORTA_ID: pin_value = GET_BIT(PINA, pin_num); break;
		case DIO_PORTB_ID: pin_value = GET_BIT(PINB, pin_num); break;
		case DIO_PORTC_ID: pin_value = GET_BIT(PINC, pin_num); break;
		case DIO_PORTD_ID: pin_value = GET_BIT(PIND, pin_num); break;
	}
	
	return pin_value;
}

