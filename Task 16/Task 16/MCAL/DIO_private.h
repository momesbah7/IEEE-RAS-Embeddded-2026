/*
 * Private.h
 *
 *  Author: Mohamed Mesbah
 *  Layer : MCAL
 *  SWC   : DIO
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "STD_TYPES.h"

/* PORT A Registers */
#define PORTA *((volatile u8*)0x3B)
#define DDRA  *((volatile u8*)0x3A)
#define PINA  *((volatile u8*)0x39)

/* PORT B Registers */
#define PORTB *((volatile u8*)0x38)
#define DDRB  *((volatile u8*)0x37)
#define PINB  *((volatile u8*)0x36)

/* PORT C Registers */
#define PORTC *((volatile u8*)0x35)
#define DDRC  *((volatile u8*)0x34)
#define PINC  *((volatile u8*)0x33)

/* PORT D Registers */
#define PORTD *((volatile u8*)0x32)
#define DDRD  *((volatile u8*)0x31)
#define PIND  *((volatile u8*)0x30)


#endif 