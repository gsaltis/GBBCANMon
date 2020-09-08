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

extern uint32_t
CANInterfaceMessagesCount;

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/
bool
CANInterfaceThreadThrottleFile
();

void
CANInterfaceThreadCreateArchive
(string InFilename);

StringList*
CANInterfaceThreadGetArchivedFilenames
();

void
CANInterfaceThreadManageArchives
(string InFilename);

void
CANInterfaceThreadManageArchives
(string InFilename);

void
CANInterfaceManageArchives
(string InOutputFilename);

void
CANInterfaceManageArchives
(string InOutputFilename);

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
