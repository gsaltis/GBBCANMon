/*******************************************************************************!
 * Function : DirManagementInitialize
 *******************************************************************************/
void
DirManagementInitialize
()
{
  char                                  buffer[FILENAME_MAX+1];
  string                                s;
  int                                   n, m;

  getcwd(buffer, sizeof(buffer)-1);

  n = strlen(buffer);
  m = n - 1;

  s = StringCopy(buffer);
  if ( buffer[m] != DirManagementDirSepChar ) {
    s = StringConcatTo(s, DirManagementDirSepString);
  }
  DMBaseDirectoryName = s; 
  DMMinFileLength = strlen(DMBaseDirectoryName) + 64;
}
