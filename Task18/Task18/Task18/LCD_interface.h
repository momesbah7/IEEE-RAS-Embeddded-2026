/*
 * LCD_interface.h
 *
 *  Author: Mohamed Mesbah
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "STD_TYPES.h"

void LCD_Init(void);
void LCD_SendCommand(u8 Copy_u8Command);
void LCD_SendData(u8 Copy_u8Data);

#endif