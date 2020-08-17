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
  }
}

