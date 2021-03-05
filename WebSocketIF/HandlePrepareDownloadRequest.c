/*****************************************************************************!
 * Function : HandlePrepareDownloadRequest
 *****************************************************************************/
void
HandlePrepareDownloadRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  string                                currentDirectory;
  string                                filename;
  string                                responseString;
  int                                   packetid;
  bool                                  b;
  string                                installDir;
  StringList*                           filenames;
  int                                   i;
  string                                base;
  
  packetid = JSONIFGetInt(InPacket, "packetid");
  CANMonLogWrite("Request for %s file made\n", CANInterfaceOutputFilename);
  b = CANInterfaceMonitor;
 
  // Only manage the montior switch if the switch is true -- We are currently monitoring the CAN BUS
  if ( b ) {
    CANInterfaceMonitorStop();
  }
  installDir = DirManagementGetInstallDir();
  currentDirectory = get_current_dir_name();
  FileUtilsTarFile(CANInterfaceOutputFilename, HTTPWWWBaseDir, currentDirectory, installDir);

  // Ditto here
  if ( b ) {
    CANInterfaceMonitorStart();
  }
  base = FilenameExtractBase(CANInterfaceOutputFilename);
  
  filename = StringMultiConcat(base, ".tar.gz", NULL);
  FreeMemory(installDir);
  responseString = StringCopy("{\n");
  responseString = StringConcatTo(responseString, "  \"linkname\" : \"");
  responseString = StringConcatTo(responseString, filename);
  responseString = StringConcatTo(responseString, "\",\n");
  
  responseString = StringConcatTo(responseString, "  \"filename\" : \"");
  responseString = StringConcatTo(responseString, filename);
  responseString = StringConcatTo(responseString, "\",\n");
  responseString = StringConcatTo(responseString, "  \"archivedfiles\" : [ \n");
  
  filenames = CANInterfaceThreadGetArchivedFilenames(); 
  StringListSort(filenames);
  for (i = 0; i < filenames->stringCount; i++) {
    string                                                              s;

        base = FilenameExtractBase(filenames->strings[i]);
    if ( i + 1 < filenames->stringCount ) {
          s = StringMultiConcat("\"", base, ".tar.gz\", ", NULL);
    } else {
          s = StringMultiConcat("\"", base, ".tar.gz\" ", NULL);
    }
    responseString = StringConcatTo(responseString, s);
        FreeMemory(s);
  }

  StringListDestroy(filenames);
  responseString = StringConcatTo(responseString, "]\n");
  responseString = StringConcatTo(responseString, "}\n");

  WebSocketFrameResponseSend(InConnection, "respreparedownloadfile", responseString, packetid, 0, "");
  FreeMemory(responseString);
  FreeMemory(filename);
}
