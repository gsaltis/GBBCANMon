/*****************************************************************************!
 * Function : MainRemoveTarFiles
 * Purpose  : Remove any tar files we left lying around
 *****************************************************************************/
void
MainRemoveTarFiles
()
{
  string								wwwDir;
  string								s;
  struct dirent*							entry;
  DIR*									dir;
  int									n;

  // Get the current directory and the full www directory name
  wwwDir = DirManagementGetWebDir();

  // Switch to the www directory 
  n = chdir(wwwDir);
  if ( n != 0 ) {
    CANMonLogWrite("Could not change directory to %s : %s\n", wwwDir, strerror(errno));
    FreeMemory(wwwDir);
    return;
  }
  
  // Walk the contents of the www directory and remove .tar.gz (Zipped tar) files 
  dir = opendir(wwwDir);
  for ( entry = readdir(dir) ; entry ; entry = readdir(dir) ) {
	string								suffix;
 	if ( StringEqualsOneOf(entry->d_name, ".", "..", NULL) ) {
	  continue;
	}
	suffix = FilenameExtractSuffix(entry->d_name);
	if ( StringEqual(suffix, "tar.gz") ) {
	  s = StringConcat(wwwDir, entry->d_name);
	  unlink(s);
	  FreeMemory(s);
	}	
 	FreeMemory(suffix);
  }

  // Restore everything  
  closedir(dir);
  FreeMemory(wwwDir);    
}
