/*****************************************************************************
 * FILE NAME    : main.c
 * DATE         : July 14 2020
 * PROJECT      : CAN Monitor
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
#include <sqlite3.h>
#include <mongoose.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CANInterface.h"
#include "String.h"
#include "DeviceDef.h"
#include "CANInterfaceThread.h"
#include "MemoryManager.h"
#include "UserInputThread.h"
#include "HTTPServerThread.h"
#include "WebSocketIF.h"
#include "DirManagement.h"
#include "CANMonLog.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
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

struct mg_serve_http_opts
s_http_server_opts;

string
MainDefaultWebSocketPort = "8011";

string
MainProgramName = "canmon";

void
MainExit
();

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
VerifyCommandLine
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

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  void*					retval1;
  void*					retval2;
  void*					retval3;
  void*					retval4;

  MainInitialize();
  MainProcessCommandLine(argc, argv);

  CANMonLogInit();
  CANMonLogWrite("%s starting\n", MainProgramName);
  VerifyCommandLine();
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
  if ( MainUseUI ) {
    UserInputThreadInit();
  }
  WebSocketServerInit();

  pthread_join(CANInterfaceThreadID, &retval1);
  if ( MainUseUI ) {
    pthread_join(UserInputThreadID, &retval2);
  }
  pthread_join(HTTPServerThreadID, &retval3);
  pthread_join(WebSocketServerThreadID, &retval4);
  return EXIT_SUCCESS;
}

/*****************************************************************************!
 * Function : VerifyCommandLine
 *****************************************************************************/
void
VerifyCommandLine
()
{

}


/*****************************************************************************!
 * Function : MainOpenDatabase
 *****************************************************************************/
void
MainOpenDatabase
()
{
  int					n;

  n = sqlite3_open(MainDatabaseName, &MainDatabase);
  if ( SQLITE_OK != n ) {
    fprintf(stderr, "Could not open database %s\n", MainDatabaseName);
    exit(EXIT_FAILURE);
  }
}

/*****************************************************************************!
 * Function : MainClearDatabase
 *****************************************************************************/
void
MainClearDatabase
()
{
  string				statement;
  char*					errormessage;

  statement = "DELETE from RegisterValues;";
  if ( SQLITE_OK != sqlite3_exec(MainDatabase, statement, NULL, NULL, &errormessage) ) {
    fprintf(stderr, "SQL Error : %s %s\n", statement, errormessage);
    sqlite3_free(errormessage);
  }
}

#include "MainProcessCommandLine.c"
#include "MainDisplayHelp.c"
#include "MainInitialize.c"
#include "MainExit.c"

