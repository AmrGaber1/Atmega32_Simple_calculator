/*
 * keypad.c
 *
 *  Created on: Sep 28, 2023
 *      Author: mecam
 */

#include "keypad.h"



#if KEYPAD_TYPE == SIMPLE_CALCULATOR
uint8 keypad_keys_map[16] = {'7', '8', '9', '/', '4', '5', '6', '*',
		'1', '2', '3', '-', 'C', '0', '=', '+'};
#elif KEYPAD_TYPE == ETAMINI32_KEYPAD
uint8 keypad_keys_map[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
#endif

void keypad_init(void){
	uint8 counter;
	/*Set keypad pins as output*/
	for(counter = KEYPAD_ROWS_OFFSET; counter < KEYPAD_ROWS_COUNT + KEYPAD_ROWS_OFFSET; counter++){
		GPIO_setupPinDirection(KEYPAD_ROWS_PORT, counter, PIN_OUTPUT);
	}

	/*set keypad columns as input*/
	for(counter = KEYPAD_COLS_OFFSET; counter < KEYPAD_COLS_COUNT + KEYPAD_COLS_OFFSET; counter++){
		GPIO_setupPinDirection(KEYPAD_COLS_PORT, counter, PIN_INPUT);
	}
}

sint8 keypad_get_pressed_key(void){
	uint8 rows_counter;
	uint8 cols_counter;
#if KEYPAD_BUTTON_PRESSED_LOGIC == LOGIC_HIGH
	for(rows_counter = 0; rows_counter < KEYPAD_ROWS_COUNT; rows_counter++){
		GPIO_writePortMasked(KEYPAD_ROWS_PORT, KEYPAD_ROWS_MASK, (1 << (rows_counter + KEYPAD_ROWS_OFFSET)));
		_delay_us(50);
		for(cols_counter = 0; cols_counter < KEYPAD_COLS_COUNT; cols_counter++){
			if(GPIO_readPin(KEYPAD_COLS_PORT, cols_counter + KEYPAD_COLS_OFFSET) == KEYPAD_BUTTON_PRESSED_LOGIC){
				return (rows_counter*KEYPAD_COLS_COUNT + (cols_counter));
			}
		}
	}

#else
	for(rows_counter = 0; rows_counter < KEYPAD_ROWS_COUNT; rows_counter++){
		GPIO_writePortMasked(KEYPAD_ROWS_PORT, KEYPAD_ROWS_MASK, ~(1 << (rows_counter + KEYPAD_ROWS_OFFSET)));
		_delay_us(50);
		for(cols_counter = 0; cols_counter < KEYPAD_COLS_COUNT; cols_counter++){
			if(GPIO_readPin(KEYPAD_COLS_PORT, cols_counter + KEYPAD_COLS_OFFSET) == KEYPAD_BUTTON_PRESSED_LOGIC){
				return (rows_counter*KEYPAD_COLS_COUNT + (cols_counter));
			}
		}
	}
#endif
	return -1;

}


