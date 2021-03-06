#include "led.h"


enum LedState {LED_LEFT, LED_RIGHT};
enum LedState eLedState = LED_LEFT;

int main(){
	LedInit();
	
	while(1){
		switch (eLedState){
		
			case LED_LEFT:
			LedStepLeft();
			eLedState = LED_RIGHT;
			break;
			
			case LED_RIGHT:
			LedStepRight();
			eLedState = LED_LEFT;
			break;
		
		}
	}
	return 0;
}
