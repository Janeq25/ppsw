#include <LPC21xx.H>

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)
#define BTN0_bm (1<<4)
#define BTN1_bm (1<<6)
#define BTN2_bm (1<<5)
#define BTN3_bm (1<<7)


//----------GLOBAL_VARS--------

enum KeyboardState {BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3, RELEASED};

enum Direction {LEFT, RIGHT};


//----------DELAY------------------------

void delay(){
	int i = 0;
	for (i = 0; i < 2000; i++){}
}

void delay_ms(int iTime){
	int iCount;
	
	iTime *= 2400;
	
	for (iCount = 0; iCount < iTime; iCount++){}
}

//----------LED------------------------

void LedInit(){
	IO1DIR |= LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	
	IO1SET |= LED0_bm;
	
}

void LedOn(unsigned char ucLedIndeks){
	//przerobic na swich
	
	IO1CLR = 0x00FF0000;
	
	switch (ucLedIndeks) {
	
		case 0:
			IO1SET = 1 << 16;
			break;
		case 1:
			IO1SET = 1 << 17;
			break;
		case 2:
			IO1SET = 1 << 18;
			break;
		case 3:
			IO1SET = 1 << 19;
			break;
		case 4:
			IO1SET = 1 << 20;
			break;
		case 5:
			IO1SET = 1 << 21;
			break;
		case 6:
			IO1SET = 1 << 22;
			break;
		case 7:
			IO1SET = 1 << 23;
			break;
		
		
	}
}



void LedStep(enum Direction eDirection){
	
	static unsigned int uiLedStepCounter;
	
	switch (eDirection){
		
		case LEFT:
			uiLedStepCounter = (uiLedStepCounter += 1) % 4;
			LedOn(uiLedStepCounter);
			break;
		
		case RIGHT:
			uiLedStepCounter = (uiLedStepCounter -= 1) % 4;
			LedOn(uiLedStepCounter);
			break;	
	}
}

void LedStepLeft(void){
	LedStep(LEFT);
}

void LedStepRight(void){
	LedStep(RIGHT);
}


//----------BUTTON------------------------


void KeyboardInit(){
	IO0DIR = IO0DIR & 0xFFFFFF0F;
}


enum KeyboardState eKeyboardRead(){
	if ((IO0PIN & BTN0_bm) == 0){
		return BUTTON_0;
	}
	
	if ((IO0PIN & BTN1_bm) == 0){
		return BUTTON_1;
	}
	
	if ((IO0PIN & BTN2_bm) == 0){
		return BUTTON_2;
	}
	
	if ((IO0PIN & BTN3_bm) == 0){
		return BUTTON_3;
	}
	
	return RELEASED;
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
		}
		
		delay_ms(250);
	}
}

