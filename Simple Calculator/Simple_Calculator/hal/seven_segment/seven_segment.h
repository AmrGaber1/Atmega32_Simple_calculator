/*
 * seven_segment.h
 *
 *  Created on: Sep 28, 2023
 *      Author: mecam
 */

#ifndef HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_
#define HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_

#include "../../mcal/gpio/gpio.h"
#include <util/delay.h>

/*7 segment modes (direct or using BCD)*/
#define SEVEN_SEGMENT_DIRECT_MODE 1
#define SEVEN_SEGMENT_BCD_MODE 2
#define SEVEN_SEGMENT_MODE SEVEN_SEGMENT_DIRECT_MODE

#define SEVEN_SEGMENT_COMMON_ANODE   1
#define SEVEN_SEGMENT_COMMON_CATHODE 2
#define SEVEN_SEGMENT_COMMON_PIN_MODE SEVEN_SEGMENT_COMMON_CATHODE

void seven_segment_init(uint8 seven_segment_port, uint8 seven_segment_offset,
		uint8 seven_segment_enable_port, uint8 seven_Segment_enable_pin);


#endif /* HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_H_ */
