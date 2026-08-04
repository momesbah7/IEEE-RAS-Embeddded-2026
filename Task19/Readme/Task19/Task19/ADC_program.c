/*
 * ADC_program.c
 *
 *  Author: Mohamed Mesbah
 *  Layer : MCAL
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"

/* ADC Registers Absolute Addresses */
#define ADMUX   *((volatile u8*)0x27)
#define ADCSRA  *((volatile u8*)0x26)
#define ADCL    *((volatile u8*)0x24)
#define ADCH    *((volatile u8*)0x25)

void ADC_Init(void) {
	/* Select VREF = AVCC */
	SET_BIT(ADMUX, 6);
	CLR_BIT(ADMUX, 7);
	
	/* Right Adjust Result */
	CLR_BIT(ADMUX, 5);
	
	/* Enable ADC and set Prescaler to 64 (for 8MHz CPU) */
	SET_BIT(ADCSRA, 7); /* ADEN */
	CLR_BIT(ADCSRA, 0); /* ADPS0 */
	SET_BIT(ADCSRA, 1); /* ADPS1 */
	SET_BIT(ADCSRA, 2); /* ADPS2 */
}

u16 ADC_ReadChannel(u8 Copy_u8Channel) {
	/* Clear MUX bits in ADMUX */
	ADMUX &= 0xE0;
	/* Set the required channel (0 to 7) */
	ADMUX |= (Copy_u8Channel & 0x07);
	
	/* Start Conversion */
	SET_BIT(ADCSRA, 6);
	
	/* Wait for conversion to complete (Polling on ADIF) */
	while(((ADCSRA >> 4) & 1) == 0);
	
	/* Clear ADIF Flag */
	SET_BIT(ADCSRA, 4);
	
	/* Return Data (Read ADCL first, then ADCH) */
	u16 Local_u16Result = ADCL;
	Local_u16Result |= (ADCH << 8);
	
	return Local_u16Result;
}