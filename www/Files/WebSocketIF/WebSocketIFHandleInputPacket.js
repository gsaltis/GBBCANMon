/*****************************************************************************!
 * Function : WebSocketHandlerInputPacket
 *****************************************************************************/
function
WebSocketIFHandleInputPacket(InData)
{
  var					requestpacket;

  console.log(InData);
  requestpacket = JSON.parse(InData);
  console.log(requestpacket);
  if ( requestpacket.packettype == "response" ) {
    WebSocketIFHandleResponsePacket(requestpacket);
  }
}

