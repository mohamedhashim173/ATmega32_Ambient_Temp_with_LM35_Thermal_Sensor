/*
 * ADC_interface.h
 *
 *  Created on: Oct 25, 2022
 *      Author: MSAEED99
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



// Initialize ADC
void ADC_voidADCInit(void);

// Get the channel read (Be careful, the channel value is from 0 to 7)
u8 ADC_u8GetChannelRead(u8 copy_u8Channel);



#endif /* ADC_INTERFACE_H_ */

