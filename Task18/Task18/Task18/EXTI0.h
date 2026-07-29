/*
 * EXTI0.h
 *
 *  Author: Mohamed Mesbah
 */ 


#ifndef EXTI0_H_
#define EXTI0_H_

#include "STD_TYPES.h"

void EXTI0_Init(void);
void EXTI0_SetCallBack(void (*Copy_pVoidCallBack)(void));

#endif