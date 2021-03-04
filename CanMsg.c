/*****************************************************************************
 * FILE NAME    : CanMsg.c
 * DATE         : May 29 2020
 * PROJECT      : Bay Simulator
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

/*****************************************************************************!
 * Local Headers 
 *****************************************************************************/
#include "CanMsg.h"
#include "ThreadSafePrint.h"

/*****************************************************************************!
 * Exported Type : CanMessage
 *****************************************************************************/
typedef struct {
        int Protocol;
        int SrcAddr;
        int DestAddr;
        int MsgType;
        int ValueType;
        ufloatbit32_t Value;
} CanMessage;


/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
uint64_t
GetBits(uint64_t, int, int);

uint64_t GetProtocolBits( uint64_t Address) { return GetBits(Address, 28, 20); }
uint64_t GetPIPBits( uint64_t Address) { return GetBits(Address, 19, 19); }
uint64_t GetDestBits( uint64_t Address) { return GetBits(Address, 18, 11); }
uint64_t GetSrcBits( uint64_t Address) { return GetBits(Address, 10, 3); }
uint64_t GetContBits( uint64_t Address) { return GetBits(Address, 2, 2); }
uint64_t GetMsgTypeBits( uint64_t Data) { return GetBits(Data, 63, 56); }
uint64_t GetErrTypeBits( uint64_t Data) { return GetBits(Data, 55, 48); }
uint64_t GetValTypeBits( uint64_t Data) { return GetBits(Data, 47, 32); }
uint64_t GetValBits( uint64_t Data) { return GetBits(Data, 31, 0); } 

#include "CanMsg/CANValueGetFromString.c"
#include "CanMsg/CanRegGetFromString.c"
#include "CanMsg/CanRegSetFromString.c"
#include "CanMsg/ParseData.c"
#include "CanMsg/ParseId.c"
#include "CanMsg/GetDataFrame.c"
#include "CanMsg/GetFrameId.c"
#include "CanMsg/GetBitsI.c"
#include "CanMsg/GetBits.c"
