/*
 * EXTI0.c
 *
 * Created: 7/29/2026 10:23:40 PM
 *  Author: HP
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI0_REGISTER.h"
#include "EXTI0.h"

/* Global Pointer to Function for Callback */
static void (*EXTI0_CallBack)(void) = NULL;

void EXTI0_Init(void) {
	/* Set Sense Control to Falling Edge for INT0 (ISC01=1, ISC00=0) */
	SET_BIT(MCUCR, 1);
	CLR_BIT(MCUCR, 0);
	
	/* Enable Peripheral Interrupt for EXTI0 (PIE) */
	SET_BIT(GICR, 6);
}

void EXTI0_SetCallBack(void (*Copy_pVoidCallBack)(void)) {
	if (Copy_pVoidCallBack != NULL) {
		EXTI0_CallBack = Copy_pVoidCallBack;
	}
}

/* ISR for EXTI0 */
void __vector_1(void) __attribute__((signal));
void __vector_1(void) {
	if (EXTI0_CallBack != NULL) {
		EXTI0_CallBack();
	}
}