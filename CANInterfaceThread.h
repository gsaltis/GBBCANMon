/*****************************************************************************
 * FILE NAME    : CANInterfaceThread.h
 * DATE         : July 14 2020
 * PROJECT      : CAN Monitor 
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/
#ifndef _caninterfacethread_h_
#define _caninterfacethread_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/
extern
pthread_t
CANInterfaceThreadID;

extern
uint32_t
CANInterfaceMessagesCount;

extern
bool
CANInterfaceMonitor;

extern
string
CANInterfaceOutputFilename;

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/
void
CANInterfaceThreadInit
();

void
CANInterfaceMonitorStop
();

void
CANInterfaceMonitorStart
();

void
CANInterfaceFileOpen
(bool InAppendFile);

void
CANInterfaceFileClose
();

void
CANInterfaceMonitorCountReset
();

#endif /* _caninterfacethread_h_*/
