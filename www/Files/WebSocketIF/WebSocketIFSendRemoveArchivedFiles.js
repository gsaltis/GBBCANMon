/*****************************************************************************!
 * Function : WebSocketIFSendRemoveArchivedFiles
 *****************************************************************************/
function
WebSocketIFSendRemoveArchivedFiles
()
{
  var									request;

  request = {};
  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.type = 'removearchivefiles';
  WebSocketIFSendGeneralRequest(request); 
}
