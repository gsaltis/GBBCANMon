/*****************************************************************************!
 * Function : WebSocketIFSendLimits
 *****************************************************************************/
function
WebSocketIFSendLimits
(InType, InValue)
{
  var                                   request;

  request = {};
  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID(); 
  request.time = 0;
  request.type = "setlimits";
  request.body = {};
  request.body.type = InType;
  if ( InValue ) {
    request.body.value = InValue;
  }
  WebSocketIFSendGeneralRequest(request);
} 
