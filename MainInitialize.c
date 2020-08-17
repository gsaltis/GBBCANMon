/*****************************************************************************!
 * Function : MainInitialize
 *****************************************************************************/
void
MainInitialize
()
{
  atexit(MainExit);  
  MainStartTime = time(NULL);
  MainDatabaseName = StringCopy("MainDataBase.db");
  MainCANInterfaceName = StringCopy("slcan0");
  WebSocketIFSetPort(MainDefaultWebSocketPort);
  DirManagementInitialize();
}
