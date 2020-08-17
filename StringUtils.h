/*****************************************************************************
 * FILE NAME    : StringUtils.h
 * DATE         : March 17 2020
 * PROJECT      : Bay Simulator
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/

#ifndef _stringutils_h_
#define _stringutils_h_

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

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Data
 *****************************************************************************/

/*****************************************************************************!
 * Exported Functions
 *****************************************************************************/
void
TrimEndOfLine
(char* InString);

char*
TrimStartOfLine
(char* InString);

char*
TrimLine
(char* InString);

bool
GetBoolFromString
(char* InString);

int
StringToFloat
(char* InString);

#endif /* _stringutils_h_*/
