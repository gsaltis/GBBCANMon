/*******************************************************************************
 * FILE         : DirManagement.c
 * DATE         : September 26 2018
 * PROJECT      : GBB CAN Simulator
 * COPYRIGHT    : Copyright (c) 2018 Vertiv Company
 *******************************************************************************/
 
/*******************************************************************************!
 * Global Headers
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

/*******************************************************************************!
 * Local Headers
 *******************************************************************************/
#include "DirManagement.h"
#include "MemoryManager.h"
#include "CANMonLog.h"

/*******************************************************************************!
 * Local Data
 *******************************************************************************/
string
DMBaseDirectoryName;

static const char*
DMDeviceDefsFileName = "devicedefs.txt";

static const char*
DMDeviceDataFileName = "devices.db";

static const char*
DMDeviceProtocolFileName = "protocols.txt";

uint16_t
DMMinFileLength;

char
DirManagementDirSepChar = '/';

string
DirManagementDirSepString = "/";

string
DirManagementWebDirName = "www";

/*******************************************************************************!
 * Local Functions
 *******************************************************************************/
static char*
DMGetFileName
(char* InReturnFileName, const char* InFileName, uint16_t InMaxFileNameLength);

#include "DirManagement/DirManagementGetInstallDir.c"
#include "DirManagement/DirManagementSetInstallDir.c"
#include "DirManagement/DMGetFileName.c"
#include "DirManagement/GetDeviceProtocolFileName.c"
#include "DirManagement/GetDeviceDataFileName.c"
#include "DirManagement/GetDeviceDefsFileName.c"
#include "DirManagement/DirManagementInitialize.c"
#include "DirManagement/DirManagementLog.c"
#include "DirManagement/DirManagementGetWebDir.c"
