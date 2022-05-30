#include "led.h"
#include "keyboard.h"

enum CurrentState {LEFT, RIGHT, STAY, RIGHT_TO_LEFT};
enum CurrentState eCurrentState = STAY;

unsigned char ucBlinkCounter;

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
			else{
				eCurrentState = LEFT;
			}
			break;
			
			case RIGHT:
			LedStepRight();
			if (eKeyboardRead() == BUTTON_1){
				eCurrentState = STAY;
			}
			else if (eKeyboardRead() == BUTTON_3){
					eCurrentState = RIGHT_TO_LEFT;
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
			
			case RIGHT_TO_LEFT:
				if (ucBlinkCounter > 4){
					ucBlinkCounter = 0;
					eCurrentState = LEFT;
				}
				else{
					if (ucBlinkCounter % 2 == 0){
						LedStepLeft();
					}
					else	{
						LedStepRight();
					}
					ucBlinkCounter++;
				}
				break;
				
		
		}
		delay_ms(500);
	}
	return 0;
}
