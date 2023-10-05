/*
 * seven_segment.c
 *
 *  Created on: Sep 28, 2023
 *      Author: mecam
 */


#include "seven_segment.h"


#if SEVEN_SEGMENT_MODE == SEVEN_SEGMENT_DIRECT_MODE
void seven_segment_init(uint8 seven_segment_port,uint8 seven_segment_offset,
	uint8 seven_segment_enable_port, uint8 seven_Segment_enable_pin){
	GPIO_setupPortDirectionMasked(seven_segment_port, 0x7F<<seven_segment_offset, PORT_OUTPUT);
	GPIO_setupPinDirection(seven_segment_enable_port, seven_Segment_enable_pin, PIN_OUTPUT);
}



#elif SEVEN_SEGMENT_MODE == SEVEN_SEGMENT_BCD_MODE
void seven_segment_init(uint8 seven_segment_port, uint8 seven_segment_offset,
		uint8 seven_segment_enable_port, uint8 seven_Segment_enable_pin){
	GPIO_setupPortDirectionMasked(seven_segment_port, 0x0F<<seven_segment_offset, PORT_OUTPUT);
	GPIO_setupPinDirection(seven_segment_enable_port, seven_Segment_enable_pin, PIN_OUTPUT);
}

#endif
