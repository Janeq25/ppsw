#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"


void Automat(){
	enum CurrentState {LEFT, RIGHT, STAY};
	static enum CurrentState eCurrentState = STAY;
	
	switch (eCurrentState){
		
			case LEFT:
			LedStepLeft();
			if (eKeyboardRead() == BUTTON_1){
				eCurrentState = STAY;
			}
			else{
				eCurrentState = LEFT;
			}
			break;
			
			case RIGHT:
			LedStepRight();
			if (eKeyboardRead() == BUTTON_1){
				eCurrentState = STAY;
			}
			else {
				eCurrentState = RIGHT;
			}
			break;
			
			case STAY:
			if (eKeyboardRead() == BUTTON_0){
				eCurrentState = LEFT;
			}
			else if (eKeyboardRead() == BUTTON_2){
				eCurrentState = RIGHT;
			}
			else {
				eCurrentState = STAY;
			}
			break;
	}
}


int main (){
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	Timer0Interrupts_Init(20000, &Automat);
	

	while(1){
	 	iMainLoopCtr++;
	}
}