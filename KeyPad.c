/*
 * KeyPad.c
 *
 *  Created on: 25 thg 4, 2017
 *      Author: voduy
 */

#include "KEYPAD.h"
#include "stdint.h"

void NDelay_ms(unsigned long time)
{
 time = ((time/375)*1000000);
 while(time)
 {
  time--;
 }
}

unsigned char Keypad_Read(){

 unsigned char col_count =0,row_count=0;
 while(1)
 {
  for(col_count = 0;col_count < N_col;col_count++)
  {
      GPIO_PORTE_DATA_R = 1<<col_count;
      for(row_count = 0;row_count < N_row;row_count++)
      {
          if((GPIO_PORTA_DATA_R &(1<<(row_count+2))) != 0)
          {
              NDelay_ms(400);
              return ((row_count*4)+col_count+1);
          }
      }
  }
 }
}
char key_pressed(unsigned char value)
{
 signed char key;
 switch(value)
 {
  case 1:key = 1;
  break;
  case 2:key = 2;
  break;
  case 3:key = 3;
  break;
  case 4:key = -5;// "+"
  break;
  case 5:key = 4;
  break;
  case 6:key = 5;
  break;
  case 7:key = 6;
  break;
  case 8:key = -3;// "-"
  break;
  case 9:key = 7;
  break;
  case 10:key = 8;
  break;
  case 11:key = 9;
  break;
  case 12:key = -6;// "*"
  break;
  case 13:key = -1;// "/"
  break;
  case 14:key = 0;
  break;
  case 15:key = 19;// "C"
  break;
  case 16:key = 13;// "="
  break;
 }
 return key;
}

void Keypad_Init(){

  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000010;     // 1) activate clock for Port E
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTE_DIR_R = 0xFF;          // 5) PE as output
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTE_PUR_R = 0x00;          // enable pull-up on PF0 and PF4
  GPIO_PORTE_DEN_R = 0xFF;          // 7) enable digital I/O on PF4-0


  SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTA_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTA_DIR_R = 0x00;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTA_AFSEL_R = 0x00;        // 6) disable alt funct on PA7-0
  GPIO_PORTA_PDR_R = 0xFF;          // enable pull-up on PA4,5,6,7
  GPIO_PORTA_DEN_R = 0xFF;          // 7) enable digital I/O on PFA-0

}

