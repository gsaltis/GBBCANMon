/******************************************************************************!
 * FILE         : CANInterface.c
 * PROJECT      : Bay Simulator
 * FILE DATE    : June 20 2019
 ******************************************************************************/

/******************************************************************************!
 * Global Headers
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#ifdef NEED_NET_IF_H
#include <net/if.h>
#endif
#ifdef NEED_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif
#ifdef NEED_LINUX_CAN_H
#include <linux/can.h>
#endif
#ifdef NEED_LINUX_CAN_RAW_H
#include <linux/can/raw.h>
#endif

#include <fcntl.h>
#ifdef NEED_TERMIO_H
#include <termio.h>
#endif
#include <unistd.h>
#include <StringUtils.h>
#include <MemoryManager.h>
#include <BytesManage.h>

/******************************************************************************!
 * Local Headers
 ******************************************************************************/
#include "CANInterface.h"
#include "CLIThread.h"
#include "ThreadSafePrint.h"
#include "Devices.h"
#include "main.h"

/******************************************************************************!
 * Local Macros
 ******************************************************************************/
#define CAN_DEFAULT_TIMEOUT   1

/******************************************************************************!
 * Local Functions
 ******************************************************************************/
static uint8_t
CANInterfaceReadTimeout
(CANInterface* InInterface, uint32_t* InID, uint64_t* InData, uint8_t* InDataLength, uint8_t InTimeout);

/******************************************************************************!
 * Local Data
 ******************************************************************************/
bool
CANMonitorInput = false;

#include "CANInterface/CANInterfaceReset.c"
#include "CANInterface/CANInterfaceTransaction.c"
#include "CANInterface/CANInterfaceReadTimeout.c"
#include "CANInterface/CANInterfaceRead.c"
#include "CANInterface/CANInterfaceWrite.c"
#include "CANInterface/CANInterfaceClose.c"
#include "CANInterface/CANInterfaceInit.c"
