/*****************************************************************************
 * FILE NAME    : greg.c
 * DATE         : August 20 2020
 * PROJECT      : Bay Simulator
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
#include <sys/stat.h>
#include <errno.h>
#include <json.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "String.h"
#include "MemoryManager.h"
#include "ascii.h"
#include "FileUtils.h"
#include "NumericTypes.h"
#include "CanMsg.h"

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
static string
mainFileName;

static DeviceDefList*
mainDevices;

static int
mainDeviceNameLen;

static int
mainRegNameLen;

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void
MainProcessLine
(FILE* InFile, int InLineNumber, string InLine);

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main(int argc, char**argv)
{
  int                                   i;
  unsigned char                         c;
  uint64_t                              filesize;
  struct stat                           statbuf;
  FILE*                                 file;
  int                                   lines, line;
  char                                  buffer[128];
  int                                   n;
  string                                base, suffix;
  string                                filename;
  FILE*                                 outFile;
  string                                deviceDefName;
  char*                                 jbuffer;
  int                                   bufferLen;
  json_settings                         settings;
  json_value*                           value;
  char                                  error[256];
  DeviceDef*                            deviceDef;
  char                                  s32[32];
  char                                  s32s[32];
  DeviceRegDef*                         deviceReg;

  n = 0;
  lines = 0;
  mainFileName = "CANMon.txt";
  deviceDefName = "DeviceDefs.json";
  
  base = FilenameExtractBase(mainFileName);
  suffix = FilenameExtractSuffix(mainFileName);
  GetFileBuffer(deviceDefName, &jbuffer, &bufferLen);
  memset(&settings, 0x00, sizeof(json_settings));
  value = json_parse_ex(&settings, jbuffer, bufferLen, error); 
  if ( NULL == value ) {
    fprintf(stderr, "Could not parse %s : %s\n", deviceDefName, error);
    exit(EXIT_FAILURE);
  }
  mainDeviceNameLen = 0;
  mainRegNameLen = 0;
  FreeMemory(jbuffer);
  mainDevices = DeviceDefListFromJSON(value);
  for ( deviceDef = mainDevices->defs; deviceDef; deviceDef = deviceDef->next ) {
    n = strlen(deviceDef->name);
    if ( mainDeviceNameLen < n ) {
       mainDeviceNameLen = n;
    }
    for ( deviceReg = deviceDef->regDefs->definitions; deviceReg; deviceReg = deviceReg->next ) {
      n = strlen(deviceReg->name);
      if ( mainRegNameLen < n ) {
        mainRegNameLen = n;
      }
    }
  }

  if ( base && suffix ) {
    filename = StringMultiConcat(base, "Parsed.", suffix, NULL);
  } else if ( base ) {
    filename = StringConcat("Parsed.", suffix);
  } else {
    filename = StringConcat(base, "Parsed");
  }

  outFile = fopen(filename, "wb");
  if ( NULL == outFile ) {
    fprintf(stderr, "Could not open %s : %s\n", filename, strerror(errno));
    exit(EXIT_FAILURE);
  }
  file = fopen(mainFileName, "rb");
  if ( NULL == file ) {
    fprintf(stderr, "Could not open %s : %s\n", mainFileName, strerror(errno));
    exit(EXIT_FAILURE);
  }
  stat(mainFileName, &statbuf);
  filesize = statbuf.st_size;

  
  printf(" File Size   : %11s Bytes\n", ConvertIntToCommaString(filesize, s32));

  for (i = 0; i < filesize; i++) {
        c = fgetc(file);
        if ( c == LF ) {
          lines++;
        }
  }
  fclose(file);
  line = 0;
  n = 0;
  file = fopen(mainFileName, "rb");
  for (i = 0; i < filesize; i++) {
    c = fgetc(file);
    buffer[n++] = c;
    if ( c == LF ) {
      buffer[n] = NUL;
      line++;
      MainProcessLine(outFile, line, buffer);
      printf("%11s of %11s Lines\r", ConvertIntToCommaString(line, s32), ConvertIntToCommaString(lines, s32s));
      fflush(stdout);
      n = 0;
    }
  }

  printf("Line Count     : %11s\n", ConvertIntToCommaString(lines, s32));
  fclose(file);
  fclose(outFile);
  exit(EXIT_SUCCESS);
}

/*****************************************************************************!
 * Function : MainProcessLine
 *****************************************************************************/
