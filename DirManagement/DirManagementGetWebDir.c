/*****************************************************************************!
 * Function : DirManagementGetWebDir
 *****************************************************************************/
string
DirManagementGetWebDir
()
{
  string				dirname;
  string                                webDirname;

  dirname = DirManagementGetInstallDir();
  webDirname = StringMultiConcat(dirname, DirManagementWebDirName, "/", NULL);
  FreeMemory(dirname);

  return webDirname;
}
