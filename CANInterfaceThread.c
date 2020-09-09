/*****************************************************************************
 * FILE NAME    : CANInterfaceThread.c
 * DATE         : July 14 2020
 * PROJECT      : CAN Monitor
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
#include <sqlite3.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <utime.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "CANInterface.h"
#include "CANInterfaceThread.h"
#include "main.h"
#include "CanMsg.h"
#include "BytesManage.h"
#include "CANMonLog.h"
#include "FileUtils.h"
#include "DirManagement.h"
#include "MemoryManager.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
pthread_t
CANInterfaceThreadID;

FILE*
CANInterfaceOutputFile = NULL;

string
CANInterfaceOutputFilename = "CANMon.txt";

uint32_t
CANInterfaceMessagesCount = 0;

bool
CANInterfaceMonitor = true;

int
CANInterfaceThreadMaxArchiveFiles = 4;

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void*
CANInterfaceThread
(void* InArg);

static
void
CANInterfaceThreadHandleRequest
(CANInterface* InInterface, frameid InID, dataframe InData, time_t InTime);

/*****************************************************************************!
 * Function : CANInterfaceThreadInit
 *****************************************************************************/
void
CANInterfaceThreadInit
()
{
  string				installDir;

  installDir = DirManagementGetInstallDir();
  CANInterfaceThreadManageArchives(CANInterfaceOutputFilename);
  CANInterfaceOutputFile = FileUtilsOpen(installDir, CANInterfaceOutputFilename, "wb");
  FreeMemory(installDir);
  if ( CANInterfaceOutputFile == NULL ) {
    CANMonLogWrite("Could not open %s\n", CANInterfaceOutputFilename);
  }
	 
  pthread_create(&CANInterfaceThreadID, NULL, CANInterfaceThread, NULL);
}

/*****************************************************************************!
 * Function : CANInterfaceThread
 *****************************************************************************/
void*
CANInterfaceThread
(void* InArg)
{
  CANMonLogWrite("CAN Interface Thread Started\n");

  while (true)
  {
    uint32_t				id;
    uint64_t				data;
    uint8_t				dataLength;
    uint8_t 				result;
    time_t				t;

    result = CANInterfaceRead(MainCANInterface, &id, &data, &dataLength);
    switch ( result ) {
      case CAN_READ_TIMEOUT : {
        break;
      }
      case CAN_READ_OK : {
        frameid fid;
        fid.data32 = id;
        dataframe df;
        df.data64 = ByteManageSwap8(data);
        if ( CANInterfaceMonitor ) {
	  if ( !CANInterfaceThreadThrottleFile() ) {
	    t = time(NULL) - MainStartTime;
    	    CANInterfaceThreadHandleRequest(MainCANInterface, fid, df, MainTimeStampTime + t);
            CANInterfaceMessagesCount++;
          }
        }
	break;
      }
      case CAN_READ_ERROR : {
	break;
      }
      default : {
	break;
      }
    }
  }
}

/*****************************************************************************!
 * Function : CANInterfaceMonitorStop
 *****************************************************************************/
void
CANInterfaceMonitorStop
()
{
  CANInterfaceMonitor = false;
}

/*****************************************************************************!
 * Function : CANInterfaceMonitorStart
 *****************************************************************************/
void
CANInterfaceMonitorStart
()
{
  CANInterfaceMonitor = true;
}

/*****************************************************************************!
 * Function : CANInterfaceFileOpen
 *****************************************************************************/
void
CANInterfaceFileOpen
(bool InAppendFile)
{
  string				installDir;

  installDir = DirManagementGetInstallDir();
  do
  {
    if ( CANInterfaceOutputFile ) {
      if ( InAppendFile ) {
        return;
      }
      fclose(CANInterfaceOutputFile);
      CANInterfaceOutputFile = FileUtilsOpen(installDir, CANInterfaceOutputFilename, "wb");
      if ( NULL == CANInterfaceOutputFile ) {
        fprintf(stderr, "Could not open %s\n", CANInterfaceOutputFilename);
	break;
      }
    }
    if ( InAppendFile ) {
      CANInterfaceOutputFile = FileUtilsOpen(installDir, CANInterfaceOutputFilename, "ab");
      if ( NULL == CANInterfaceOutputFile ) {
        fprintf(stderr, "Could not open %s\n", CANInterfaceOutputFilename);
        break;
      }
    }
  } while (false);
  FreeMemory(installDir);
}

/*****************************************************************************!
 * Function : CANInterfaceFileClose
 *****************************************************************************/
void
CANInterfaceFileClose
()
{
  if ( CANInterfaceOutputFile ) {
    fclose(CANInterfaceOutputFile);
    CANInterfaceOutputFile = NULL;
  }
}
#include "CANInterfaceThreadManageArchives.c"
#include "CANInterfaceThreadGetArchivedFilenames.c"
#include "CANInterfaceThreadCreateArchive.c"
#include "CANInterfaceThreadThrottleFile.c"
#include "CANInterfaceThreadHandleRequest.c"