void
MainProcessLine
(FILE* InFile, int InLineNumber, string InLine)
{
  struct tm*                            ts;
  StringList*                           elements;
  frameid                               frame;
  dataframe                             data;
  time_t                                t;  
  bool                                  b;
  DeviceDef*                            deviceDef;
  char                                  protocolNumberString[8];
  char*                                 protocolNumberP;
  string                                t2;
  char*                                 regDefNameP;
  char                                  regDefName[8];
  DeviceRegDef*                         deviceReg;
  char                                  valueString[16];
  ufloatbit32_t                         dataValue;
  char                                  dstAddrString[5];
  char                                  srcAddrString[5];
  
  if ( InLine == NULL ) {
    return;
  }

  elements = StringSplit(InLine, " ", true);
  if ( NULL == elements || elements->stringCount != 3 ) {
    if ( elements ) {
      StringListDestroy(elements);
    }
    return;
  }

  frame.data32 = GetHex32ValueFromString(&b, elements->strings[0]);
  data.data64  = GetHex64ValueFromString(&b, elements->strings[1]);
  t2 = StringTrim(elements->strings[2]);
  t            = GetHex32ValueFromString(&b, t2);
  ts = localtime(&t);
  FreeMemory(t2); 

  deviceDef = FindDeviceDefByProtocol(mainDevices, frame.msgbit.ProtNo);
  dataValue.data32 = data.data.Value;
  if ( deviceDef ) {
    protocolNumberP = deviceDef->name;
    deviceReg = FindRegDefByValue(deviceDef->regDefs, data.data.ValueType);
    if ( deviceReg ) {
      regDefNameP = deviceReg->name;
      CANValueGetFromString(valueString, deviceReg, dataValue);
  } else {
      sprintf(regDefName, "%04x", data.data.ValueType);
      regDefNameP = regDefName;
      sprintf(valueString, "%08x", data.data.Value);
    }
  } else {
    sprintf(protocolNumberString, "%d", frame.msgbit.ProtNo);
    protocolNumberP = protocolNumberString;
    sprintf(regDefName, "%04x", data.data.ValueType);
    regDefNameP = regDefName;
    sprintf(valueString, "%08x", data.data.Value);
  }
  if ( frame.msgbit.SrcAddr == 240 ) {
    sprintf(srcAddrString, " NCU");
  } else {
    sprintf(srcAddrString, "  %02X", frame.msgbit.SrcAddr);
  }

  if ( frame.msgbit.DstAddr == 240 ) {
    sprintf(dstAddrString, " NCU");
  } if ( frame.msgbit.DstAddr == 255 ) {
    sprintf(dstAddrString, " BRD");
  } else {
    sprintf(dstAddrString, "  %02X", frame.msgbit.DstAddr);
  }
  fprintf(InFile, 
          "%8d  %02d/%02d/%04d %02d:%02d:%02d  %*s %s %s  %d  %3X %3X %*s %s\n", 
          InLineNumber, 
          ts->tm_mon + 1,
          ts->tm_mday, 
          ts->tm_year + 1900, 
          ts->tm_hour, 
          ts->tm_min, 
          ts->tm_sec,
          mainDeviceNameLen, 
          protocolNumberP,
          srcAddrString,
          dstAddrString,
          frame.msgbit.PTP, 
          data.data.ErrType, 
          data.data.MsgType, 
          mainRegNameLen,
          regDefNameP,
          valueString);
  StringListDestroy(elements);
}
