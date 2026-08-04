/*
 * Task19.c
 *
 * Author : Mohamed Mesbah
 * Layer  : APP
 */ 

#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include <util/delay.h>

/* Helper function to convert integer to string and display on LCD */
void LCD_DisplayNumber(u16 number) {
	u8 str[6];
	s8 i = 0;
	if (number == 0) {
		LCD_SendData('0');
		return;
	}
	while (number > 0) {
		str[i++] = (number % 10) + '0';
		number /= 10;
	}
	while (i > 0) {
		LCD_SendData(str[--i]);
	}
}

int main(void) {
	/* Initialization */
	DIO_SetPortDirection(DIO_PORTC_ID, 0xFF); /* 8 LEDs connected to PORTC */
	DIO_SetPinDirection(DIO_PORTA_ID, DIO_PIN0, DIO_PIN_INPUT); /* Potentiometer connected to PA0 */
	
	LCD_Init();
	ADC_Init();
	
	u16 adc_value = 0;
	u32 percentage = 0;
	u8 leds_on = 0;
	u8 led_port_value = 0;
	u8 i;
	
	while(1) {
		/* Read ADC value from Channel 0 (PA0) */
		adc_value = ADC_ReadChannel(0);
		
		/* Calculate Percentage (0% to 100%) */
		percentage = ((u32)adc_value * 100) / 1023;
		
		/* Calculate how many LEDs to turn on (0 to 8) */
		leds_on = (percentage * 8) / 100;
		
		/* Prepare the PORTC value to turn ON the LEDs */
		led_port_value = 0;
		for(i = 0; i < leds_on; i++) {
			led_port_value |= (1 << i);
		}
		DIO_SetPortValue(DIO_PORTC_ID, led_port_value);
		
		/* Display Results on LCD */
		LCD_SendCommand(0x01); /* Clear LCD */
		
		/* Line 1: ADC Value */
		LCD_SendData('A'); LCD_SendData('D'); LCD_SendData('C'); LCD_SendData(':'); LCD_SendData(' ');
		LCD_DisplayNumber(adc_value);
		
		/* Line 2: Percentage */
		LCD_SendCommand(0xC0); /* Move cursor to second line */
		LCD_SendData('P'); LCD_SendData('e'); LCD_SendData('r'); LCD_SendData('c'); LCD_SendData(':'); LCD_SendData(' ');
		LCD_DisplayNumber((u16)percentage);
		LCD_SendData('%');
		
		_delay_ms(200); /* Small delay to stabilize display */
	}
	return 0;
}
