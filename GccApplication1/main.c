/*
 * GccApplication1.c
 *
 * Created: 12/30/2015 7:17:59 PM
 * Author : BrnoldWin7
 */ 

#define F_CPU 16000000UL // 16 MHz


#include <avr/io.h>
#include "uart.h"
#include <util/delay.h>
#include "midiHelper.h"
#include <avr/interrupt.h>
#include "circularQueue.h"


volatile bool interruptBool ;


int main(void) {
	
	
	/* Do I need to setup the clock? */
	
	//how to mask the uart interrupt, can it be done?
	
	//Initiate the Peripherals
	initUARTInterruptBased();
	sei();
	//change uart to interrupts
	//ring buffer
	//Implemented, not tested
	
	
	//play a song
	
	midiCommand(0x00, _NOTEOFF, 45);

	while(1) {
		for(char i = 32; i<90; i++){
			midiCommandToQueue(0x00,_NOTEON, i);
			midiCommandToQueue(0x01,_NOTEON, i);
			_delay_ms(500);
			midiCommandToQueue(0x00, _NOTEOFF, i); 
			midiCommandToQueue(0x01, _NOTEOFF, i); 
			
			
		}	
	}
	
	
	}

ISR(USART_TX_vect){
	//Push the next element on the stack
	
	putByte(readCircularQueue());
	interruptBool  = isCircularQueueEmpty();
	if(interruptBool == true){
		UCSR0B &= ~(1 << TXCIE0);
		//midiCommand(0x00, _NOTEOFF, 43);
		
		//need to disable the interrupt until the queue has data again.
	}
	
}