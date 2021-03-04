/*******************************************************************************
 * FILE         : DeviceDef.c
 * DATE         : September 24 2018
 * PROJECT      : CanSim
 * COPYRIGHT    : Copyright (c) 2018 Vertiv Company
 *******************************************************************************/
 
/*******************************************************************************!
 * Local Headers
 *******************************************************************************/
#include "DeviceDef.h"
#include "DirManagement.h"
#include "MemoryManager.h"
#include "DefFileToken.h"
#include "ThreadSafePrint.h"

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
static void
DeviceDefResolveResponseDefs
(DeviceDef* InDeviceDef);

#include "DeviceDef/FindDeviceDefByProtocol.c"
#include "DeviceDef/FindRegDefByValueType.c"
#include "DeviceDef/DeviceDefFindRegByValueType.c"
#include "DeviceDef/DeviceDefFindMessageByType.c"
#include "DeviceDef/DeviceDefErrorCodeToString.c"
#include "DeviceDef/DeviceDefGetMessageCount.c"
#include "DeviceDef/DeviceDefGetRegCount.c"
#include "DeviceDef/FindDeviceDef.c"
#include "DeviceDef/RemoveDeviceDefByName.c"
#include "DeviceDef/RemoveDeviceDef.c"
#include "DeviceDef/AddDeviceDef.c"
#include "DeviceDef/DestroyDeviceDefList.c"
#include "DeviceDef/DeviceDefListAppendDef.c"
#include "DeviceDef/DeviceDefResolveResponseDefs.c"
#include "DeviceDef/DeviceDefListToJSON.c"
#include "DeviceDef/DeviceDefToJSON.c"
#include "DeviceDef/DeviceDefFromJSON.c"
#include "DeviceDef/DeviceDefListFromJSON.c"
#include "DeviceDef/DumpDeviceDefList.c"
#include "DeviceDef/CreateDeviceDefList.c"
#include "DeviceDef/DumpDeviceDef.c"
#include "DeviceDef/DumpDeviceDefShort.c"
#include "DeviceDef/DestroyDeviceDef.c"
#include "DeviceDef/CreateNewDeviceDef.c"
#include "DeviceDef/CreateDeviceDef.c"
