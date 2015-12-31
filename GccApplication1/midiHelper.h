/*
 * midiHelper.h
 *
 * Created: 12/31/2015 10:05:01 AM
 *  Author: BrnoldWin7
 */ 

#include "uart.h"
#include "circularQueue.h"

#ifndef MIDIHELPER_H_
#define MIDIHELPER_H_

#define _NOTEON 0x90
#define _NOTEOFF 0x80
#define _DEFAULTVELOCITY 0x90


void midiCommand(char channel, char cmd, char pitch);
void midiCommandToQueue(char channel, char cmd, char pitch);

#endif /* MIDIHELPER_H_ */