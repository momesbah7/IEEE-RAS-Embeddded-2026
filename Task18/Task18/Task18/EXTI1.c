/*
 * EXTI1.c
 *
 *  Author: Mohamed Mesbah
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI1_REGISTER.h"
#include "EXTI1.h"

/* Global Pointer to Function for Callback */
static void (*EXTI1_CallBack)(void) = NULL;

void EXTI1_Init(void) {
	/* Set Sense Control to Falling Edge for INT1 (ISC11=1, ISC10=0) */
	SET_BIT(MCUCR, 3);
	CLR_BIT(MCUCR, 2);
	
	/* Enable Peripheral Interrupt for EXTI1 (PIE) */
	SET_BIT(GICR, 7);
}

void EXTI1_SetCallBack(void (*Copy_pVoidCallBack)(void)) {
	if (Copy_pVoidCallBack != NULL) {
		EXTI1_CallBack = Copy_pVoidCallBack;
	}
}

/* ISR for EXTI1 */
void __vector_2(void) __attribute__((signal));
void __vector_2(void) {
	if (EXTI1_CallBack != NULL) {
		EXTI1_CallBack();
	}
}