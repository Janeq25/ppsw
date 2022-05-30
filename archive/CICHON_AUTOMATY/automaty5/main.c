#include "led.h"
#include "keyboard.h"

enum CurrentState {MOVE, STAY};
enum CurrentState eCurrentState = MOVE;

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
		
			case MOVE:
			LedStepRight();
			if (eKeyboardRead() == BUTTON_0){
				eCurrentState = STAY;
			}
			else {
				eCurrentState = MOVE;
			}
			break;
			
			case STAY:
			if (eKeyboardRead() == BUTTON_1){
				eCurrentState = MOVE;
			}
			else {
				eCurrentState = STAY;
			}
			break;
		
		}
		delay_ms(500);
	}
	return 0;
}
