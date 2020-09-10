/*****************************************************************************!
 * Function : WebSocketIFInitialize
 *****************************************************************************/
function 
WebSocketIFInitialize()
{
  var hostAddress = "ws://" + WebSocketIFAddress + ":" + WebSocketIFPort; 

  WebSocketIFConnection = new WebSocket(hostAddress);

  WebSocketIFConnection.onopen = function () {
    WebSocketIFSendSimpleRequest("getlimits"); 
    MainDisplayMessage("Connected");
  };

  // Log errors
  WebSocketIFConnection.onerror = function (error) {
  };

  // 
  WebSocketIFConnection.onclose = function() {
  }
  
  // Log messages from the server
  WebSocketIFConnection.onmessage = function (e) {
    WebSocketIFHandleInputPacket(e.data);
  };
}

