/*****************************************************************************!
 * Function : MainInitialize
 *****************************************************************************/
void
MainInitialize
()
{
  atexit(MainExit);  
  MainStartTime  = time(NULL);
  MainTimeStampTime = MainStartTime;
  MainLimitType  = StringCopy("size");
  MainLimitDays  = 3;
  MainLimitHours = 96;
  MainLimitCount = 50000;
  MainLimitSize  = 10;

  MainLimitDaysRuntime 	= 0;
  MainLimitHoursRuntime = 0;
  MainLimitCountRuntime = 0;
  MainLimitSizeRuntime 	= 0;

  MainDatabaseName = StringCopy("MainDataBase.db");
  MainCANInterfaceName = StringCopy("slcan0");
  WebSocketIFSetPort(MainDefaultWebSocketPort);
  DirManagementInitialize();
}
