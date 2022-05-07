#include "timer.h"
#include "led.h"


int main(){
	LedInit();
	InitTimer0();
	
	while (1){
		LedStepLeft();
		WaitOnTimer0(250000);
	}
	
	return 0;
}

