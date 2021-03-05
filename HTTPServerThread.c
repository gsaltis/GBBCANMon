/*****************************************************************************
 * FILE NAME    : HTTPServerThread.c
 * DATE         : April 09 2020
 * PROJECT      : Bay Simulator
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
#include <unistd.h>
#include <mongoose.h>
#include <StringUtils.h>
#include <MemoryManager.h>
#include <FileUtils.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "HTTPServerThread.h"
#include "main.h"
#include "DirManagement.h"
#include "CANMonLog.h"
#include "CANInterfaceThread.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
pthread_t
HTTPServerThreadID;

static const char *
s_http_port = "8001";

string
HTTPWWWBaseDir = "www";

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
static void*
HTTPServerThread
(void* InArgs);

void
HTTPEventHandler
(struct mg_connection* nc, int ev, void* p);

/*****************************************************************************!
 * Imported Functions
 *****************************************************************************/
extern char*
get_current_dir_name
(void);

#include "HTTPServerThread/HTTPEventHandler.c"
#include "HTTPServerThread/HTTPServerThread.c"
#include "HTTPServerThread/HTTPServerThreadInit.c"
