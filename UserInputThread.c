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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "UserInputThread.h"
#include "linenoise.h"
#include "String.h"
#include "MemoryManager.h"
#include "ANSIColors.h"
#include "linenoise.h"
#include "CANInterfaceThread.h"
#include "main.h"
#include "FileUtils.h"
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
  string				prompt = "Enter Command : ";
  string				commandline;
  StringList*				strings;

  while (true) {
    commandline = linenoise(prompt);
    strings = StringSplit(commandline, " ", true);
    HandleCommand(strings);
    linenoiseHistoryAdd(commandline);
    free(commandline);
    StringListDestroy(strings);
  }
}

/*****************************************************************************!
 * Function : HandleCommand
 *****************************************************************************/
void
HandleCommand
(StringList* InStrings)
{
  string				command;
  if ( NULL == InStrings || InStrings->stringCount == 0 ) {
    return;
  }
  command = InStrings->strings[0];
  if ( StringEqualNoCase(command, "EXIT")  || StringEqualNoCase(command, "QUIT") ) {
    HandleCommandExit(InStrings);
  } else if ( StringEqualNoCase(command, "MESSAGE") ) {
    HandleCommandMessage(InStrings);
  } else if ( StringEqualNoCase(command, "TIME") ) {
    HandleCommandTime(InStrings);
  } else if ( StringEqualNoCase(command, "HELP") ) {
    HandleCommandHelp(InStrings);
  } else if ( StringEqualNoCase(command, "MONITOR") ) {
    HandleCommandMonitor(InStrings);
  } else if ( StringEqualNoCase(command, "LOG") ) {
    HandleCommandLog(InStrings);
  }
}

/*****************************************************************************!
 * Function : HandleCommandHelp
 *****************************************************************************/
void
HandleCommandHelp
(StringList* InStrings)
{
  fprintf(stdout, "COMMANDS\n");
  fprintf(stdout, "%s  MESSAGE COUNT%s                       - Display number of messages seen\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  TIME ELAPSED%s                        - Display the time application has been running\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  MONITOR%s                             - Display the monitoring status\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  MONITOR STOP%s                        - Stop the montitoring of CAN Data\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s          START%s                       - Start the montitoring of CAN Data\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s          CLEAR%s                       - Clear the collected of CAN Data\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  HELP%s                                - Display this information\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  EXIT | QUIT%s                         - Exit the application\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  LOG%s                                 - Display the log\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s\n", ColorReset);
}


/*****************************************************************************!
 * Function : HandleCommandTime
 *****************************************************************************/
void
HandleCommandTime
(StringList* InStrings)
{
  if ( NULL == InStrings || InStrings->stringCount < 2 ) {
    return;
  }
  if ( StringEqualNoCase("ELAPSED", InStrings->strings[1]) ) {
    HandleCommandTimeElapsed(InStrings);
  }
}

/*****************************************************************************!
 * Function ; HandleCommandTimeElapsed
 *****************************************************************************/
void
HandleCommandTimeElapsed
(StringList* InStrings)
{
  time_t				t;
  uint32_t				e, hours, minutes, seconds;

  t = time(NULL);

  e = t - MainStartTime;
  hours = e / 3600;
  e = e % 3600;
  minutes = e / 60;
  seconds = e % 60;

  if ( hours ) {
    fprintf(stdout, "Elapsed : %d:%02d:%02d\n", hours, minutes, seconds);
  } else {
    fprintf(stdout, "Elapsed : %d:%02d\n", minutes, seconds);
  }
}

/*****************************************************************************!
 * Function : HandleCommandExit
 *****************************************************************************/
void
HandleCommandExit
(StringList* InStrings)
{
  exit(EXIT_SUCCESS);
}

/*****************************************************************************!
 * Function : HandleCommandMessage
 *****************************************************************************/
void
HandleCommandMessage
(StringList* InStrings)
{
  string				command;

  if ( NULL == InStrings || InStrings->stringCount < 2 ) {
    return;
  }
  command = InStrings->strings[1];
  if ( StringEqualNoCase(command, "COUNT") ) {
    HandleCommandMessageCount(InStrings);
  }
}

/*****************************************************************************!
 * Function : HandleCommandMessageCount
 *****************************************************************************/
void
HandleCommandMessageCount
(StringList* InStrings)
{
  time_t				currentTime = time(NULL);
  time_t				elapsedTime = currentTime - MainStartTime;
  fprintf(stdout, "%sMessage Count : %d %ld seconds%s\n", ColorBrightGreen, CANInterfaceMessagesCount, elapsedTime, ColorReset);
}

/*****************************************************************************!
 * Function : HandleCommandMonitor
 *****************************************************************************/
void
HandleCommandMonitor
(StringList* InStrings)
{
  if ( InStrings == NULL ) {
    return;
  } 
  if ( InStrings->stringCount == 1 ) {
    printf("Monitor CAN Traffic : %s\n", CANInterfaceMonitor ? "ON" : "FALSE");
    printf("Monitor Output file : %s\n", CANInterfaceOutputFilename);
    return;
  }
  if ( InStrings->stringCount < 2 ) {
    return;
  }
  if ( StringEqualNoCase(InStrings->strings[1], "STOP") ) {
    HandleCommandMonitorStop(InStrings);
  } else if ( StringEqualNoCase(InStrings->strings[1], "START") ) {
    HandleCommandMonitorStart(InStrings);
  } else if ( StringEqualNoCase(InStrings->strings[1], "CLEAR") ) {
    HandleCommandMonitorClear(InStrings);
  } 
}

/*****************************************************************************!
 * Function : HandleCommandMonitorStop
 *****************************************************************************/
void
HandleCommandMonitorStop
(StringList* InStrings)
{
  if ( InStrings == NULL ) {
    return;
  }
  if ( InStrings->stringCount < 2 ) {
    return;
  }
  CANInterfaceFileClose();
  CANInterfaceMonitorStop();
}

/*****************************************************************************!
 * Function : HandleCommandMonitorStart
 *****************************************************************************/
void
HandleCommandMonitorStart
(StringList* InStrings)
{
  if ( InStrings == NULL ) {
    return;
  }
  if ( InStrings->stringCount < 2 ) {
    return;
  }
  CANInterfaceFileOpen(true);
  CANInterfaceMonitorStart();
}

/*****************************************************************************!
 * Function : HandleCommandMonitorClear
 *****************************************************************************/
void
HandleCommandMonitorClear
(StringList* InStrings)
{
  if ( InStrings == NULL ) {
    return;
  }
  if ( InStrings->stringCount < 2 ) {
    return;
  }
  CANInterfaceMonitorStop();
  CANInterfaceFileClose();
  CANInterfaceMonitorCountReset();
  CANInterfaceFileOpen(false);
  CANInterfaceMonitorStart();
}

/*****************************************************************************!
 * Function : CANInterfaceMonitorCountReset
 *****************************************************************************/
void
CANInterfaceMonitorCountReset
()
{
  CANInterfaceMessagesCount = 0;
}

#include "HandleCommandLog.c"

