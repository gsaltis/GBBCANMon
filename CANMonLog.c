/*****************************************************************************
 * FILE NAME    : CANMonLog.c
 * DATE         : August 08 2020
 * PROJECT      : GBB CAN Monitor
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
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "String.h"
#include "FileUtils.h"
#include "MemoryManager.h"
#include "CANMonLog.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
string
CANMonLogFilename = NULL;

pthread_mutex_t
CANMonLogMutex;

FILE*
CANMonLogFile;

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/

#include "CANMonLogInit.c"
#include "CANMonLogWrite.c"
#include "CANMonLogSetFilename.c"
