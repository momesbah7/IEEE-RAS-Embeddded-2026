/*
 * SWITCH_interface.h
 *
 *  Author: Mohamed Mesbah
 *  Layer : HAL
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#include "STD_TYPES.h"
#include "DIO_interface.h"

/* Switch Port Configuration */
#define SWITCH_PORT      DIO_PORTD_ID

/* Switch Pins Definitions */
#define SWITCH_FWD_PIN   DIO_PIN2
#define SWITCH_BWD_PIN   DIO_PIN3
#define SWITCH_RIGHT_PIN DIO_PIN4
#define SWITCH_LEFT_PIN  DIO_PIN5
#define SWITCH_STOP_PIN  DIO_PIN6

/* Macro for pressed state assuming Internal Pull-up configuration */
#define SWITCH_PRESSED   0

/* Function Prototypes */
void SWITCH_Init(void);
u8   SWITCH_GetState(u8 copy_pin_num);

#endif