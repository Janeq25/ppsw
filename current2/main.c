#include "led.h"
#include "keyboard.h"

enum CurrentState {MOVE, STAY};
enum CurrentState eCurrentState = MOVE;

char cLedCounter = 0;

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
			cLedCounter++;
			if (cLedCounter > 2){
				eCurrentState = STAY;
				cLedCounter = 0;
			}
			else {
				eCurrentState = MOVE;
			}
			break;
			
			case STAY:
			if (eKeyboardRead() == BUTTON_0){
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
