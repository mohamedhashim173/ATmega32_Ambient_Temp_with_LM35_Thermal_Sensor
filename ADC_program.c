/*
 * ADC_program.c
 *
 *  Created on: Oct 25, 2022
 *      Author: MSAEED99
 */


// Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// MCAL
#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"


// Initialize ADC
void ADC_voidADCInit(void)
{
	// Choose AVCC as Reference Voltage (Vref)
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

	// Enable left adjust (8-bit resolution)
	SET_BIT(ADMUX, ADMUX_ADLAR);

	// Set the pre-scaler value (conversion frequency) (Divide by 128)
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);

	// Enable ADC peripheral
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}


// Get the channel read (Be careful, the channel value is from 0 to 7)
u8 ADC_u8GetChannelRead(u8 copy_u8Channel)
{
	// Bit Masking
	// 1. Clear the required bits
	ADMUX &= 0b11100000;
	// 2. Set the needed value to MUX bits
	ADMUX |= copy_u8Channel;

	// Start conversion
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	// Polling (Busy waiting) till the conversion is done
	while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);

	// Clear flag
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	// Return ADC data register ADCH (using left adjustment 8-bit resolution)
	return ADCH;
}












