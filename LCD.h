/*
 * LCD.h
 *
 *  Created on: 25 thg 4, 2017
 *      Author: voduy
 */

#ifndef LCD_H_
#define LCD_H_

#include <stdio.h>
#include "inc/tm4c123gh6pm.h"
#include "PIN_PORTS_DEFINATIONS.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef unsigned char uint8;

void LCD_init(void);
void LCD_Send_Command(uint8 command);
void LCD_Goto(uint8 x, uint8 y);
void LCD_Send_Character(uint8 character);
void LCD_Send_String(char *str);
void Delay_ms(unsigned long time);
void LCD_Clear(void);
void LCD_Send_Integer(unsigned long int result);
void LCD_Send_Float(float f);
//void Delay_5_ms(void);

#endif /* LCD_H_ */
