/*
 * EXTI1.h
 *
 *  Author: Mohamed Mesbah
 */ 


#ifndef EXTI1_H_
#define EXTI1_H_

#include "STD_TYPES.h"

void EXTI1_Init(void);
void EXTI1_SetCallBack(void (*Copy_pVoidCallBack)(void));

#endif