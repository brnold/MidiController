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





int main(void) {
	
	
	/* Do I need to setup the clock? */
	
	//Initiate the Peripherals
	initUART();
	
	
	
	
	while(1) {
		for(char i = 32; i<90; i++){
			midiNote(_NOTEON, i, (unsigned char)100);
			_delay_ms(500);
			midiNote(_NOTEOFF, i, (unsigned char)100);
		}
		
		
			
		
	}
	
	
	
	
	}
