/*****************************************************************************
 * FILE NAME    : WebSocketIF.c
 * DATE         : March 27 2020
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
#include <pthread.h>
#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#include <json.h>
#include <StringUtils.h>
#include <MemoryManager.h>
#include <JSONIF.h>
#include <FileUtils.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WebSocketIF.h"
#include "main.h"
#include "Devices.h"
#include "ThreadSafePrint.h"
#include "CANInterfaceThread.h"
#include "CANMonLog.h"
#include "HTTPServerThread.h"
#include "DirManagement.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Imported Functions
 *****************************************************************************/
char*
strptime
(char*, char*, struct tm*);

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
int
WebSocketIFPacketID = 0;

pthread_t
WebSocketServerThreadID;

string
s_websocket_port = NULL;

string
WebSocketIFAddress = NULL;

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void
WebSocketIFHandlePacketRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
WebSocketIFHandleGetMonitorInfoRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
WebSocketIFHandleSetLimitsRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
HandleSetDateRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
HandleWebSocketRequest
(struct mg_connection* nc, struct mg_str InString);

void
WebSocketEventHandler
(struct mg_connection* nc, int ev, void* p);

void*
WebSocketServerThread
(void* InArgs);

void
HandleGetDeviceDefsRequest
(struct mg_connection* nc, json_value* InPacket);

void
HandleGetBaysRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
HandlePrepareDownloadRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
HandleToggleMonitorRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
WebSocketFrameResponseSend
(struct mg_connection* InConnection, string InResponseType,
 string InBody, int InPacketID, uint32_t InTime,
 string InResponseMessage);

void
WebSocketFrameSend
(struct mg_connection* InConnection, string InBuffer, uint16_t InBufferLen);

/*****************************************************************************!
 * Imported Functions
 *****************************************************************************/
char*
strptime
(char*, char*, struct tm*);

extern char*
get_current_dir_name
(void);

#include "WebSocketIF/WebSocketIFSetPort.c"
#include "WebSocketIF/WebSocketIFCreateInfoScript.c"
#include "WebSocketIF/HandlePrepareDownloadRequest.c"
#include "WebSocketIF/HandleGetLimitsRequest.c"
#include "WebSocketIF/WebSocketIFHandleSetTimeStampRequest.c"
#include "WebSocketIF/WebSocketFrameResponseSend.c"
#include "WebSocketIF/WebSocketFrameSend.c"
#include "WebSocketIF/WebSocketIFHandleSetLimitsRequest.c"
#include "WebSocketIF/WebSocketIFHandleGetMonitorInfoRequest.c"
#include "WebSocketIF/WebSocketIFHandlePacketRequest.c"
#include "WebSocketIF/WebSocketIFHandleRemoveArchiveFiles.c"
#include "WebSocketIF/WebSocketFrameResponseSendError.c"
#include "WebSocketIF/HandleToggleMonitorRequest.c"
#include "WebSocketIF/HandleSetBayRegValuesRequest.c"
#include "WebSocketIF/HandleWebSocketRequest.c"
#include "WebSocketIF/WebSocketEventHandler.c"
#include "WebSocketIF/WebSocketServerThread.c"
#include "WebSocketIF/WebSocketServerInit.c"
