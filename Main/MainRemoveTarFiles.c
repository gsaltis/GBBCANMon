/*****************************************************************************!
 * Function : MainRemoveTarFiles
 * Purpose  : Remove any tar files we left lying around
 *****************************************************************************/
void
MainRemoveTarFiles
()
{
  string								wwwDir;
  string								currentDir;
  string								s;
  struct dirent*						entry;
  DIR*									dir;
  int									n;

  // Get the current directory and the full www directory name
  currentDir = get_current_dir_name();
  s = DirManagementGetInstallDir();
  wwwDir = StringMultiConcat(s, HTTPWWWBaseDir, NULL);
  FreeMemory(s);

  // Switch to the www directory 
  n = chdir(wwwDir);
  if ( n != 0 ) {
	CANMonLogWrite("Could not change directory to %s : %s\n", wwwDir, strerror(errno));
	free(currentDir);
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
	  unlink(entry->d_name);
	}	
 	FreeMemory(suffix);
  }

  // Restore everything  
  closedir(dir);
  chdir(currentDir);   
  free(currentDir);
  FreeMemory(wwwDir);    
}
