/*****************************************************************************!
 * Function : HTTPEventHandler
 *****************************************************************************/
void
HTTPEventHandler
(struct mg_connection* nc, int ev, void* p)
{
  struct http_message*					message;
  string								s;
  StringList*							lines;
  StringList*							elements;
  StringList*							urlParts;
  string								fileNameBase;
  string								base;
  string								filename;

  fileNameBase = FilenameExtractBase(CANInterfaceOutputFilename);

  if (ev == MG_EV_HTTP_REQUEST) {
    message = (struct http_message*)p;

   	s = (string)message->uri.p;

    lines = StringSplit(s, "\n", true);
    if ( lines->stringCount > 0 ) {
	  elements = StringSplit(lines->strings[0], " ", true);
	  urlParts = StringSplit(elements->strings[0], "/", true);
	  if ( urlParts->stringCount > 0 ) {
		base = FilenameExtractBase(urlParts->strings[0]);
		if ( base ) {
		  if ( StringEqual(base, fileNameBase) ) {
		    FreeMemory(base);
  		  } else if ( StringBeginsWith(base, fileNameBase) ) {
			filename = StringConcat(base, ".txt");
	        printf("%s %d : %s\n", __FILE__, __LINE__, filename);
			FileUtilsTarFile(filename, HTTPWWWBaseDir);
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

