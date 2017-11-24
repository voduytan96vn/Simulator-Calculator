/*
 * KeyPad.h
 *
 *  Created on: 25 thg 4, 2017
 *      Author: voduy
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "inc/tm4c123gh6pm.h"

#define N_col 4
#define N_row 4

unsigned char Keypad_Read(void);
void Keypad_Init(void);
char key_pressed(unsigned char value);

#endif /* KEYPAD_H_ */
