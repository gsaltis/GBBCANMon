/*****************************************************************************!
 * Function : WebSocketIFSendDate
 *****************************************************************************/
function
WebSocketIFSendDate
(InDateString)
{
  var                                   request;

  request = {};
  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID(); 
  request.time = 0;
  request.type = "setdate";
  request.body = {};
  request.body.datetime = InDateString;
  
  WebSocketIFSendGeneralRequest(request);
}
