/*****************************************************************************!
 * Function : HTTPServerThreadInit
 *****************************************************************************/
void
HTTPServerThreadInit
()
{
  pthread_create(&HTTPServerThreadID, NULL, HTTPServerThread, NULL);
}
