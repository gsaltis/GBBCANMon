/*****************************************************************************!
 * Function : CANInterfaceThreadManageArchives
 *****************************************************************************/
void
CANInterfaceThreadManageArchives
(string InFilename)
{
  StringList*							filenames;
  int									n, i;
  string 								filename;
  string								dirname;

  dirname = DirManagementGetInstallDir();

  CANMonLogWrite("Transaction filename %s\n", InFilename);
  filenames = CANInterfaceThreadGetArchivedFilenames(InFilename);
  if ( NULL == filenames || filenames->stringCount == 0 ) {
    CANMonLogWrite("No archived files\n");
  } else {
    CANMonLogWrite("Archived[0] = %s\n", filenames->strings[0]);
    CANMonLogWrite("%d archived files\n", filenames->stringCount);
  }
  
  StringListReverseSort(filenames);

  filename = StringConcat(dirname, InFilename);
  if ( FileExists(filename) ) {
	CANInterfaceThreadCreateArchive(filename);
  }
  FreeMemory(filename);
  n = filenames->stringCount;
  if ( n > CANInterfaceThreadMaxArchiveFiles ) {
	for (i = CANInterfaceThreadMaxArchiveFiles; i < n; i++ ) {
	  unlink(filenames->strings[i]);
	}
  }
  StringListDestroy(filenames);
}
