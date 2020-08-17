/*****************************************************************************!
 * Function : HandlePrepareDownloadRequest
 *****************************************************************************/
void
HandlePrepareDownloadRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  string                				baseFilename;
  string	                			s;
  string                                fullFilename;
  string		                		tarFilename;
  string			                	filename;
  string				                responseString;
  int					                packetid;
  bool					                b;
  string                                installDir;

  packetid = JSONIFGetInt(InPacket, "packetid");
  installDir = DirManagementGetInstallDir();
 
  baseFilename = FilenameExtractBase(CANInterfaceOutputFilename);
  tarFilename = StringMultiConcat(installDir, HTTPWWWBaseDir, "/", baseFilename, ".tar.gz", NULL);
  filename = StringMultiConcat(baseFilename, ".tar.gz", NULL);

  fullFilename = StringMultiConcat(installDir, CANInterfaceOutputFilename, NULL);
  CANMonLogWrite("Request for %s file made\n", tarFilename);
  CANMonLogWrite("Compressing %s\n", fullFilename);
  s = StringMultiConcat("tar czf ", tarFilename, " ", fullFilename, NULL);
  b = CANInterfaceMonitor;

  // Only manage the montior switch if the switch is true -- We are currently monitoring the CAN BUS
  if ( b ) {
    CANInterfaceMonitorStop();
  }
  system(s);

  // Ditto here
  if ( b ) {
    CANInterfaceMonitorStart();
  }
  FreeMemory(installDir);
  FreeMemory(s);
  FreeMemory(baseFilename);
  FreeMemory(fullFilename);
  responseString = StringCopy("{\n");
  responseString = StringConcatTo(responseString, "  \"linkname\" : \"");
  responseString = StringConcatTo(responseString, filename);
  responseString = StringConcatTo(responseString, "\",\n");
  
  responseString = StringConcatTo(responseString, "  \"filename\" : \"");
  responseString = StringConcatTo(responseString, filename);
  responseString = StringConcatTo(responseString, "\"\n");
 
 
  responseString = StringConcatTo(responseString, "}\n");

  WebSocketFrameResponseSend(InConnection, "respreparedownloadfile", responseString, packetid, 0, "");
  FreeMemory(responseString);
  FreeMemory(tarFilename);
  FreeMemory(filename);
}
