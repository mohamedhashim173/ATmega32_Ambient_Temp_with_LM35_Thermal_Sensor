/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: MSAEED99
 */

// AVR Libraries
#include <util/delay.h>

// Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// MCAL
#include "DIO_interface.h"
#include "ADC_interface.h"

// HAL
#include "LCD_interface.h"


/*
 * LAB 02
 * Implement a system that display the ambient temperature
   on LCD and update it every 1 second using LM35 temperature sensor.
 */

void main(void)
{
	u8 local_u8ChannelRead;
	u16 local_u16Analog_mv;
	u8 local_u8Temperature;

	// Initialize LCD
	LCD_voidInit();

	// Initialize ADC pin as input (PinA0)
	ADC_voidADCInit();
	DIO_voidSetPinDirection(DIO_u8PORTA, DIO_u8PIN0, DIO_u8PIN_INPUT);


	LCD_voidSendString("Ambient Temp:");

	LCD_voidPositionSet(1, 2);
	LCD_voidSendCharacter(0b11011111);		// degree symbol
	LCD_voidSendCharacter('C');

	while(1)
	{
		// Update ADC channel read
		local_u8ChannelRead = ADC_u8GetChannelRead(0);

		// Calculate channel read (temperature read) into milli-volts
		local_u16Analog_mv = ((u32)local_u8ChannelRead * 5000UL) / 256UL;

		/* Convert milli-volts to the corresponding temperature value (from data sheet)
		 * 0   mV -> 0  °C
		 * 10  mV -> 1  °C
		 * 100 mV -> 10 °C
		 */
		local_u8Temperature = local_u16Analog_mv / 10;

		// Display current temperature
		LCD_voidPositionSet(1, 0);
		LCD_voidWriteNum(local_u8Temperature);
		_delay_ms(1000);
	}
}

