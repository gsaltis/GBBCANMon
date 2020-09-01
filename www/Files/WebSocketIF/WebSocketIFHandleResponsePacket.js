/*****************************************************************************!
 * Function : WebSocketIFHandleResponsePacket
 *****************************************************************************/
function
WebSocketIFHandleResponsePacket(InPacket)
{
  if ( InPacket.responseid != "OK" ) {
    MainDisplayMessage(InPacket.responsemessage);
    return;
  }
  if ( InPacket.type == "resmonitorinfo" ) {
    WebSocketIFHandleResponseMonitorInfo(InPacket.body.monitorinfo);
  } else if ( InPacket.type == "respreparedownloadfile"  ) {
    WebSocketIFHandleResponsePrepareDownloadFile(InPacket.body);
  } else if ( InPacket.type == "resgetlimits" ) {
	WebSocketIFHandleGetLimitsResponse(InPacket.body);
  } else if ( InPacket.type == "ressettimestamp" ) {
	WebSocketIFHandleSetTimeResponse(InPacket.body);
  } else if ( InPacket.type == "ressetlimits" ) {
	WebSocketIFHandleSetLimitsResponse(InPacket.body);
  }
}

