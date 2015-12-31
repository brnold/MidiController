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





int main(void) {
	
	
	/* Do I need to setup the clock? */
	
	//how to mask the uart interrupt, can it be done?
	
	//Initiate the Peripherals
	initUARTInterruptBased();
	//sei();
	//change uart to interrupts
	//ring buffer
	//Implemented, not tested
	
	
	//play a song
	
	
	putByte(0xFF);
	putByte(0xFF);
	putByte(0xFF);
	
	putByte(0xFF);
	putByte(0xFF);
	putByte(0xFF);
	
	putByte(0xFF);
	putByte(0xFF);
	putByte(0xFF);
	
	while(1) {
		for(char i = 32; i<90; i++){
			/*midiCommandToQueue(0x00,_NOTEON, i);
			_delay_ms(500);
			midiCommandToQueue(0x00, _NOTEOFF, i); */
			midiCommand(0x00,_NOTEON, i);
			_delay_ms(500);
			midiCommand(0x00, _NOTEOFF, i); 
			
		}	
	}
	
	
	}

ISR(USART_TX_vect){
	//Push the next element on the stack
	if(isCircularQueueEmpty() == true){
		UCSR0B &= ~(1 << TXCIE0);
		return;
		//need to disable the interrupt until the queue has data again.
	}else{
		//load the next item on the queue into the uart register
		putByte(readCircularQueue());
		//putByte not sure if it will work or not.
	}
	
}