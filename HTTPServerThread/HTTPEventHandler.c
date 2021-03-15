/*****************************************************************************!
 * Function : HTTPEventHandler
 *****************************************************************************/
void
HTTPEventHandler
(struct mg_connection* nc, int ev, void* p)
{
  string                                installDirectory;       // Free me
  string                                currentDirectory;       // Free me
  int                                   k, n;
  struct http_message*                  message;
  string                                s;
  StringList*                           lines;
  StringList*                           elements;
  StringList*                           urlParts;
  string                                fileNameBase;
  string                                base;
  string                                filename;               // Free me

  // Get the base part of the download file name
  fileNameBase = FilenameExtractBase(CANInterfaceOutputFilename);

  if (ev == MG_EV_HTTP_REQUEST) {
    message = (struct http_message*)p;

    s = (string)message->uri.p;

    // Extract the first request line - the URL
    lines = StringSplit(s, "\n", true);
    if ( lines->stringCount > 0 ) {

      // Get the URL Line so we can check for a archived version of the data file
      // we need to tar up before so the mongoose engine can send it.  If it's not
      // an archived version but simply the data file we just drop through and 
      // let the mongoose engine handle since it's already been tar'd up
      elements = StringSplit(lines->strings[0], " ", true);
      urlParts = StringSplit(elements->strings[0], "/", true);
      if ( urlParts->stringCount > 0 ) {
	k = urlParts->stringCount - 1;
        base = FilenameExtractBase(urlParts->strings[k]);
        if ( base ) {
          // Check if this is a archived version file (begins with the filename but is not the filename)
          if ( StringBeginsWith(base, fileNameBase) && !StringEqual(base, fileNameBase) ) {
            // It's an archived version of the file so we append a suffix and tar it
            filename = StringConcat(base, ".txt");
            currentDirectory = get_current_dir_name();
            installDirectory = DirManagementGetInstallDir();
            n = FileUtilsTarFile(filename, HTTPWWWBaseDir, currentDirectory, installDirectory);
            if ( n ) {
              CANMonLogWrite("Could not write tar file %s\n", strerror(n));
            }
            free(currentDirectory);
            FreeMemory(installDirectory);
            FreeMemory(filename);       
          }
          FreeMemory(base);
        }
      }
      StringListDestroy(elements);
      StringListDestroy(urlParts);
    }
    mg_serve_http(nc, message, s_http_server_opts);
    StringListDestroy(lines);
  }
}

