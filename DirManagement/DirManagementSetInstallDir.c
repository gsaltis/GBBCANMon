/*****************************************************************************!
 * Function : DirManagementSetInstallDir
 *****************************************************************************/
void
DirManagementSetInstallDir
(string InInstallDir)
{
  int                                   n;

  if ( NULL == InInstallDir ) {
    return;
  }
  if ( DMBaseDirectoryName ) {
    FreeMemory(DMBaseDirectoryName);
  }
    
  DMBaseDirectoryName = StringCopy(InInstallDir);

  n = strlen(DMBaseDirectoryName);
  if ( DMBaseDirectoryName[n-1] != DirManagementDirSepChar ) {
    DMBaseDirectoryName = StringConcatTo(DMBaseDirectoryName, DirManagementDirSepString);
  }
}
