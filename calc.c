/*
 * calc.c
 *
 *  Created on: 25 thg 4, 2017
 *      Author: voduytan
 */

#include "Calc.h"

void _delay_ms(unsigned long time)
{
 time = ((time/375)*1000000);
 while(time)
 {
  time--;
 }
}

void Calc(){

 char input[16] = {0};
 char read = 0;
 unsigned long int num1 = 0, num2 = 0;
 float result = 0;
 unsigned char count = 0, operator;
 unsigned char i = 0, operator_index, equal_index;

 while(((read =Keypad_Read())!= CLEAR)&&((read =Keypad_Read())!= 16)) //read opearnds and operator from user
  {
   input[count] = key_pressed(read); //save inputs
   LCD_Send_Character(key_pressed(Keypad_Read())+48); //display inputs on LCD display
   if(read == PLUS) //check the opearator
   {
    operator = PLUS;
    operator_index = count;
   }
   else if(read == MINUS)
   {
    operator = MINUS;
    operator_index = count;
   }
   else if(read == TIMES)
   {
    operator = TIMES;
    operator_index = count;
   }
   else if(read == DIVIDE)
   {
    operator = DIVIDE;
    operator_index = count;
   }
   count++;
  }

 if(Keypad_Read() == CLEAR)
 {
  count = 0;
  operator_index = 0;
  equal_index = 0;
  num1 = 0;
  num2 = 0;
  result = 0;
  LCD_Clear();
 }
 //Delay_ms(100);
 else if (Keypad_Read() == 16)
 {

  LCD_Send_Character('=');
  equal_index = count;

  //get the first operand
  for(i=0;i<operator_index;i++)
  {
    num1 += ((input[i])*(pow(10,(operator_index-i-1))));
  }

  //get the second operand
  for(i=operator_index+1;i<equal_index;i++)
  {
    num2 += ((input[i])*(pow(10,(equal_index-i-1))));
  }

  switch(operator)
  {
   case PLUS:
    result = num1+num2;
    break;

   case MINUS:
    if(num1>num2)
     result = num1-num2;
    else if (num1<num2)
    {
     Delay_ms(100);
     LCD_Goto(2,1);
     LCD_Send_Character('-');
     result = num2-num1;
    }
    else
    {
        result=0;
    }
    break;

   case TIMES:
    result = num1*num2;
    break;

   case DIVIDE:
    result = ((float)num1)/((float)num2);
    break;
  }

  Delay_ms(100);
  LCD_Goto(2,2);
  LCD_Send_Float(result); //Display the result
  Delay_ms(1000);
 }
}
