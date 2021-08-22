/*
  This program lights the green LED if a key pressed in the keypad
	else the red LED is on

*/

#include "tm4c123gh6pm.h"


void PORTB_init(void);
void PORTF_init(void);
int result = 1;
int main(){
	PORTB_init();
	PORTF_init();
	
	while(1){
		result = (~GPIOB->DATA) & 0x0F;
		if(result != 0) GPIOF->DATA = 0x08;
		else GPIOF->DATA = 0x02;
	}
	
	/*
	while(1){
		GPIOF->DATA = (!GPIOB->DATA) & 0x0F;
	}
	*/
}

void PORTB_init(void){
	int dummy;
	SYSCTL->RCGCGPIO |= 0x02;
	dummy = 1;
	GPIOB->DIR = 0xF0;
	GPIOB->DEN = 0xFF;
	GPIOB->PUR = 0x0F;
	GPIOB->DATA = 0;
}
void PORTF_init(void){
	int dummy;
	SYSCTL->RCGCGPIO |= 0x20;
	dummy = 1;
	GPIOF->DIR = 0x0E;
	GPIOF->DEN = 0x0E;
	GPIOF->DATA = 0;
}

/* This function is called by the startup assembly code to perform system specific
initialization tasks. */
void SystemInit(void)
{
/*coprocessor Grant access*/
/* This is required since TM4C123G has a floating point coprocessor */
	SCB->CPACR |= 0x00F00000;
}
