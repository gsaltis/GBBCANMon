/*****************************************************************************!
 * Function : WebSocketServerThread
 *****************************************************************************/
void*
WebSocketServerThread
(void* InArgs)
{
  struct mg_connection *              nc;
  struct mg_mgr                       mgr;
  CANMonLogWrite("Starting websocket server thread on port %s\n", s_websocket_port);
  mg_mgr_init(&mgr, NULL);

  nc = mg_bind(&mgr, s_websocket_port, WebSocketEventHandler);
  if (nc == NULL) {
    CANMonLogWrite("Failed to create webssocket listener\n");
    return (void*)1;
  }
  mg_set_protocol_http_websocket(nc);

  for (;;) {
    mg_mgr_poll(&mgr, 20);
  }
}
