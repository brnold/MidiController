/*
 * midiHelper.c
 *
 * Created: 12/31/2015 11:11:37 AM
 *  Author: BrnoldWin7
 */ 

#include "midiHelper.h"
#include "circularQueue.h"

/* https://www.arduino.cc/en/Tutorial/Midi */
void midiCommand(char channel, char cmd, char pitch){
	
	char chanelCommand = (cmd && 0xF0) + (channel && 0x0F);
	
	//push channel and command
	putByte(chanelCommand);
	//push pitch
	putByte(pitch);
	//push velocity
	putByte(_DEFAULTVELOCITY);
}

void midiCommandToQueue(char channel, char cmd, char pitch){
		
		char chanelCommand = (cmd && 0xF0) + (channel && 0x0F);
		
		//push channel and command
		writeCircularQueue(chanelCommand);
		//push pitch
		writeCircularQueue(pitch);
		//push velocity
		writeCircularQueue(_DEFAULTVELOCITY);
}
