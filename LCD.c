/*
 * LCD.c
 *
 *  Created on: 25 thg 4, 2017
 *      Author: voduy
 */

#include "LCD.h"

#define LCD_DATA_PORT GPIO_PORTB_DATA_R

#define LCD_CONTROL_PORT GPIO_PORTF_DATA_R

#define LCD_RS_PIN PF1
#define LCD_RW_PIN PF2
#define LCD_E_PIN  PF3


void LCD_init(void)
{
 /* initialization for lcd data and command (ALL PINS OF PORT B)*/
 volatile unsigned long delay;
 SYSCTL_RCGC2_R |=SYSCTL_RCGC2_GPIOB; //ative clock for PORT B
 delay = SYSCTL_RCGC2_R;

 GPIO_PORTB_AMSEL_R = 0x00; //DISABLE ANLOG ON PORT B
 GPIO_PORTB_PCTL_R = 0x00000000; //
 GPIO_PORTB_DIR_R = 0xFF; // MAKE PORTB IS OUTPUT PORT
 GPIO_PORTB_AFSEL_R = 0x00; //DISABLE ALTERNATIVE FUNCTION
 GPIO_PORTB_DEN_R =0xFF;  // ENABLE DIGITAL I/O FOR PORT B

 /*initialization for lcd control ()*/
 /*SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;
 delay = SYSCTL_RCGC2_R;
 GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
 GPIO_PORTF_CR_R = 0x0E;
 GPIO_PORTF_AMSEL_R = 0x00;
 GPIO_PORTF_PCTL_R = 0x00000000;
 GPIO_PORTF_DIR_R = 0x0E;
 GPIO_PORTF_AFSEL_R = 0x00;
 GPIO_PORTF_DEN_R = 0x0E;*/

 LCD_Send_Command(0x38);
 Delay_ms(100);
 LCD_Send_Command(0x0C);
 Delay_ms(100);
 LCD_Send_Command(0x01);
 Delay_ms(100);
 LCD_Send_Command(0x06);
}


void LCD_Send_Command(uint8 command)
{
 LCD_DATA_PORT = command;

 LCD_RS_PIN = 0x00;
 LCD_RW_PIN = 0x00;
 LCD_E_PIN = 0xFF;
 Delay_ms(100);
 LCD_E_PIN = 0x00;
}


void LCD_Goto(uint8 x, uint8 y)
{
 uint8 firstAddress[]={0x80,0xC0};
 LCD_Send_Command(firstAddress[x-1] + y-1);
 Delay_ms(100);
}


void LCD_Send_Character(uint8 character)
{
 LCD_DATA_PORT = character;

 LCD_RS_PIN = 0xFF;
 LCD_RW_PIN = 0x00;
 LCD_E_PIN = 0xFF;
 Delay_ms(100);
 LCD_E_PIN = 0x00;
}


void LCD_Send_String(char *str)
{
 while(*str)
 {
  LCD_Send_Character(*str++);

 }
}
/*
void LCD_Send_Integer(unsigned long number){// This function prints integer on LCD
 unsigned char thousands,hundreds,tens,ones;
 if (number>=1000)
  thousands = ((number/1000)%10);
 if (number>=100)
  hundreds = ((number/100)%10);
 if (number>=10)
  tens = ((number/10)%10);

  ones = ((number/1)%10);

  if (number>=1000)
 LCD_Send_Character(thousands+48);
  if (number>=100)
 LCD_Send_Character(hundreds+48);
   if (number>=10)
 LCD_Send_Character(tens+48);

 LCD_Send_Character(ones+48);
}*/


