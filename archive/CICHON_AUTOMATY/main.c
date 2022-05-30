#include "led.h"
#include "keyboard.h"

enum CurrentState {LEFT, RIGHT, STAY};
enum CurrentState eCurrentState = STAY;


void delay_ms(int iTime){
	int iCount;
	
	iTime *= 2400;
	
	for (iCount = 0; iCount < iTime; iCount++){}
}

int main(){
	LedInit();
	KeyboardInit();
	
	while(1){
		switch (eCurrentState){
		
			case LEFT:
			LedStepLeft();
			if (eKeyboardRead() == BUTTON_1){
				eCurrentState = STAY;
			}
			else {
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
		delay_ms(100);
	}
	return 0;
}
