#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE_BIT (1<<0)
#define COUNTER_RESET_BIT (1<<1)
#define INTERRUPT_ON_MR0_BIT (1<<0)

void InitTimer0(void){
	T0TCR |= COUNTER_ENABLE_BIT;
}

void WaitOnTimer0(unsigned int uiTime){
	T0TCR |= COUNTER_RESET_BIT;
	T0TCR &= ~COUNTER_RESET_BIT;
	
	while (T0TC < (uiTime * 15)) {}
}

