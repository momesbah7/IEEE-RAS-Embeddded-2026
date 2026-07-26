/*
 * MOTOR_program.c
 *
 *  Author: Mohamed Mesbah
 *  Layer : HAL
 */ 


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "MOTOR_interface.h"

void MOTOR_Init(void) {
	/* Configure Motor pins as Output */
	DIO_SetPinDirection(MOTOR_PORT, MOTOR_RIGHT_IN1, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(MOTOR_PORT, MOTOR_RIGHT_IN2, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(MOTOR_PORT, MOTOR_LEFT_IN3, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(MOTOR_PORT, MOTOR_LEFT_IN4, DIO_PIN_OUTPUT);
}

void MOTOR_MoveForward(void) {
	/* Both motors move forward */
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN1, DIO_PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN2, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN3, DIO_PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN4, DIO_PIN_LOW);
}

void MOTOR_MoveBackward(void) {
	/* Both motors move backward */
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN1, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN2, DIO_PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN3, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN4, DIO_PIN_HIGH);
}

void MOTOR_TurnRight(void) {
	/* Left motor moves forward, right motor stops */
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN1, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN2, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN3, DIO_PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN4, DIO_PIN_LOW);
}

void MOTOR_TurnLeft(void) {
	/* Right motor moves forward, left motor stops */
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN1, DIO_PIN_HIGH);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN2, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN3, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN4, DIO_PIN_LOW);
}

void MOTOR_Stop(void) {
	/* Stop all motors */
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN1, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_RIGHT_IN2, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN3, DIO_PIN_LOW);
	DIO_SetPinValue(MOTOR_PORT, MOTOR_LEFT_IN4, DIO_PIN_LOW);
}