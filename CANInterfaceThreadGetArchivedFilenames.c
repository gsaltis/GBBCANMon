/*****************************************************************************!
 * Function : CANInterfaceThreadGetArchivedFilenames
 *****************************************************************************/
StringList*
CANInterfaceThreadGetArchivedFilenames
(string InFilename)
{
  DIR*									dir;
  struct dirent*						entry;
  string								installDirName;
  string								filenameBase;
  string								filenameSuffix;
  StringList*							filenames;
  string								base;
  string								suffix;
 
  filenameBase = FilenameExtractBase(CANInterfaceOutputFilename);
  filenameSuffix = FilenameExtractSuffix(CANInterfaceOutputFilename);

  filenames = StringListCreate();
  installDirName = DirManagementGetInstallDir();
  dir = opendir(installDirName);
  for ( entry = readdir(dir); entry; entry = readdir(dir) ) {
    if ( StringEqualsOneOf(entry->d_name, ".", "..", NULL) ) {
	  continue;
	}
	base = FilenameExtractBase(entry->d_name);
    suffix = FilenameExtractSuffix(entry->d_name);
    if ( base && suffix ) {
	  // We only wnat the archived filenames not the main filename
      if ( StringEqual(base, filenameBase) && StringEqual(suffix, filenameSuffix) ) {
	    FreeMemory(base);
	    FreeMemory(suffix);
	    continue;
	  }
      if ( StringBeginsWith(base, filenameBase) && StringEqual(filenameSuffix, suffix) ) {
		StringListAppend(filenames, StringCopy(entry->d_name));
      }
    }
 	if ( base ) {
   	  FreeMemory(base);
    }
    if ( suffix ) {
	  FreeMemory(suffix);
    }
  }
  closedir(dir);
  FreeMemory(installDirName);
  FreeMemory(filenameBase);
  FreeMemory(filenameSuffix);
  return filenames;
}
