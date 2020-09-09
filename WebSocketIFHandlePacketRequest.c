/*****************************************************************************!
 * Function : WebSocketIFHandlePacketRequest
 *****************************************************************************/
void
WebSocketIFHandlePacketRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  string                                requesttype;
  if ( NULL == InPacket ) {
    return;
  }
 
  requesttype = JSONIFGetString(InPacket, "type");
  if ( NULL == requesttype ) {
    return;
  }

  if ( StringEqual("getmonitorinfo", requesttype) ) {
    WebSocketIFHandleGetMonitorInfoRequest(InConnection, InPacket);
  } else if ( StringEqual("preparedownloadfilename", requesttype) ) {
    HandlePrepareDownloadRequest(InConnection, InPacket);
  } else if ( StringEqual("monitortoggle", requesttype) ) {
    HandleToggleMonitorRequest(InConnection, InPacket);
  } else if ( StringEqual("getbays", requesttype) ){
    HandleGetBaysRequest(InConnection, InPacket);
  } else if ( StringEqual("getlimits", requesttype) ) {
	HandleGetLimitsRequest(InConnection, InPacket);
  } else if ( StringEqual("settimestamp", requesttype) ) {
	WebSocketIFHandleSetTimeStampRequest(InConnection, InPacket);
  } else if ( StringEqual("setlimits", requesttype) ) {
	WebSocketIFHandleSetLimitsRequest(InConnection, InPacket);
  } else if ( StringEqual("removearchivefiles", requesttype) ) {
	WebSocketIFHandleRemoveArchiveFiles(InConnection, InPacket);
  }
  FreeMemory(requesttype);
}
