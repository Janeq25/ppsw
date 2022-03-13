#include <LPC21xx.H>

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)
#define BTN0_bm (1<<4)

void delay(){
	int i = 0;
	for (i = 0; i < 2000; i++){}
}

void delay_ms(int iTime){
	int iCount;
	
	iTime *= 2400;
	
	for (iCount = 0; iCount < iTime; iCount++){}
}

void LedInit(){
	IO1DIR |= LED0_bm;
	IO1DIR |= LED1_bm;
	IO1DIR |= LED2_bm;
	IO1DIR |= LED3_bm;
	
	IO1SET |= LED0_bm;
	
}

void LedOn(unsigned char ucLedIndeks){
	if (ucLedIndeks >= 0 && ucLedIndeks <= 7){
		IO1CLR = 0xffffffff;
		
		IO1SET = 1 << (ucLedIndeks + 16);
	}
}


unsigned char ucReadButton1(){
	int test;
	test = IO0PIN & (1<<4);
	if ((IO0PIN & BTN0_bm) > 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	LedInit();
	
	
	while(1){
		if (ucReadButton1() == 1){
			LedOn(1);
		}
		else{
		LedOn(0);
		}
	}
	
}

