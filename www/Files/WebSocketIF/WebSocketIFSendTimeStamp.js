/*****************************************************************************!
 * Function : WebSocketIFSendTimeStamp
 *****************************************************************************/
function
WebSocketIFSendTimeStamp
(InDateString)
{
  var                                   request;

  request = {};
  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID(); 
  request.time = 0;
  request.type = "settimestamp";
  request.body = {};
  request.body.datetime = InDateString;
  
  WebSocketIFSendGeneralRequest(request);
}
