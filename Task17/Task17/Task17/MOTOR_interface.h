/*
 * MOTOR_interface.h
 *
 *  Author: Mohamed Mesbah
 *  Layer : HAL
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "STD_TYPES.h"
#include "DIO_interface.h"


/* Motor Port Configuration */
#define MOTOR_PORT      DIO_PORTC_ID

/* Right Motor Pins */
#define MOTOR_RIGHT_IN1 DIO_PIN0
#define MOTOR_RIGHT_IN2 DIO_PIN1

/* Left Motor Pins */
#define MOTOR_LEFT_IN3  DIO_PIN2
#define MOTOR_LEFT_IN4  DIO_PIN3

/* Function Prototypes */
void MOTOR_Init(void);
void MOTOR_MoveForward(void);
void MOTOR_MoveBackward(void);
void MOTOR_TurnRight(void);
void MOTOR_TurnLeft(void);
void MOTOR_Stop(void);

#endif