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
#include <mongoose.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "HTTPServerThread.h"
#include "main.h"
#include "String.h"
#include "MemoryManager.h"
#include "DirManagement.h"
#include "CANMonLog.h"
#include "FileUtils.h"
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
 * Function : HTTPServerThreadInit
 *****************************************************************************/
void
HTTPServerThreadInit
()
{
  pthread_create(&HTTPServerThreadID, NULL, HTTPServerThread, NULL);
}

/*****************************************************************************!
 * Function : HTTPServerThread
 *****************************************************************************/
void*
HTTPServerThread
(void* InArgs)
{
  struct mg_connection *              nc;
  struct mg_mgr                       mgr;
  string                                locationName;

  CANMonLogWrite("Starting server thread on port %s\n", s_http_port);
  CANMonLogWrite("Starting mongoose\n");
  mg_mgr_init(&mgr, NULL);
  CANMonLogWrite("Mongoose started\n");
  nc = mg_bind(&mgr, s_http_port, HTTPEventHandler);
  if (nc == NULL) {
    CANMonLogWrite("Failed to create http listener\n");
    return (void*)1;
  }
  mg_set_protocol_http_websocket(nc);
  locationName = DirManagementGetInstallDir();
  locationName = StringConcatTo(locationName, HTTPWWWBaseDir);
  CANMonLogWrite("HTTP WWW Directory : %s\n", locationName); 
  s_http_server_opts.document_root = locationName;
  s_http_server_opts.enable_directory_listing = "no";

  for (;;) {
    mg_mgr_poll(&mgr, 20);            
  }
}

#include "HTTPEventHandler.c"


