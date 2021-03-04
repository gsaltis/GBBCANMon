/*****************************************************************************
 * FILE NAME    : WebSocketIF.h
 * DATE         : March 27 2020
 * PROJECT      : Bay Simulator
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/
#ifndef _websocketif_h_
#define _websocketif_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <mongoose.h>
#include <StringUtils.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "Messages.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define WEBSOCKET_IF_MAX_ADDRESS_TRIES      12
#define WEBSOCKET_IF_ADDRESS_WAIT_PERIOD    5

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/
extern pthread_t
WebSocketServerThreadID;

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/
void
WebSocketIFHandleRemoveArchiveFiles
(struct mg_connection* InConnection, json_value* InPacket);

void
HandleGetLimitsRequest
(struct mg_connection* InConnection, json_value* InPacket);

void
WebSocketServerInit();


void
WebSocketIFRemoveBay
(int InBayIndex);


void
WebSocketIFCreateInfoScript
();

void
WebSocketIFSetPort
(string InPortNumber);

#endif /* _websocketif_h_*/
