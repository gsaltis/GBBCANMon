/*****************************************************************************
 * FILE NAME    : UserInputThread.c
 * DATE         : July 15 2020
 * PROJECT      : GBB CAN Monitor
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <linenoise.h>
#include <StringUtils.h>
#include <MemoryManager.h>
#include <ANSIColors.h>
#include <FileUtils.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "UserInputThread.h"
#include "CANInterfaceThread.h"
#include "main.h"
#include "CANMonLog.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
pthread_t
UserInputThreadID;

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void*
UserInputThread
(void* InArg);

void
HandleCommandLimitSet
(StringList* InString);

void
HandleCommandLimit
(StringList* InString);

void
HandleCommand
(StringList* InStrings);

void
HandleCommandExit
(StringList* InStrings);

void
HandleCommandMessage
(StringList* InStrings);

void
HandleCommandMessageCount
(StringList* InStrings);

void
HandleCommandTime
(StringList* InStrings);

void
HandleCommandTimeElapsed
(StringList* InStrings);

void
HandleCommandMonitor
(StringList* InStrings);

void
HandleCommandMonitorStop
(StringList* InStrings);

void
HandleCommandMonitorStart
(StringList* InStrings);

void
HandleCommandMonitorClear
(StringList* InStrings);

void
HandleCommandHelp
(StringList* InStrings);

void
HandleCommandLog
(StringList* InStrings);

/*****************************************************************************!
 * Function : UserInputThreadInit
 *****************************************************************************/
void
UserInputThreadInit
()
{
  pthread_create(&UserInputThreadID, NULL, UserInputThread, NULL);
}

/*****************************************************************************!
 * Function : UserInputThread
 *****************************************************************************/
void*
UserInputThread
(void* InArg)
{
  string                                prompt = "Enter Command : ";
  string                                commandline;
  StringList*                           strings;

  MainDisplayVersion();
  while (true) {
    commandline = linenoise(prompt);
    strings = StringSplit(commandline, " ", true);
    HandleCommand(strings);
    linenoiseHistoryAdd(commandline);
    free(commandline);
    StringListDestroy(strings);
  }
}

#include "UserInputThread/HandleCommandLog.c"
#include "UserInputThread/HandleCommandLimit.c"
#include "UserInputThread/HandleCommandLimitSet.c"
#include "UserInputThread/HandleCommandHelp.c"
#include "UserInputThread/CANInterfaceMonitorCountReset.c"
#include "UserInputThread/HandleCommandMonitorClear.c"
#include "UserInputThread/HandleCommandMonitorStart.c"
#include "UserInputThread/HandleCommandMonitorStop.c"
#include "UserInputThread/HandleCommandMonitor.c"
#include "UserInputThread/HandleCommandMessageCount.c"
#include "UserInputThread/HandleCommandMessage.c"
#include "UserInputThread/HandleCommandExit.c"
#include "UserInputThread/HandleCommandTimeElapsed.c"
#include "UserInputThread/HandleCommandTime.c"
#include "UserInputThread/HandleCommand.c"
