/*
 * midiHelper.h
 *
 * Created: 12/31/2015 10:05:01 AM
 *  Author: BrnoldWin7
 */ 

#include "uart.h"

#ifndef MIDIHELPER_H_
#define MIDIHELPER_H_

#define _NOTEON 0x90
#define _NOTEOFF 0x80

/* https://www.arduino.cc/en/Tutorial/Midi */
void midiNote(int cmd, int pitch, int velocity){
	putByte(cmd);
	putByte(pitch);
	putByte(velocity);
}


#endif /* MIDIHELPER_H_ */