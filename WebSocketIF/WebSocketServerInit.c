/*****************************************************************************!
 * Function : WebSocketServerInit
 *****************************************************************************/
void
WebSocketServerInit()
{
  pthread_create(&WebSocketServerThreadID, NULL, WebSocketServerThread, NULL);
}
