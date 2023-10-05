/*
 * keypad.h
 *
 *  Created on: Sep 28, 2023
 *      Author: mecam
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../mcal/std_types.h"
#include "../../mcal/gpio/gpio.h"
#include <avr/io.h>
#include <util/delay.h>



/*define keypad types*/
#define SIMPLE_CALCULATOR 1
#define ETAMINI32_KEYPAD 2

/*Choose keypad type among the 2 above*/
#define KEYPAD_TYPE ETAMINI32_KEYPAD


/*Keypad ports*/
#define KEYPAD_ROWS_PORT PORTB_ID
#define KEYPAD_COLS_PORT PORTD_ID

/*first pin in dimension for keypad pins*/
#define KEYPAD_ROWS_OFFSET 4
#define KEYPAD_COLS_OFFSET 2

/*mask for each dimension*/
#define KEYPAD_ROWS_MASK 0xF0
#define KEYPAD_COLS_MASK 0x3C

#define KEYPAD_ROWS_COUNT 4
#define KEYPAD_COLS_COUNT 4

/*keypad connection logic states*/
#define KEYPAD_BUTTON_PRESSED_LOGIC LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED_LOGIC LOGIC_HIGH


/*Validate correct number of rows and columns*/
#if KEYPAD_ROWS_COUNT != 4
#error("Invalid Keypad number of rows");
#elif KEYPAD_COLS_COUNT > 4
#error("Invalid Keypad number of columns");
#elif KEYPAD_COLS_COUNT < 3
#error("Invalid Keypad number of columns");
#endif

/*extern keypad map selected based on map type*/
extern uint8 keypad_keys_map[16];

void keypad_init(void);
sint8 keypad_get_pressed_key(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
