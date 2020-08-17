/*****************************************************************************!
 * Function : WebSocketHandlerInputPacket
 *****************************************************************************/
function
WebSocketIFHandleInputPacket(InData)
{
  var					requestpacket;

  requestpacket = JSON.parse(InData);
  console.log(requestpacket);

  if ( requestpacket.packettype == "response" ) {
    console.log(requestpacket);
    WebSocketIFHandleResponsePacket(requestpacket);
  }
}

