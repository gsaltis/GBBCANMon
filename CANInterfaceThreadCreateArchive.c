/*****************************************************************************!
 * Function : CANInterfaceThreadCreateArchive
 *****************************************************************************/
void
CANInterfaceThreadCreateArchive
(string InFilename)
{
  struct stat					statbuf;
  struct tm*					tm;
  time_t						filetime;
  int							n;
  string						newFilename;
  string						base;
  string						suffix;

  if ( InFilename == NULL ) {
	return;
  }
  if ( !FileExists(InFilename) ) {
	return;
  }
 
  base = FilenameExtractBase(InFilename);
  suffix = FilenameExtractSuffix(InFilename); 

  stat(InFilename, &statbuf);
  filetime = statbuf.st_mtim.tv_sec;

  n = strlen(InFilename);

  newFilename = (string)GetMemory(n + 32);
  tm = localtime(&filetime);

  sprintf(newFilename, "%s-%04d-%02d-%02d-%02d-%02d-%02d.%s", base, tm->tm_year + 1900, 
		  tm->tm_mon + 1,
		  tm->tm_mday,
		  tm->tm_hour,
		  tm->tm_min,
		  tm->tm_sec, 
		  suffix);
  FileUtilsCopyFile(InFilename, newFilename);

  FreeMemory(newFilename);
  FreeMemory(base);
  FreeMemory(suffix);
}
