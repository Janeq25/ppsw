#include "led.h"


enum LedDirection {LEFT, RIGHT};
enum LedDirection eLedDirection = LEFT;

char cLedCounter = 0;

void delay_ms(int iTime){
	int iCount;
	
	iTime *= 2400;
	
	for (iCount = 0; iCount < iTime; iCount++){}
}

int main(){
	LedInit();
	
	while(1){
		switch (eLedDirection){
		
			case LEFT:
			LedStepLeft();
			cLedCounter++;
			if (cLedCounter > 2){
				eLedDirection = RIGHT;
				cLedCounter = 0;
			}
			else {
				eLedDirection = LEFT;
			}
			break;
			
			case RIGHT:
			LedStepRight();
			cLedCounter++;
			if (cLedCounter > 2){
				eLedDirection = LEFT;
				cLedCounter = 0;
			}
			else {
				eLedDirection = RIGHT;
			}
			break;
		
		}
		delay_ms(500);
	}
	return 0;
}
