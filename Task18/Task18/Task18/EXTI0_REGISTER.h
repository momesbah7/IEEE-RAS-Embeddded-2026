/*
 * EXTI0_REGISTER.h
 *
 *  Author: Mohamed Mesbah
 */ 


#ifndef EXTI0_REGISTER_H_
#define EXTI0_REGISTER_H_

#include "STD_TYPES.h"

/* Registers for External Interrupts */
#define MCUCR  *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR   *((volatile u8*)0x5B)
#define GIFR   *((volatile u8*)0x5A)

#endif