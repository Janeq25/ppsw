#include <LPC21xx.H>
#include "timer_interrupts.h"

//--------------Timer-Masks--------------
#define mCOUNTER_ENABLE 0x00000001
#define mCOUNTER_RESET  0x00000002

//-------------Compare-Match-Masks----------------
#define mINTERRUPT_ON_MR0 0x00000001
#define mRESET_ON_MR0     0x00000002
#define mMR0_INTERRUPT    0x00000001

//-------------VIC-MASKS-----------------
#define VIC_TIMER0_CHANNEL_NR 4 //TIMER0 interrupt channel number

#define mIRQ_SLOT_ENABLE 0x00000020 

//-----------Interrupt0-Corutine-Adress------------
void (*ptrTimer0InterruptFunction)();

//----------interrupt-handler-corutine-----------
__irq void Timer0IRQHandler(){

	T0IR=mMR0_INTERRUPT; 	// skasowanie flagi przerwania 
	ptrTimer0InterruptFunction();		// cos do roboty
	VICVectAddr=0x00; 	// potwierdzenie wykonania procedury obslugi przerwania
}


//-----------------------interrupt-init-----------------
void Timer0Interrupts_Init(unsigned int uiPeriod, void (*ptrInterruptFunction)()){ // microseconds

	ptrTimer0InterruptFunction = ptrInterruptFunction;
	
        // interrupts

	VICIntEnable |= (0x1 << VIC_TIMER0_CHANNEL_NR);            // Enable Timer 0 interrupt channel 
	VICVectCntl1  = mIRQ_SLOT_ENABLE | VIC_TIMER0_CHANNEL_NR;  // Enable Slot 0 and assign it to Timer 0 interrupt channel
	VICVectAddr1  =(unsigned long)Timer0IRQHandler; 	   // Set to Slot 0 Address of Interrupt Service Routine 

        // match module

	T0MR0 = 15 * uiPeriod;                 	      // value 
	T0MCR |= (mINTERRUPT_ON_MR0 | mRESET_ON_MR0); // action 

        // timer

	T0TCR =  mCOUNTER_ENABLE; // start 

}