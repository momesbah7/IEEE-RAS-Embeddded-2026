/*
 * ADC_interface.h
 *
 *  Author: Mohamed Mesbah
 *  Layer : MCAL
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"

void ADC_Init(void);
u16 ADC_ReadChannel(u8 Copy_u8Channel);

#endif