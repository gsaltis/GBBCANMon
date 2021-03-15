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
  JSONOut*				json;
  JSONOut*                              fileArray;
  string                                suffix;
  string                                wwwfilename;
  string                                linkfilename;
 
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
  base = FileGetBaseFilename(CANInterfaceOutputFilename);
  suffix = FileGetFileSuffix(CANInterfaceOutputFilename);
 
  filename = StringMultiConcat(base, ".tar.gz", NULL);
  FreeMemory(installDir);

  json = JSONOutCreateObject(NULL);

  wwwfilename = StringMultiConcat(base, ".", suffix, NULL);
  linkfilename = StringMultiConcat(base, ".tar.gz", NULL);

  JSONOutObjectAddObjects(json, 
                          JSONOutCreateString("filename", wwwfilename),
                          JSONOutCreateString("linkname", linkfilename),
                          NULL); 

  FreeMemory(wwwfilename);
  FreeMemory(linkfilename);
  FreeMemory(suffix);
  FreeMemory(filename);
 
  fileArray = JSONOutCreateArray("archivedfiles");
 
  filenames = CANInterfaceThreadGetArchivedFilenames(); 
  StringListSort(filenames);
  for (i = 0; i < filenames->stringCount; i++) {
    string                                                              s, s2;
    JSONOut*					archiveJSON;
    base = FileGetBaseFilename(filenames->strings[i]);
    suffix = FileGetFileSuffix(filenames->strings[i]);
    
    s = StringMultiConcat(base, ".", suffix, NULL);
    s2 = StringMultiConcat(base, ".tar.gz", NULL);
    archiveJSON = JSONOutCreateObject(NULL);
    JSONOutObjectAddObjects(archiveJSON, JSONOutCreateString("filename", s), JSONOutCreateString("linkname", s2), NULL); 
    JSONOutArrayAddObject(fileArray, archiveJSON);
    FreeMemory(s);
    FreeMemory(s2);
    FreeMemory(base);
    FreeMemory(suffix);
  }

  JSONOutObjectAddObject(json, fileArray); 
  StringListDestroy(filenames); 
  responseString = JSONOutToString(json, 2);
  WebSocketFrameResponseSend(InConnection, "respreparedownloadfile", responseString, packetid, 0, "");
  FreeMemory(responseString);
}
