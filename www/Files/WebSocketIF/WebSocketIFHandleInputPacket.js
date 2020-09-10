/*****************************************************************************!
 * Function : WebSocketHandlerInputPacket
 *****************************************************************************/
function
WebSocketIFHandleInputPacket(InData)
{
  var					requestpacket;

  requestpacket = JSON.parse(InData);
  if ( requestpacket.packettype == "response" ) {
    WebSocketIFHandleResponsePacket(requestpacket);
  }
}

