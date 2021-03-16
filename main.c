/*****************************************************************************
 * FILE NAME    : main.c
 * DATE         : July 14 2020
 * PROJECT      : CAN Monitor
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/
#define _GNU_SOURCE

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <sqlite3.h>
#include <mongoose.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <FileUtils.h>
#include <StringUtils.h>
#include <MemoryManager.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CANInterface.h"
#include "DeviceDef.h"
#include "CANInterfaceThread.h"
#include "UserInputThread.h"
#include "HTTPServerThread.h"
#include "WebSocketIF.h"
#include "DirManagement.h"
#include "CANMonLog.h"
#include "main.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
string
MainVersionNumber = "1.2.0";

bool
MainVerbose = false;

int
MainMinLimitCount = 1;

int
MainMaxLimitCount = 100000000;

int
MainMinLimitSize = 1;

int
MainMaxLimitSize = 2000000000;

int
MainMinLimitHours = 1;

int
MainMaxLimitHours = 96;

int
MainMinLimitDays = 1;

int
MainMaxLimitDays = 7;

CANInterface*
MainCANInterface = NULL;

string
MainCANInterfaceName = NULL;

DeviceDefList*
mainDeviceDefs;

sqlite3*
MainDatabase;

string
MainDatabaseName = NULL;

bool
MainClearDatabaseSwitch = false;

time_t
MainStartTime;

time_t
MainTimeStampTime;

struct mg_serve_http_opts
s_http_server_opts;

string
MainDefaultWebSocketPort = "8011";

string
MainProgramName = "canmon";

void
MainExit
();

string
MainLimitType;

int
MainLimitHours = 0;

int
MainLimitSize = 0;

int
MainLimitCount = 0;

int
MainLimitDays = 0;

int
MainLimitDaysRuntime = 0;

int
MainLimitHoursRuntime = 0;

int
MainLimitCountRuntime = 0;

int
MainLimitSizeRuntime = 0;

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void
MainExit
();

void
MainInitialize
();

void
MainProcessCommandLine
(int argc, char** argv);

void
MainVerifyCommandLine
();

void
MainDisplayHelp
();

void
MainOpenDatabase
();

void
MainClearDatabase
();

bool
MainUseUI = true;

void
MainRemoveTarFiles
();

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  void*                                 retval1;
  void*                                 retval2;
  void*                                 retval3;
  void*                                 retval4;

  MainInitialize();
  MainProcessCommandLine(argc, argv);

  CANMonLogInit();
  DirManagementLog();
  CANMonLogWrite("%s starting\n", MainProgramName);
  
  // Clean up any tar files lying around after previous sessions
  MainRemoveTarFiles();

  MainVerifyCommandLine();
  MainOpenDatabase();
  WebSocketIFCreateInfoScript();
  if ( MainClearDatabaseSwitch ) {
    MainClearDatabase();
  }

  MainCANInterface = CANInterfaceInit(MainCANInterfaceName);
  if ( NULL == MainCANInterface ) {
    fprintf(stderr, "Could not open CAN Interface %s\n", MainCANInterfaceName);
    exit(EXIT_FAILURE);
  }

  HTTPServerThreadInit();
  CANInterfaceThreadInit();
  WebSocketServerInit();
  if ( MainUseUI ) {
    UserInputThreadInit();
  }

  pthread_join(CANInterfaceThreadID, &retval1);
  if ( MainUseUI ) {
    pthread_join(UserInputThreadID, &retval2);
  }
  pthread_join(HTTPServerThreadID, &retval3);
  pthread_join(WebSocketServerThreadID, &retval4);
  return EXIT_SUCCESS;
}

#include "Main/MainProcessCommandLine.c"
#include "Main/MainDisplayHelp.c"
#include "Main/MainInitialize.c"
#include "Main/MainExit.c"
#include "Main/MainRemoveTarFiles.c"
#include "Main/MainLimitSet.c"
#include "Main/MainDisplayVersion.c"
#include "Main/MainInitializeStartTime.c"
#include "Main/MainClearDatabase.c"
#include "Main/MainOpenDatabase.c"
#include "Main/MainVerifyCommandLine.c"
#include "Main/MainLimitTypeSet.c"
#include "Main/MainLimitSizeSet.c"
