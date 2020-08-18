/*****************************************************************************!
 * Function : CANInterfaceThreadManageArchives
 *****************************************************************************/
void
CANInterfaceThreadManageArchives
(string InFilename)
{
  StringList*							filenames;
  int									n, i;

  filenames = CANInterfaceThreadGetArchivedFilenames(InFilename);

  StringListReverseSort(filenames);

  if ( FileExists(InFilename) ) {
	CANInterfaceThreadCreateArchive(InFilename);
  }
  n = filenames->stringCount;
  if ( n > CANInterfaceThreadMaxArchiveFiles ) {
	for (i = CANInterfaceThreadMaxArchiveFiles; i < n; i++ ) {
	  unlink(filenames->strings[i]);
	}
  }
  StringListDestroy(filenames);
}
