/*
 * PIN_PORTS_Definations.h
 *
 *  Created on: 25 thg 4, 2017
 *      Author: voduytan
 */

#ifndef PIN_PORTS_DEFINATIONS_H_
#define PIN_PORTS_DEFINATIONS_H_

/* PINS OF PORT A*/

#define PA2  (*((volatile unsigned long *)0x40004010))
#define PA3  (*((volatile unsigned long *)0x40004020))
#define PA4  (*((volatile unsigned long *)0x40004040))
#define PA5  (*((volatile unsigned long *)0x40004080))
#define PA6  (*((volatile unsigned long *)0x40004100))
#define PA7  (*((volatile unsigned long *)0x40004200))


/* PINS OF PORT B*/

#define PB0  (*((volatile unsigned long *)0x40005004))
#define PB1  (*((volatile unsigned long *)0x40005008))
#define PB2  (*((volatile unsigned long *)0x40005010))
#define PB3  (*((volatile unsigned long *)0x40005020))
#define PB4  (*((volatile unsigned long *)0x40005040))
#define PB5  (*((volatile unsigned long *)0x40005080))
#define PB6  (*((volatile unsigned long *)0x40005100))
#define PB7  (*((volatile unsigned long *)0x40005200))


/* PINS OF PORT C*/

#define PC4  (*((volatile unsigned long *)0x40006040))
#define PC5  (*((volatile unsigned long *)0x40006080))
#define PC6  (*((volatile unsigned long *)0x40006100))
#define PC7  (*((volatile unsigned long *)0x40006200))


/* PINS OF PORT D*/

#define PD0  (*((volatile unsigned long *)0x40007004))
#define PD1  (*((volatile unsigned long *)0x40007008))
#define PD2  (*((volatile unsigned long *)0x40007010))
#define PD3  (*((volatile unsigned long *)0x40007020))
#define PD6  (*((volatile unsigned long *)0x40007100))
#define PD7  (*((volatile unsigned long *)0x40007200))


/* PINS OF PORT E*/

#define PE0  (*((volatile unsigned long *)0x40024004))
#define PE1  (*((volatile unsigned long *)0x40024008))
#define PE2  (*((volatile unsigned long *)0x40024010))
#define PE3  (*((volatile unsigned long *)0x40024020))
#define PE4  (*((volatile unsigned long *)0x40024040))
#define PE5  (*((volatile unsigned long *)0x40024080))


/* PINS OF PORT F*/

#define PF0  (*((volatile unsigned long *)0x40025004))
#define PF1  (*((volatile unsigned long *)0x40025008))
#define PF2  (*((volatile unsigned long *)0x40025010))
#define PF3  (*((volatile unsigned long *)0x40025020))
#define PF4  (*((volatile unsigned long *)0x40025040))
#define PF5  (*((volatile unsigned long *)0x40025080))
#define PF6  (*((volatile unsigned long *)0x40025100))
#define PF7  (*((volatile unsigned long *)0x40025200))

#endif /* PIN_PORTS_DEFINATIONS_H_ */
