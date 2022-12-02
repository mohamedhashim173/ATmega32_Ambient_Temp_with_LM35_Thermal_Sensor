/*
 * ADC_register.h
 *
 *  Created on: Oct 25, 2022
 *      Author: MSAEED99
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_



// ADC Multiplexer Selection Register – ADMUX
#define  ADMUX			*((volatile u8*) 0x27)
// ADMUX register bits
#define  ADMUX_MUX0		0
#define  ADMUX_MUX1		1
#define  ADMUX_MUX2		2
#define  ADMUX_MUX3		3
#define  ADMUX_MUX4		4
#define  ADMUX_ADLAR	5
#define  ADMUX_REFS0	6
#define  ADMUX_REFS1	7


// ADC Control and Status Register A – ADCSRA
#define  ADCSRA			*((volatile u8*) 0x26)
// ADCSRA register bits
#define  ADCSRA_ADPS0	0
#define  ADCSRA_ADPS1	1
#define  ADCSRA_ADPS2	2
#define  ADCSRA_ADIE	3
#define  ADCSRA_ADIF	4
#define  ADCSRA_ADATE	5
#define  ADCSRA_ADSC	6
#define  ADCSRA_ADEN	7


// The ADC Data Register – ADCL and ADCH
// ADC Data Register High Byte
#define  ADCH			*((volatile u8*) 0x25)
// ADC Data Register Low Byte
#define  ADCL			*((volatile u8*) 0x24)


// Special FunctionIO Register – SFIOR
#define  SFIOR			*((volatile u8*) 0x50)
// SFIOR register bits
#define  SFIOR_ADTS0	5
#define  SFIOR_ADTS1	6
#define  SFIOR_ADTS2	7



#endif /* ADC_REGISTER_H_ */

