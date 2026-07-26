/*
 * Task17.c
 *
 * Author : Mohamed Mesbah
 * Layer  : APP
 */ 

#include "STD_TYPES.h"
#include "MOTOR_interface.h"
#include "SWITCH_interface.h"

int main(void) {
	/* Hardware Initialization */
	MOTOR_Init();
	SWITCH_Init();

	/* Infinite Super Loop */
	while(1) {
		/* Priority for Stop switch */
		if(SWITCH_GetState(SWITCH_STOP_PIN) == SWITCH_PRESSED) {
			MOTOR_Stop();
		}
		/* Check Forward switch */
		else if(SWITCH_GetState(SWITCH_FWD_PIN) == SWITCH_PRESSED) {
			MOTOR_MoveForward();
		}
		/* Check Backward switch */
		else if(SWITCH_GetState(SWITCH_BWD_PIN) == SWITCH_PRESSED) {
			MOTOR_MoveBackward();
		}
		/* Check Right switch */
		else if(SWITCH_GetState(SWITCH_RIGHT_PIN) == SWITCH_PRESSED) {
			MOTOR_TurnRight();
		}
		/* Check Left switch */
		else if(SWITCH_GetState(SWITCH_LEFT_PIN) == SWITCH_PRESSED) {
			MOTOR_TurnLeft();
		}
	}
	return 0;
}