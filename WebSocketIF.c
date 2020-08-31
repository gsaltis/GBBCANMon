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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "WebSocketIF.h"
#include "main.h"
#include "json.h"
#include "String.h"
#include "MemoryManager.h"
#include "JSONIF.h"
#include "FileUtils.h"
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
HandleGetMonitorInfoRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
HandlePacketRequest
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
 * Function : WebSocketServerInit
 *****************************************************************************/
void
WebSocketServerInit()
{
  pthread_create(&WebSocketServerThreadID, NULL, WebSocketServerThread, NULL);
}

/*****************************************************************************!
 * Function : WebSocketServerThread
 *****************************************************************************/
void*
WebSocketServerThread
(void* InArgs)
{
  struct mg_connection *              nc;
  struct mg_mgr                       mgr;
  CANMonLogWrite("Starting websocket server thread on port %s\n", s_websocket_port);
  mg_mgr_init(&mgr, NULL);

  nc = mg_bind(&mgr, s_websocket_port, WebSocketEventHandler);
  if (nc == NULL) {
    CANMonLogWrite("Failed to create webssocket listener\n");
    return (void*)1;
  }
  mg_set_protocol_http_websocket(nc);

  for (;;) {
    mg_mgr_poll(&mgr, 20);
  }
}

/*****************************************************************************!
 * Function : WebSocketEventHandler
 *****************************************************************************/
void
WebSocketEventHandler
(struct mg_connection* nc, int ev, void* p)
{
  if ( ev == 0 ) {
    return;
  }
  switch (ev) {
    case MG_EV_CLOSE : {
      break;
    }

    case MG_EV_WEBSOCKET_FRAME: {
      struct websocket_message *wm = (struct websocket_message *) p;
      struct mg_str d = {(char *) wm->data, wm->size};
      HandleWebSocketRequest(nc, d);
      break;
    }
  }
}

/*****************************************************************************!
 * Function : HandleWebSocketRequest
 *****************************************************************************/
void
HandleWebSocketRequest
(struct mg_connection* nc, struct mg_str InMessage)
{
  string                                packettype;
  json_value*                           jsonDoc;

  jsonDoc = json_parse((const json_char*)InMessage.p, (size_t)InMessage.len);

  packettype = JSONIFGetString(jsonDoc, "packettype");

  if ( NULL == packettype ) {
    json_value_free(jsonDoc);
    return;
  }

  if ( StringEqual("request", packettype) ) {
    HandlePacketRequest(nc, jsonDoc);
  } else if ( StringEqual("response", packettype) ) {
 
  } else if ( StringEqual("push", packettype) ) {
 
  }
  FreeMemory(packettype);
  json_value_free(jsonDoc);
}

/*****************************************************************************!
 * Function : HandlePacketRequest
 *****************************************************************************/
void
HandlePacketRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  string                                requesttype;
  if ( NULL == InPacket ) {
    return;
  }
 
  requesttype = JSONIFGetString(InPacket, "type");
  if ( NULL == requesttype ) {
    return;
  }

  if ( StringEqual("getmonitorinfo", requesttype) ) {
    HandleGetMonitorInfoRequest(InConnection, InPacket);
  } else if ( StringEqual("preparedownloadfilename", requesttype) ) {
    HandlePrepareDownloadRequest(InConnection, InPacket);
  } else if ( StringEqual("monitortoggle", requesttype) ) {
    HandleToggleMonitorRequest(InConnection, InPacket);
  } else if ( StringEqual("getbays", requesttype) ){
    HandleGetBaysRequest(InConnection, InPacket);
  } else if ( StringEqual("getlimits", requesttype) ) {
	HandleGetLimitsRequest(InConnection, InPacket);
  } else if ( StringEqual("setdate", requesttype) ) {
	HandleSetDateRequest(InConnection, InPacket);
  }
 
  FreeMemory(requesttype);
}

/*****************************************************************************!
 * Function : HandleSetBayRegValuesRequest
 *****************************************************************************/
void
HandleGetBaysRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
}

/*****************************************************************************!
 * Function : HandleToggleMonitorRequest
 *****************************************************************************/
