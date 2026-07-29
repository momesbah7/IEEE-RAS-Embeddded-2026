/*
 * Task18.c
 *
 * Author : Mohamed Mesbah
 */ 
#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI0.h"
#include "EXTI1.h"
#include "LCD_interface.h"
#include "SEVSEG_interface.h"
#include <util/delay.h>

/* Global Interrupt Enable Register */
#define SREG *((volatile u8*)0x5F)

volatile u8 counter = 1;
volatile u8 led_state = 0;

void Toggle_LED(void) {
	led_state = !led_state;
	if(led_state)
	DIO_SetPinValue(DIO_PORTC_ID, DIO_PIN0, DIO_PIN_HIGH);
	else
	DIO_SetPinValue(DIO_PORTC_ID, DIO_PIN0, DIO_PIN_LOW);
}

void Reset_Counter(void) {
	counter = 0;
}

int main(void) {
	/* 1. HAL & Pins Initialization */
	DIO_SetPinDirection(DIO_PORTC_ID, DIO_PIN0, DIO_PIN_OUTPUT); /* LED Pin */
	SEVSEG_Init();
	LCD_Init();
	
	/* Interrupt Pins Setup (Input + Internal Pull-Up) */
	DIO_SetPinDirection(DIO_PORTD_ID, DIO_PIN2, DIO_PIN_INPUT);
	DIO_SetPinValue(DIO_PORTD_ID, DIO_PIN2, DIO_PIN_HIGH);
	
	DIO_SetPinDirection(DIO_PORTD_ID, DIO_PIN3, DIO_PIN_INPUT);
	DIO_SetPinValue(DIO_PORTD_ID, DIO_PIN3, DIO_PIN_HIGH);
	
	/* 2. EXTI Initialization */
	EXTI0_SetCallBack(Toggle_LED);
	EXTI1_SetCallBack(Reset_Counter);
	EXTI0_Init();
	EXTI1_Init();
	
	/* Enable Global Interrupt */
	SET_BIT(SREG, 7);
	
	/* 3. Super Loop */
	while(1) {
		if(counter == 0) counter = 1;
		SEVSEG_Display(counter);
		
		LCD_SendCommand(0x01); /* Clear display */
		LCD_SendData('C');
		LCD_SendData('o');
		LCD_SendData('u');
		LCD_SendData('n');
		LCD_SendData('t');
		LCD_SendData(':');
		LCD_SendData(' ');
		LCD_SendData(counter + '0');
		
		_delay_ms(1000);
		
		counter++;
		if(counter > 9) {
			counter = 1;
		}
	}
	return 0;
}