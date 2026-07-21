/*
 * Private.h
 *
 *  Author: Mohamed Mesbah
 *  Layer : MCAL
 *  SWC   : DIO
 */ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"

/* Port Defines */
#define DIO_PORTA_ID 0
#define DIO_PORTB_ID 1
#define DIO_PORTC_ID 2
#define DIO_PORTD_ID 3

/* Pin Defines */

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


/* Pin Direction Defines */
#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1

/* Pin Value Defines */
#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1

/* Function Prototypes */
void    DIO_SetPinDirection  (u8 port_num, u8 pin_num, u8 direction);
void    DIO_SetPinValue      (u8 port_num, u8 pin_num, u8 value);
u8 DIO_GetPinValue      (u8 port_num, u8 pin_num);



#endif 