void LCD_Send_Integer(unsigned long int result)
{
    if(result <= 9) //check if number consists of ONLY ONE digit
        LCD_Send_Character(result+'0');
    else if((result >= 10)&&((result <= 99))) //check if number consists of  TWO digits
    {
        LCD_Send_Character((result/10)+'0');
        LCD_Send_Character((result%10)+'0');
    }
    else if((result >= 100)&&((result <= 999))) //check if number consists of  THREE digits
    {
        LCD_Send_Character((result/100)+'0');
        LCD_Send_Character(((result%100)/10)+'0');
        LCD_Send_Character(((result%100)%10)+'0');
    }
    else if((result >= 1000)&&((result <= 9999))) //check if number consists of  FOUR digits
    {
        LCD_Send_Character((result/1000)+'0');
        LCD_Send_Character(((result%1000)/100)+'0');
        LCD_Send_Character((((result%1000)%100)/10)+'0');
        LCD_Send_Character((((result%1000)%100)%10)+'0');
    }
    else if((result >= 10000)&&((result <= 99999))) //check if number consists of  FOUR digits
    {
        LCD_Send_Character((result/10000)+'0');
        LCD_Send_Character(((result%10000)/1000)+'0');
        LCD_Send_Character((((result%10000)%1000)/100)+'0');
        LCD_Send_Character(((((result%10000)%1000)%100)/10)+'0');
        LCD_Send_Character(((((result%100000)%1000)%100)%10)+'0');
    }
    else if((result >= 100000)&&((result <= 999999))) //check if number consists of  FOUR digits
    {
        LCD_Send_Character((result/100000)+'0');
        LCD_Send_Character(((result%100000)/10000)+'0');
        LCD_Send_Character((((result%100000)%10000)/1000)+'0');
        LCD_Send_Character(((((result%100000)%10000)%1000)/100)+'0');
        LCD_Send_Character((((((result%1000000)%10000)%1000)%100)/10)+'0');
        LCD_Send_Character((((((result%10000000)%10000)%1000)%100)%10)+'0');
    }
/*    else if((result >= 1000000)&&((result <= 9999999))) //check if number consists of  FOUR digits
    {
        LCD_Send_Character((result/1000000)+'0');
        LCD_Send_Character(((result%1000000)/100000)+'0');
        LCD_Send_Character((((result%1000000)%100000)/10000)+'0');
        LCD_Send_Character(((((result%1000000)%100000)%10000)/1000)+'0');
        LCD_Send_Character((((((result%1000000)%100000)%10000)%1000)/100)+'0');
        LCD_Send_Character(((((((result%1000000)%100000)%10000)%1000)%100)/10)+'0');
        LCD_Send_Character(((((((result%1000000)%100000)%10000)%1000)%100)%10)+'0');
    }
    else if((result >= 10000000)&&((result <= 99999999))) //check if number consists of  FOUR digits
    {
        LCD_Send_Character((result/10000000)+'0');
        LCD_Send_Character(((result%10000000)/1000000)+'0');
        LCD_Send_Character((((result%10000000)%1000000)/100000)+'0');
        LCD_Send_Character(((((result%10000000)%1000000)%100000)/10000)+'0');
        LCD_Send_Character((((((result%10000000)%1000000)%100000)%10000)/1000)+'0');
        LCD_Send_Character(((((((result%10000000)%1000000)%100000)%10000)%1000)/100)+'0');
        LCD_Send_Character((((((((result%10000000)%1000000)%100000)%10000)%1000)%100)/10)+'0');
        LCD_Send_Character((((((((result%10000000)%1000000)%100000)%10000)%1000)%100)%10)+'0');
    }
    else if((result >= 100000000)&&((result <= 999999999))) //check if number consists of  FOUR digits
    {
        LCD_Send_Character((result/100000000)+'0');
        LCD_Send_Character(((result%100000000)/10000000)+'0');
        LCD_Send_Character((((result%100000000)%10000000)/1000000)+'0');
        LCD_Send_Character(((((result%100000000)%10000000)%1000000)/100000)+'0');
        LCD_Send_Character((((((result%100000000)%10000000)%1000000)%100000)/10000)+'0');
        LCD_Send_Character(((((((result%100000000)%10000000)%1000000)%100000)%10000)/1000)+'0');
        LCD_Send_Character((((((((result%100000000)%10000000)%1000000)%100000)%10000)%1000)/100)+'0');
        LCD_Send_Character(((((((((result%100000000)%10000000)%1000000)%100000)%10000)%1000)%100)/10)+'0');
        LCD_Send_Character(((((((((result%100000000)%10000000)%1000000)%100000)%10000)%1000)%100)%10)+'0');
    }*/
}



void Delay_ms(unsigned long time)
{
 time = 145448;  // 0.1sec
  while(time){
  time--;
  }
}
//void Delay_ms(unsigned long time)
//{
// time = ((time/375)*1000000);
// while(time)
// {
//  time--;
// }
//}
void LCD_Clear()
{
 LCD_Send_Command(0x01);
}

void LCD_Send_Float(float f)
{
 unsigned int v,p;
 long int num;
 num=f*10000;
 p=num%10000;

 v=num/10000;

 LCD_Send_Integer(v);
 LCD_Send_Character('.');
 LCD_Send_Integer(p);

}
/*
void LCD_Send_Result(char word[]){
 unsigned char i=0; // iterating variable
 unsigned char length = (unsigned char)strlen(word); // length of the word

 // Printing the word
 for(i=0;i<length;i++)
 {
  LCD_Send_Character(word[i]);
 }
}
*/

/*void LCD_Send_Integer(float number){// This function prints integer on LCD
 char buffer[10];
 Delay_ms(10);
 sprintf(buffer,"%0.2f",number); // function sprintf converts integer to string
 LCD_Send_String(buffer);
}
*/
