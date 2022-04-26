#include <LPC21xx.H>
#include "keyboard.h"

#define BTN0_bm (1<<4)
#define BTN1_bm (1<<6)
#define BTN2_bm (1<<5)
#define BTN3_bm (1<<7)


void KeyboardInit(){
	IO0DIR = IO0DIR & ~(BTN0_bm | BTN1_bm | BTN2_bm | BTN3_bm);
}


enum KeyboardState eKeyboardRead(){
	if ((IO0PIN & BTN0_bm) == 0){
		return BUTTON_0;
	}
	
	if ((IO0PIN & BTN1_bm) == 0){ // wcisniety 0x00000000 puszczony 0x00000040
		return BUTTON_1;
	}
	
	if ((IO0PIN & BTN2_bm) == 0){ // wcisniety 0x00000000 puszczony 0x00000020
		return BUTTON_2;
		
	}
	
	if ((IO0PIN & BTN3_bm) == 0){
		return BUTTON_3;
	}
	
	return RELEASED;
}
