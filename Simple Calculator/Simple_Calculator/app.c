/*
 * app.c
 *
 *  Created on: Oct 5, 2023
 *      Author: mecam
 */
#include <stdlib.h>
#include "app.h"

uint8 keypad_charMap[16] = {'7', '8', '9', '/',
							'4', '5', '6','*',
							'1', '2', '3', '-',
							'O', '0', '=', '+'};

sint8 current_key;
sint8 previous_key = -1;
uint8 length;
char strBuffer[16];
uint8 strBuffer_next_digit_flag = 0;
uint32 result = 0;
uint32 temp_num = 0;
uint8 new_calc = 1;
uint8 previous_operator;
uint8 result_printed_flag = 0;
uint8 error_flag = 0;
int main(){
	keypad_init();
	lcd_init(LCD_COMMAND_DISPLAY_ON_CURSOR_OFF);
	helper_fillWithEndline(strBuffer, 0, 16);
	while(1){
		current_key = keypad_get_pressed_key();
		if((current_key != -1)&&(current_key != previous_key)){
			if(result_printed_flag == 1){
				current_key = 12;
			}
			if(keypad_charMap[current_key] == 'O')
			{
				helper_fillWithSpaces(strBuffer, 0, 16);
				lcd_setPosition(0,0);
				lcd_displayString(strBuffer);
				lcd_setPosition(1,0);
				lcd_displayString(strBuffer);
				lcd_setPosition(0,0);
				new_calc = 1;
				temp_num = 0;
				result_printed_flag = 0;
				result = 0;
				strBuffer_next_digit_flag = 0;
			}
			else if(keypad_charMap[current_key] == '=')
			{
				if(!new_calc){
					if(!((keypad_charMap[previous_key] == '+')||(keypad_charMap[previous_key] == '-')
							||(keypad_charMap[previous_key] == '*')||(keypad_charMap[previous_key] == '/'))){
						switch(previous_operator){
							case '+':
								result += temp_num;
								break;
							case '-':
								result -= temp_num;
								break;
							case '*':
								result *= temp_num;
								break;
							case '/':
								result /= temp_num;
								break;
						}
					}
				}
				lcd_setPosition(1,0);
				lcd_displayString("Result: ");
				itoa(result, strBuffer, 10);
				lcd_displayString(strBuffer);
				new_calc = 1;
				result = 0;
				temp_num = 0;
				result_printed_flag = 1;
				strBuffer_next_digit_flag = 0;
			}
			else if((keypad_charMap[current_key] >= '0')&&(keypad_charMap[current_key] <= '9')){
				temp_num *= 10;
				temp_num += (keypad_charMap[current_key] - '0');
				strBuffer_next_digit_flag++;
				lcd_displayCharacter(keypad_charMap[current_key]);

			}
			else
			{
				if((new_calc == 1) && (strBuffer_next_digit_flag != 0)){
					new_calc = 0;
					result = temp_num;
					temp_num = 0;
					previous_operator = keypad_charMap[current_key];
				}else if((new_calc == 1) && (strBuffer_next_digit_flag == 0)){
					helper_fillWithSpaces(strBuffer, 0, 16);
					lcd_setPosition(0,0);
					lcd_displayString(strBuffer);
					lcd_setPosition(1,0);
					lcd_displayString(strBuffer);
					lcd_setPosition(0,0);
					new_calc = 1;
					temp_num = 0;
					result_printed_flag = 0;
					result = 0;
					error_flag = 1;
				}else{
					switch(previous_operator){
					case '+':
						result += temp_num;
						break;
					case '-':
						result -= temp_num;
						break;
					case '*':
						result *= temp_num;
						break;
					case '/':
						result /= temp_num;
						break;
					}
					temp_num = 0;
					previous_operator = keypad_charMap[current_key];
				}
				if(error_flag){
					error_flag = 0;
				}
				else{
					strBuffer_next_digit_flag++;
					lcd_displayCharacter(keypad_charMap[current_key]);
				}

			}
		}
		previous_key = current_key;
	}
}

