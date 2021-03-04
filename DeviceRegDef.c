/*******************************************************************************
 * FILE         : DeviceRegDef.c
 * DATE         : September 24 2018
 * PROJECT      : CanSim
 * COPYRIGHT    : Copyright (c) 2018 Vertiv Company
 *******************************************************************************/

/*******************************************************************************!
 * Global Headers
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <NumericTypes.h>
#include <MemoryManager.h>
#include <StringUtils.h>

/*******************************************************************************!
 * Local Headers
 *******************************************************************************/
#include "DeviceRegDef.h"
#include "DefFileToken.h"
#include "ThreadSafePrint.h"

/*******************************************************************************!
 * Local Macros
 *******************************************************************************/
#define REG_DEF_READ_END_STATE      7

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
static int
DeviceRegDefCompareByName
(const void* InPointer1, const void* InPointer2);

static int
DeviceRegDefCompareByGroupName
(const void* InPointer1, const void* InPointer2);

static int
DeviceRegDefCompareByNumber
(const void* InPointer1, const void* InPointer2);

#include "DeviceRegDef/DeviceRegDefToJSON.c"
#include "DeviceRegDef/DeviceRegDefListToJSON.c"
#include "DeviceRegDef/DeviceRegDefFromJSON.c"
#include "DeviceRegDef/DeviceRegDefCompareByNumber.c"
#include "DeviceRegDef/DeviceRegDefCompareByGroupName.c"
#include "DeviceRegDef/DeviceRegDefCompareByName.c"
#include "DeviceRegDef/GetDeviceRegCount.c"
#include "DeviceRegDef/AddDeviceRegDef.c"
#include "DeviceRegDef/FindRegDefByValue.c"
#include "DeviceRegDef/FindRegDefByName.c"
#include "DeviceRegDef/CreateDeviceRegDefList.c"
#include "DeviceRegDef/CreateDeviceRegDef.c"
#include "DeviceRegDef/DestroyDeviceRegDef.c"
#include "DeviceRegDef/DumpDeviceRegDefShort.c"
#include "DeviceRegDef/DumpDeviceRegDef.c"
#include "DeviceRegDef/DumpDeviceRegDefList.c"
#include "DeviceRegDef/DumpDeviceRegDefListShort.c"
#include "DeviceRegDef/ReadDeviceReg.c"
#include "DeviceRegDef/DestroyDeviceRegList.c"
#include "DeviceRegDef/ReadDeviceRegsList.c"
