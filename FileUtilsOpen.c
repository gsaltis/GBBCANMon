/*****************************************************************************!
 * Function : FileUtilsOpen
 *****************************************************************************/
FILE*
FileUtilsOpen
(string InFilename, string InFilePermissions)
{
  string                                dir;
  string                                filename;
  FILE*                                 file;

  dir = DirManagementGetInstallDir();
  filename = StringConcat(dir, InFilename);

  CANMonLogWrite("File Opened : %s\n", filename);
  file = fopen(filename, InFilePermissions);
 
  FreeMemory(filename);
  FreeMemory(dir);

  return file;
}
