/*
 * helper_functions.h
 *
 *  Created on: Oct 5, 2023
 *      Author: mecam
 */

#ifndef HELPER_FUNCTIONS_H_
#define HELPER_FUNCTIONS_H_

#include "mcal/std_types.h"
#include "mcal/common_macros.h"
uint8 helper_countDigits(uint32 num);
void helper_fillWithSpaces(char *str, uint32 offset, uint32 string_length);
void helper_fillWithEndline(char *str, uint32 offset, uint32 string_length);
#endif /* HELPER_FUNCTIONS_H_ */