void
HandleToggleMonitorRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  int					packetid;
  string				s;

  if ( CANInterfaceMonitor ) {
    CANInterfaceMonitorStop();
  } else {
    CANInterfaceMonitorStart();
  }
  packetid = JSONIFGetInt(InPacket, "packetid");
  s = StringCopy("{\n");
  s = StringConcatTo(s, "  \"monitorstatus\" : ");
  s = StringConcatTo(s, CANInterfaceMonitor ? "true" : "false");
  s = StringConcatTo(s, "}\n");
  WebSocketFrameResponseSend(InConnection, "restogglemonitor", s, packetid, 0, "");
  FreeMemory(s);
}

/*****************************************************************************!
 * Function : HandleGetMonitorInfoRequest
 *****************************************************************************/
void
HandleGetMonitorInfoRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  string				s;
  int					packetid;
  char					s2[32];
  struct tm*				t;
 
  packetid = JSONIFGetInt(InPacket, "packetid");
  s = StringCopy("{  \"monitorinfo\" :  { ");
  s = StringConcatTo(s, "    \"messagecount\" : ");
  sprintf(s2, "%d,\n",  CANInterfaceMessagesCount);
  s = StringConcatTo(s, s2);

  s = StringConcatTo(s, "    \"monitorstatus\" : ");
  sprintf(s2, "%s,\n", CANInterfaceMonitor ? "true" : "false");
  s = StringConcatTo(s, s2);

  s = StringConcatTo(s, "   \"monitorstarttime\" : \"");
  t = localtime(&MainStartTime);
  sprintf(s2, "%02d/%02d/%04d %02d:%02d:%02d\", \n", t->tm_mon + 1, t->tm_mday, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);
  s = StringConcatTo(s, s2);

  s = StringConcatTo(s, "    \"monitorfilename\" : \"");
  s = StringConcatTo(s, CANInterfaceOutputFilename);
  s = StringConcatTo(s, "\"\n");
 
  s = StringConcatTo(s, "  }\n");
  s = StringConcatTo(s, "}\n");

  WebSocketFrameResponseSend(InConnection, "resmonitorinfo", s, packetid, 0, "");
  FreeMemory(s);
}

/*****************************************************************************!
 * Function : WebSocketFrameResponseSendError
 *****************************************************************************/
void
WebSocketFrameResponseSendError
(struct mg_connection* InConnection, string InResponseType,
 string InBody, int InPacketID, uint32_t InTime,
 string InResponseCode, string InResponseMessage)
{
  string                                responseString;
  char                                  s[16];

  responseString = StringCopy("{\n");

  responseString = StringConcatTo(responseString, "\"type\" : \"");
  responseString = StringConcatTo(responseString, InResponseType);
  responseString = StringConcatTo(responseString, "\",\n");

  responseString = StringConcatTo(responseString, "\"body\" : ");
  responseString = StringConcatTo(responseString, InBody);
  responseString = StringConcatTo(responseString, ",\n");

  responseString = StringConcatTo(responseString, "\"packettype\" : \"response\",\n");

  sprintf(s, "%d", InPacketID);
  responseString = StringConcatTo(responseString, "\"packetid\" : ");
  responseString = StringConcatTo(responseString, s);
  responseString = StringConcatTo(responseString, ",\n");

  sprintf(s, "%d", InTime);
  responseString = StringConcatTo(responseString, "\"time\" : ");
  responseString = StringConcatTo(responseString, s);
  responseString = StringConcatTo(responseString, ",\n");

  responseString = StringConcatTo(responseString, "\"responseid\" : \"");
  responseString = StringConcatTo(responseString, InResponseCode);
  responseString = StringConcatTo(responseString, "\",\n");

  responseString = StringConcatTo(responseString, "\"responsemessage\" : \"");
  responseString = StringConcatTo(responseString, InResponseMessage);
  responseString = StringConcatTo(responseString, "\"\n");

  responseString = StringConcatTo(responseString, "}\n");
  WebSocketFrameSend(InConnection, responseString, strlen(responseString));
  FreeMemory(responseString);
}


#include "WebSocketIFSetPort.c"
#include "WebSocketIFCreateInfoScript.c"
#include "HandlePrepareDownloadRequest.c"

#include "HandleGetLimitsRequest.c"
#include "HandleSetDateRequest.c"
#include "WebSocketFrameResponseSend.c"
#include "WebSocketFrameSend.c"
