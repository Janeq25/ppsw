#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"


void delay_ms(int iTime){
	int iCount;
	
	iTime *= 2400;
	
	for (iCount = 0; iCount < iTime; iCount++){}
}


int main(){
	LedInit();
	KeyboardInit();
	
	while(1){		
		switch (eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				break;
			
			case BUTTON_2:
				LedStepLeft();
				break;
			
			default:
			break;
		}
		delay_ms(250);
	}
}
