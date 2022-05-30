#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE_BIT (1<<0)
#define COUNTER_RESET_BIT (1<<1)

#define MR0_INTERRUPT_BIT (1<<0)
#define MR0_RESET_BIT (1<<1)

void InitTimer0(void){
	T0TCR |= COUNTER_ENABLE_BIT;
}

void WaitOnTimer0(unsigned int uiTime){
	T0TCR |= COUNTER_RESET_BIT;
	T0TCR &= ~COUNTER_RESET_BIT;
	
	while (T0TC < (uiTime * 15)) {} //cykl licznika i cykl sprawdzania czy warunek jest spelniony 
}

void InitTimer0Match0(unsigned int uiDelayTime){
	T0TCR |= COUNTER_ENABLE_BIT;
	T0MCR |= MR0_INTERRUPT_BIT | MR0_RESET_BIT;
	
	T0MR0 = uiDelayTime * 15;
	
	T0TCR |= COUNTER_RESET_BIT;
	T0TCR &= ~COUNTER_RESET_BIT;
}

void WaitOnTimer0Match0(void){
	while ((T0IR & MR0_INTERRUPT_BIT) == 0){}
	T0IR = MR0_INTERRUPT_BIT;
}


