#include "inc/tm4c123gh6pm.h"
#include"LCD.h"
#include"KEYPAD.h"
#include "Calc.h"
#include "stdint.h"

void PortE_Init(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000010;     // 1) activate clock for Port E
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTE_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTE_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTE_DIR_R = 0xFF;          // 5) PE as output
  GPIO_PORTE_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTE_PDR_R = 0x00;          // enable pull-up on PF0 and PF4
  GPIO_PORTE_DEN_R = 0xFF;          // 7) enable digital I/O on PF4-0
}

void PortA_Init(void){ volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTA_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTA_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTA_DIR_R = 0x00;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTA_AFSEL_R = 0x00;        // 6) disable alt funct on PA7-0
  GPIO_PORTA_PUR_R = 0xFF;          // enable pull-up on PA4,5,6,7
  GPIO_PORTA_DEN_R = 0xFF;          // 7) enable digital I/O on PFA-0
}


void PortF_Init(void){ volatile unsigned long delay;
SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;  // 1) activate clock for Port F
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
  // only PF0 needs to be unlocked, other bits can't be locked
  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
  GPIO_PORTF_PUR_R = 0x11;          // enable pull-up on PF0 and PF4
  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital I/O on PF4-0
}

/*void _delay_ms(unsigned long time)
{
 time = ((time/375)*1000000);
 while(time)
 {
  time--;
 }
}*/



int main()
{
 PortF_Init();
 PortA_Init();
 PortE_Init();

 LCD_init();
 Keypad_Init();
 LCD_Clear();

 LCD_Goto(1,1);
 LCD_Send_String("Calculator >_<");

 LCD_Goto(2,1);
 LCD_Send_String("Lap Trinh Nhung...");

 _delay_ms(3000);
 LCD_Clear();

 while(1){
    //LCD_Clear();
    LCD_Goto(1,1);
    Calc();
    Delay_ms(2000);
    }
}
