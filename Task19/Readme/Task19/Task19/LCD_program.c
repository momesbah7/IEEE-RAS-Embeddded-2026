/*
 * LCD_program.c
 *
 *  Author: Mohamed Mesbah
 */ 

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include <util/delay.h>

void LCD_SendCommand(u8 Copy_u8Command) {
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_LOW);
	DIO_SetPortValue(LCD_DATA_PORT, Copy_u8Command);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_LOW);
}

void LCD_SendData(u8 Copy_u8Data) {
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_HIGH);
	DIO_SetPortValue(LCD_DATA_PORT, Copy_u8Data);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_LOW);
}

void LCD_Init(void) {
	DIO_SetPortDirection(LCD_DATA_PORT, 0xFF);
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, DIO_PIN_OUTPUT);
	
	_delay_ms(40);
	LCD_SendCommand(0x38);
	LCD_SendCommand(0x0C);
	LCD_SendCommand(0x01);
}