/*
 * CFile1.c
 *
 * Created: 12/31/2015 11:52:56 AM
 *  Author: BrnoldWin7
 */ 

#include "circularQueue.h"

unsigned char theQueue[_QUEUESIZE];
volatile unsigned char qRead =0, qWrite =0, temporaryQueueStorage = 0;

volatile bool isCircularQueueEmpty(void){
	if(qWrite == qRead)
		return true;
	else
		return false;	
}

unsigned char readCircularQueue(void){
	temporaryQueueStorage = theQueue[qRead];
	
	if(qRead==(_QUEUESIZE-1))
		qRead = 0;
	else
		qRead++;	
		
	return temporaryQueueStorage;

}
void writeCircularQueue(unsigned char data){
	theQueue[qWrite]= data;
	
	if(qWrite==(_QUEUESIZE-1))
		qWrite = 0;
	else
		qWrite++;
}