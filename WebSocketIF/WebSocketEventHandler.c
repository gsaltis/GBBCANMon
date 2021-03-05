/*****************************************************************************!
 * Function : WebSocketEventHandler
 *****************************************************************************/
void
WebSocketEventHandler
(struct mg_connection* nc, int ev, void* p)
{
  if ( ev == 0 ) {
    return;
  }
  switch (ev) {
    case MG_EV_CLOSE : {
      break;
    }

    case MG_EV_WEBSOCKET_FRAME: {
      struct websocket_message *wm = (struct websocket_message *) p;
      struct mg_str d = {(char *) wm->data, wm->size};
      HandleWebSocketRequest(nc, d);
      break;
    }
  }
}
