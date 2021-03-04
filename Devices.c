/*****************************************************************************
 FILE NAME      : Devices.c
 DATE           : October 01 2018
 PROJECT        : 
 COPYRIGHT      : Copyright (C) 2018 by Gregory R Saltis
******************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#define _GNU_SOURCE
#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <MemoryManager.h>
#include <StringUtils.h>
#include <BytesManage.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CanMsg.h"
#include "CANInterface.h"
#include "ThreadSafePrint.h"
#include "UserInputThread.h"
#include "Devices.h"
#include "DeviceDef.h"
#include "main.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define Upcase(s) {int i; for (i = 0; (s[i] != '\0' && s[i] != '\n'); i++) { s[i] = toupper(s[i]); } s[i] = '\0';}
#define ColorRed "\e[1;31m" 
#define ColorWhite "\e[0m"
#define ColorGreen "\e[32m"

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
CanDevice CanDeviceList[MAXDEVICES];
int NumDevices = 0;

int GetNumDevice() { return NumDevices; }
CanDevice* GetCanDevice() { return &CanDeviceList[0]; }

#include "Devices/FindRegisterByIndexGroup.c"
#include "Devices/GetDeviceNumbersString.c"
#include "Devices/DeviceFindRegister.c"
#include "Devices/GetNextDevice.c"
#include "Devices/GetFirstDevice.c"
#include "Devices/GetDeviceTypeCount.c"
#include "Devices/HandleCanTraffic.c"
#include "Devices/HandleReguest.c"
#include "Devices/GetRegisterByDef.c"
#include "Devices/GetRegisterByName.c"
#include "Devices/SendResponses.c"
#include "Devices/GetRequestBreakdown.c"
#include "Devices/DisableDevice.c"
#include "Devices/EnableDevice.c"
#include "Devices/AddDevice.c"
#include "Devices/AddSingleDevice.c"
#include "Devices/FindCANDeviceByDefNameAddress.c"
#include "Devices/CreateDevice.c"
#include "Devices/AddCANDevice.c"
#include "Devices/CopyDevice.c"
#include "Devices/ClearDevice.c"
#include "Devices/RemoveDevice.c"
#include "Devices/SetRegisterValueFlat.c"
#include "Devices/SetRegisterValueHex.c"
#include "Devices/SetRegisterValue.c"
#include "Devices/GetDeviceRegisterFloat.c"
#include "Devices/SetDeviceRegister.c"
#include "Devices/SetRegisterValueByName.c"
#include "Devices/DumpGroup.c"
#include "Devices/ClearDeviceRegisters.c"
#include "Devices/DumpDevice.c"
#include "Devices/FindDevice.c"
#include "Devices/DumpDefs.c"
#include "Devices/HandleShowMessages.c"
#include "Devices/DisplayDeviceDefMessages.c"
#include "Devices/GetGroupAndAbbrev.c"
#include "Devices/GetRegisterByGroup.c"
#include "Devices/GetAbbrevList.c"
#include "Devices/GetGroupList.c"
#include "Devices/GetDeviceCount.c"
#include "Devices/GetDeviceList.c"
#include "Devices/GetCanDeviceDefByName.c"
#include "Devices/GetGroupArray.c"
