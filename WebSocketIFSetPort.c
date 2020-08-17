/*****************************************************************************!
 * Function : WebSocketIFSetPort
 *****************************************************************************/
void
WebSocketIFSetPort
(string InPortNumber)
{
  if ( NULL == InPortNumber ) {
    return;
  }

  if ( NULL != s_websocket_port ) {
    FreeMemory(s_websocket_port);
  }

  s_websocket_port = StringCopy(InPortNumber);
}

