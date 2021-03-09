/*****************************************************************************
 * FILE NAME    : bundle.c
 * DATE         : June 22 2020
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <dirent.h>
#include <errno.h>
#include <StringUtils.h>
#include <FileUtils.h>
#include <MemoryManager.h>
#include <ANSIColors.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Local Macros
 *****************************************************************************/
#define DEFAULT_FILE_NAME		"scripts.js"
#define DEFAULT_DIR_NAME		"./"
#define DIRECTORY_SEPARATOR_CHAR	'/'
#define DIRECTORY_SEPARATOR_STRING	"/"
#define DEFAULT_JAVASCRIPT_SUFFIX	".js"

/*****************************************************************************!
 * Local Type : Filename
 *****************************************************************************/
struct _FilenameType
{
  string								filename;
  string								fullPathname;
  struct _FilenameType*					next;
};
typedef struct _FilenameType FilenameType;

/*****************************************************************************!
 * Local Functions 
 *****************************************************************************/
void
Initialize
();

void
ParseCommandLine
(int argc, char** argv);

void
VerifyCommandLine
();

void
ReadDirectoryFileNames
(string InBaseDirectoryName);

void
BundleFiles
();

void
DisplayHelp
();

FilenameType*
FilenameTypeCreate
(string InFilename, string InFullPathname);

FilenameType*
FilenameTypeInsertAlpha
(FilenameType* InHead, FilenameType* InType);

void
FilenameTypeDump
(FilenameType* InType);

void
FilenameTypeChainDump
(FilenameType* InType);

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
FILE*
MainFile;

string
MainFileName;

string
MainDirName;

FilenameType*
MainFileNames;

/*****************************************************************************!
 * Function : main
 *****************************************************************************/
