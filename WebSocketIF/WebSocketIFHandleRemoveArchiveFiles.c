/*****************************************************************************!
 * Function : WebSocketIFHandleRemoveArchiveFiles
 *****************************************************************************/
void
WebSocketIFHandleRemoveArchiveFiles
(struct mg_connection* InConnection, json_value* InPacket)
{
  StringList*							archiveFilenames;
  int                                   i;
  string 								installDir;
  string 								unRemovedFiles = NULL;
  string								returnMessage;
  int									unRemovedFilesCount = 0;
  int									packetid;

  packetid = JSONIFGetInt(InPacket, "packetid");
  installDir = DirManagementGetInstallDir();
  archiveFilenames = CANInterfaceThreadGetArchivedFilenames();
  for (i = 0 ; i < archiveFilenames->stringCount ; i++ ) {
    string filename = StringMultiConcat(installDir, archiveFilenames->strings[i], NULL);
	if ( unlink(filename) ) {
	  if ( unRemovedFiles == NULL ) {
		unRemovedFiles = StringCopy(archiveFilenames->strings[i]);
      } else {
		unRemovedFilesCount++;
		unRemovedFiles = StringConcatTo(unRemovedFiles, " ");
		unRemovedFiles = StringConcatTo(unRemovedFiles, archiveFilenames->strings[i]);
	  }
    }
	FreeMemory(filename);
  }
  if ( unRemovedFiles ) {
	returnMessage = StringMultiConcat("Archived file", unRemovedFilesCount ? "s " : " ", unRemovedFiles, " not removed", NULL);
  	FreeMemory(unRemovedFiles);
  } else {
	returnMessage = StringMultiConcat("Archived file", archiveFilenames->stringCount ? "s" : "", " removed", NULL);
  }
  StringListDestroy(archiveFilenames);
  FreeMemory(installDir);

  WebSocketFrameResponseSend(InConnection, "resremovearchivefiles", "\"\"",  packetid, time(NULL), returnMessage);
  FreeMemory(returnMessage);
}
