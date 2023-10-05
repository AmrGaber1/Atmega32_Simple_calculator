/*
 * helper_functions.c
 *
 *  Created on: Oct 5, 2023
 *      Author: mecam
 */

#include "helper_functions.h"

uint8 helper_countDigits(uint32 num){
	uint8 digitsCount = 1;
	while(num > 9){
		digitsCount++;
		num /= 10;
	}
	return digitsCount;
}

void helper_fillWithSpaces(char *str, uint32 offset, uint32 string_length){
	while(offset < string_length){
		str[offset] = ' ';
		offset++;
	}
}

void helper_fillWithEndline(char *str, uint32 offset, uint32 string_length){
	while(offset < string_length){
		str[offset] = '\0';
		offset++;
	}
}