int
main
(int argc, char** argv)
{
  Initialize();
  ParseCommandLine(argc, argv);
  VerifyCommandLine();
  ReadDirectoryFileNames(MainDirName);

  FilenameTypeChainDump(MainFileNames);
  BundleFiles();

  exit(EXIT_SUCCESS);
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
Initialize
()
{
  MainFileNames = NULL;
  MainFile = NULL;
  MainFileName = StringCopy(DEFAULT_FILE_NAME);
  MainDirName = StringCopy(DEFAULT_DIR_NAME);
}

/*****************************************************************************!
 * Function : ParseCommandLine
 *****************************************************************************/
void
ParseCommandLine
(int argc, char** argv)
{
  int					i;
  string				command;

  for (i = 1; i < argc; i++) {
    command = argv[i];
    if ( StringEqualsOneOf(command, "-h", "--help", NULL) ) {
      DisplayHelp();
      exit(EXIT_SUCCESS);
    }
    if ( StringEqualsOneOf(command, "-f", "--file", NULL) ) {
      i++;
      if ( i == argc ) {
	fprintf(stderr, "%s requires a filename\n", command);
	DisplayHelp();
	exit(EXIT_FAILURE);
      }
      if ( MainFileName ) {
        FreeMemory(MainFileName);
      }
      MainFileName = StringCopy(argv[i]);
      continue;
    }
    if ( StringEqualsOneOf(command, "-d", "--dir", NULL) ) {
      i++;
      if ( i == argc ) {
	fprintf(stderr, "%s requires a directory name\n", command);
	DisplayHelp();
	exit(EXIT_FAILURE);
      }
      if ( MainDirName ) {
	FreeMemory(MainDirName);
      }
      MainDirName = StringCopy(argv[i]);
      continue;
    }
    fprintf(stderr, "%s is not a valid command\n", command);
    DisplayHelp();
    exit(EXIT_FAILURE);	    
  }
}

/*****************************************************************************!
 * Function : VerifyCommandLine
 *****************************************************************************/
void
VerifyCommandLine
()
{
  int					n;

  if ( NULL == MainFileName ) {
    fprintf(stderr, "Missing filename\n");
    DisplayHelp();
    exit(EXIT_FAILURE);
  }

  if ( NULL == MainDirName ) {
    fprintf(stderr, "Missing directory name\n");
    DisplayHelp();
    exit(EXIT_FAILURE);
  }

  if ( !FileExists(MainDirName) ) {
    fprintf(stderr, "The directory %s does not exist\n", MainDirName);
    exit(EXIT_FAILURE);
  } 

  n = strlen(MainDirName);
  n--;
  if ( MainDirName[n] != DIRECTORY_SEPARATOR_CHAR ) {
    MainDirName = StringConcatTo(MainDirName, DIRECTORY_SEPARATOR_STRING);
  }
}

/*****************************************************************************!
 * Function : ReadDirectoryFileNames
 *****************************************************************************/
void
ReadDirectoryFileNames
(string InBaseDirectoryName)
{
  DIR*					                d;
  struct dirent*			            de;
  string				                td;
  int					                p, m, n;
  string                                s;
  FilenameType*                         filenameType;

  p = strlen(DEFAULT_JAVASCRIPT_SUFFIX);
  d = opendir(InBaseDirectoryName);
  if ( d == NULL ) {
    fprintf(stderr, "Could not open directory %s : %s\n", MainDirName, strerror(errno));
    exit(EXIT_FAILURE);
  }

  for ( de = readdir(d); de; de = readdir(d) ) {
    // Skip the directory entries
    if ( StringEqualsOneOf(de->d_name, ".", "..", NULL) ) {
      continue;
    }
    // Don't include->the file we are creating if a previous version exists
    // Of course, this exclude-> any file named the same as MainFileName in 
    //   any subdirectory.  For now so be it.
    if ( StringEqual(de->d_name, MainFileName) ) {
      continue;
    }
    if ( de->d_type & DT_DIR ) {
      // We have a subdirectory, recurse into and collect files
      td = StringMultiConcat(InBaseDirectoryName, de->d_name, "/", NULL);
      ReadDirectoryFileNames(td);
      FreeMemory(td);
      continue;
    }
    n = strlen(de->d_name);
    if ( n < 3 ) {
      continue;
    }
    m = n - p;
    s = de->d_name + m;
    if ( !StringEqual(s, DEFAULT_JAVASCRIPT_SUFFIX) ) {
      continue;
    }
	s = StringConcat(InBaseDirectoryName, de->d_name);
	filenameType = FilenameTypeCreate(de->d_name, s);
	FreeMemory(s);
	MainFileNames = FilenameTypeInsertAlpha(MainFileNames, filenameType);
  }
  closedir(d);  
}

/*****************************************************************************!
 * Function : BundleFiles 
 *****************************************************************************/
void
BundleFiles
()
{
  FILE*					file;
  string				buffer;
  int					bufferSize;
  FilenameType*		    type;

  file = fopen(MainFileName, "wb");
  if ( NULL == file ) {
    fprintf(stderr, "Could not open file %s : %s\n", MainFileName, strerror(errno));
    exit(EXIT_FAILURE);
  }
  
   
  for ( type = MainFileNames; type; type = type->next) {
    GetFileBuffer(type->fullPathname, &buffer, &bufferSize);
    fprintf(file, "// FILE: %s\n", type->fullPathname);
    fprintf(file, buffer);
    FreeMemory(buffer);
	if ( type->next ) {
	  fprintf(file, "\n");
	}
  }

  fclose(file);
}

/*****************************************************************************!
 * Function : DisplayHelp
 *****************************************************************************/
void
DisplayHelp
()
{

}

/*****************************************************************************!
 * Function : FilenameTypeCreate
 *****************************************************************************/
FilenameType*
FilenameTypeCreate
(string InFilename, string InFullPathname)
{
  FilenameType*							type;

  if ( NULL == InFilename || NULL == InFullPathname ) {
	return NULL;
  }

  type = (FilenameType*)GetMemory(sizeof(FilenameType));
  type->filename = StringCopy(InFilename);
  type->fullPathname = StringCopy(InFullPathname);
  type->next = NULL;
  return type;
}

/*****************************************************************************!
 * Function : FilenameTypeDestroy
 *****************************************************************************/
void
FilenameTypeDestroy
(FilenameType* InType)
{
  if ( NULL == InType ) {
	return;
  }

  FreeMemory(InType->filename);
  FreeMemory(InType->fullPathname);
  FreeMemory(InType);
}

/*****************************************************************************!
 * Function : FilenameTypeChainDestroy
 *****************************************************************************/
void
FilenameTypeChainDestroy
(FilenameType* InHead)
{
  FilenameType*							type;
  FilenameType*							next;
  if ( NULL == InHead ) {
	return;
  }

  type = InHead;
  while (type) {
	next = type->next;
	FilenameTypeDestroy(type);
	type = next;
  }
}

/*****************************************************************************!
 * Function : FilenameTypeInsertAlpha
 *****************************************************************************/
FilenameType*
FilenameTypeInsertAlpha
(FilenameType* InHead, FilenameType* InType)
{
  FilenameType*								last;
  FilenameType*								next;
  FilenameType*								type;
  int                                       n;

  if ( NULL == InType ) {
	return InHead;
  }

  if ( NULL == InHead ) {
	return InType;
  }

  // Check to see if this should be the new head
  n = strcmp(InType->filename, InHead->filename);
  if ( n < 0 ) {
	InType->next = InHead;
	return InType;
  }

  type = InHead;
  last = type;

  // Cycle through current list
  while (type) {
	next = type->next;

	// Check to see if current is > InType
    n = strcmp(type->filename, InType->filename);
    if ( n <= 0 ) {
	  last = type;
	  type = next;
	  continue;
    }
	// Insert the item before the current item
	InType->next = type;
	last->next = InType;
    return InHead;	
  }
  last->next = InType;
  return InHead;
}

/*****************************************************************************!
 * Function : FilenameTypeChainDump
 *****************************************************************************/
void
FilenameTypeChainDump
(FilenameType* InType)
{
  FilenameType*							type;

  if ( NULL == InType ) {
	return;
  }

  for ( type = InType ; type ; type = type->next ) {
	FilenameTypeDump(type);
  }
}

/*****************************************************************************!
 * Function : FilenameTypeDump
 *****************************************************************************/
void
FilenameTypeDump
(FilenameType* InType)
{
  printf("    %-50s %s\n", InType->filename, InType->fullPathname);
}

