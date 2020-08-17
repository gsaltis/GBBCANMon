/*****************************************************************************
 * FILE NAME    : canmonview.c
 * DATE         : July 21 2020
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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "String.h"
#include "CanMsg.h"
#include "MemoryManager.h"
#include "ANSIColors.h"
#include "FileUtils.h"
#include "NumericTypes.h"

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
string
mainFilename;

StringList*
mainFileLines;

bool
mainVerbose = false;

/*****************************************************************************!
 * Local Functions
 *****************************************************************************/
void
MainInitialize
();

void
MainProcessCommandLine
(int argc, char** argv);

void
MainVerifyCommandLine
();

void
MainReadFileLines
();

void
MainProcessFileLines
();

void
MainTerminate
();

void
MainDisplayHelp
();

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  MainInitialize();
  MainProcessCommandLine(argc, argv);
  MainVerifyCommandLine();
  MainReadFileLines();
  MainProcessFileLines();
  MainTerminate();
 
  exit(EXIT_SUCCESS);
}

/*****************************************************************************!
 * Function : MainInitialize
 *****************************************************************************/
void
MainInitialize
()
{
  mainFilename = NULL;
  mainFileLines = NULL;
}

/*****************************************************************************!
 * Function : MainProcessCommandLine
 *****************************************************************************/
void
MainProcessCommandLine
(int argc, char** argv)
{
  int					i;
  string				command;

  for ( i = 1 ; i < argc; i++ ) {
    command = argv[i];
    
    if ( StringEqualsOneOf(command, "-f", "--file", NULL) ) {
      i++;
      if ( i == argc ) {
        fprintf(stderr, "%s is missing a filename\n", command);
        MainDisplayHelp();
        exit(EXIT_FAILURE);
      }
      if ( mainFilename ) {
        FreeMemory(mainFilename);
      }
      mainFilename = StringCopy(argv[i]);
      continue;
    }
    
    if ( StringEqualsOneOf(command, "-v", "--verbose", NULL) ) {
      mainVerbose = true;
      continue;
    }

    if ( StringEqualsOneOf(command, "-h", "--help", NULL) ) {
      MainDisplayHelp();
      exit(EXIT_SUCCESS);
    }

    if ( command[0] == '-' ) {
      fprintf(stderr, "%s is an invalid command\n", command);
      MainDisplayHelp();
      exit(EXIT_FAILURE);
    }
  }
}

/*****************************************************************************!
 * Function : MainVerifyCommandLine
 *****************************************************************************/
void
MainVerifyCommandLine
()
{
  if ( mainFilename == NULL ) {
    fprintf(stderr, "A filename is required\n");
    MainDisplayHelp();
    exit(EXIT_FAILURE);
  }

  if ( !FileExists(mainFilename) ) {
    fprintf(stderr, "%s does not exist\n", mainFilename);
    MainDisplayHelp();
    exit(EXIT_FAILURE);
  }
}

/*****************************************************************************!
 * Function : MainReadFileLines
 *****************************************************************************/
void
MainReadFileLines
()
{
  char*					buffer;
  int					bufferLen;
  char**				lines;
  int					linesCount;
  int					i;

  if ( mainVerbose ) {
    fprintf(stdout, "%sRead file%s\n", ColorYellow, ColorReset);
  }
  if ( !GetFileBuffer(mainFilename, &buffer, &bufferLen) ) {
    fprintf(stderr, "%sCould not read %s%s\n", ColorBoldRed, mainFilename, ColorReset);
    exit(EXIT_FAILURE);
  }

  if ( mainVerbose ) {
    fprintf(stdout, "%sReading File Lines%s\n", ColorYellow, ColorReset);
  }
  GetFileLines(buffer, bufferLen, &lines, &linesCount);
  mainFileLines = StringListCreate();

  for ( i = 0 ; i < linesCount ; i++ ) {
    if ( mainVerbose ) {
      fprintf(stdout, "%sReading Line %7d of %d%s\r", ColorYellow, i+1, linesCount, ColorReset);
      fflush(stdout);
    }
    StringListAppend(mainFileLines, lines[i]);
  }
  
  if ( mainVerbose ) {
    fprintf(stdout, "\n%sFile Lines Read%s\n", ColorBrightGreen, ColorReset);
  }
  FreeMemory(buffer);
  FreeMemory(lines);
}

/*****************************************************************************!
 * Function : MainProcessFileLines
 *****************************************************************************/
void
MainProcessFileLines
()
{
  int					i;
  string				line;
  StringList*				lineParts;
  frameid				fid;
  dataframe				data;
  uint32_t				n;
  int					protocol, sourceAddress, destAddress;
  int					valueType, messageType, errorType;
  ufloatbit32_t				value;
  bool					b;
 
  printf("Protocol  Source  Destination  Message Type  Value Type      Data\n"); 
  for ( i = 0 ; i < mainFileLines-> stringCount ; i++ ) {
    line = mainFileLines->strings[i];
    lineParts = StringSplit(line, " ", true);
    if ( lineParts->stringCount != 3 ) {
      StringListDestroy(lineParts);
      continue;
    }
    n = GetHex32ValueFromString(&b, lineParts->strings[0]);
    fid.data32 = n;
    ParseId(fid, &protocol, &sourceAddress, &destAddress);

    data.data64 = GetHex64ValueFromString(&b, lineParts->strings[1]);
    ParseData(data, &messageType, &valueType, &errorType, &value);
    printf("      %02x     %03d          %03d           %3d         %3d  %08X\n", protocol, sourceAddress, destAddress, messageType, valueType, value.data32);
    StringListDestroy(lineParts);
  }
  printf("%s %d : %d\n", __FILE__, __LINE__, mainFileLines->stringCount);
}

/*****************************************************************************!
 * Function : MainTerminate
 *****************************************************************************/
void
MainTerminate
()
{
  StringListDestroy(mainFileLines);
  FreeMemory(mainFilename);
}

/*****************************************************************************!
 * Function : MainDisplayHelp 
 *****************************************************************************/
void
MainDisplayHelp
()
{
   printf("Usage : canmonview -f --file filename,  -h --help\n");
}


