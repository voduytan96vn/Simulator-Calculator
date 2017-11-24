/*
 * calc.h
 *
 *  Created on: 25 thg 4, 2017
 *      Author: voduy
 */

#ifndef CALC_H_
#define CALC_H_

#include "KEYPAD.h"
#include "LCD.h"
#include <math.h>

#define PLUS 4
#define MINUS 8
#define TIMES 12
#define DIVIDE 13
#define CLEAR 15

void  get_number1(void);
 int  get_number2(void);
 int x_settings(int x);
 int Get_sign(void);
void _delay_ms(unsigned long time);
void Calc(void);


#endif /* CALC_H_ */
