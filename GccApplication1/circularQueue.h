/*
 * circularQueue.h
 *
 * Created: 12/31/2015 11:53:20 AM
 *  Author: BrnoldWin7
 */ 

#include "stdbool.h"

#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_

#define _QUEUESIZE 250 //picked a huge random size



bool isCircularQueueEmpty(void);
unsigned char readCircularQueue(void);
void writeCircularQueue(unsigned char data);


#endif /* CIRCULARQUEUE_H_ */