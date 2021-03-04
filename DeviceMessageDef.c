/*******************************************************************************
 * FILE         : DeviceMessageDef.c
 * DATE         : September 24 2018
 * PROJECT      : CanSim
 * COPYRIGHT    : Copyright (c) 2018 Vertiv Company
 *******************************************************************************/

/*******************************************************************************!
 * Global Headers
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

/*******************************************************************************!
 * Local Headers
 *******************************************************************************/
#include "DeviceMessageDef.h"
#include "MemoryManager.h"
#include "DefFileToken.h"
#include "ThreadSafePrint.h"
#include "DeviceDef.h"

#include "DeviceMessageDef/DeviceMessageResponseSetFromJSON.c"
#include "DeviceMessageDef/DeviceMessageDefListToJSON.c"
#include "DeviceMessageDef/DeviceMessageDefToJSON.c"
#include "DeviceMessageDef/DeviceMessageDefFromJSON.c"
#include "DeviceMessageDef/FindMessageDefByMessageType.c"
#include "DeviceMessageDef/GetDeviceMessageCount.c"
#include "DeviceMessageDef/AddDeviceMessageDef.c"
#include "DeviceMessageDef/DeviceMessageDefAddResponseType.c"
#include "DeviceMessageDef/CreateDeviceMessageDefList.c"
#include "DeviceMessageDef/DestroyDeviceMessageDeviceList.c"
#include "DeviceMessageDef/DumpDeviceMessageDefList.c"
#include "DeviceMessageDef/DumpDeviceMessageDefListShort.c"
#include "DeviceMessageDef/DumpDeviceMessageDefShort.c"
#include "DeviceMessageDef/DumpDeviceMessageDef.c"
#include "DeviceMessageDef/DestroyDeviceMessageDef.c"
#include "DeviceMessageDef/CreateDeviceMessageDef.c"
