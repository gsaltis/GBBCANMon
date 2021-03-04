/*******************************************************************************
 * FILE                : main.h
 * DATE                : September 26 2018
 * COPYRIGHT       : Copyright (c) 2018 Vertiv Company
 *******************************************************************************/
#ifndef _main_h_
#define _main_h_

/*******************************************************************************!
 * Global Headers
 *******************************************************************************/
#include <stdbool.h>
#include <mongoose.h>
#include <sqlite3.h>

/*******************************************************************************!
 * Local Headers
 *******************************************************************************/
#include "DeviceDef.h"
#include "CANInterface.h"

/*******************************************************************************!
 * Local Data
 *******************************************************************************/
extern bool
MainUseUI;

extern DeviceDefList*
mainDeviceDefs;

extern string
MainVersionNumber;

extern bool
MainVerbose;

extern struct mg_serve_http_opts
s_http_server_opts;

extern int
MainMinLimitCount;

extern int
MainMaxLimitCount;

extern int
MainMinLimitSize;

extern int
MainMaxLimitSize;

extern int
MainMinLimitHours;

extern int
MainMaxLimitHours;

extern int
MainMinLimitDays;

extern int
MainMaxLimitDays;

extern bool
MainMonitorWebRequest;

extern sqlite3*
MainDatabase;

extern CANInterface*
MainCANInterface;

extern time_t
MainStartTime;

extern time_t
MainTimeStampTime;

extern string
MainLimitType;

extern int
MainLimitHours;

extern int
MainLimitSize;

extern int
MainLimitCount;

extern int
MainLimitDays;

extern int
MainLimitDaysRuntime;

extern int
MainLimitHoursRuntime;

extern int
MainLimitCountRuntime;

extern int
MainLimitSizeRuntime;

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/
void
MainInitializeStartTime
();

void
MainDisplayVersion
();

bool
MainLimitSet
(string InType, int InValue);

#endif
