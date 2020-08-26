/*****************************************************************************!
 * Function : MainInitialize
 *****************************************************************************/
void
MainInitialize
()
{
  atexit(MainExit);  
  MainStartTime = time(NULL);
  MainLimitType = StringCopy("size");
  MainLimitDays =           3;
  MainLimitHours =         96;
  MainLimitCount =    50;  // 000;
  MainLimitSize  =  5000;    // 0000000;

  MainLimitDaysRuntime 	= 0;
  MainLimitHoursRuntime = 0;
  MainLimitCountRuntime = 0;
  MainLimitSizeRuntime 	= 0;

  MainDatabaseName = StringCopy("MainDataBase.db");
  MainCANInterfaceName = StringCopy("slcan0");
  WebSocketIFSetPort(MainDefaultWebSocketPort);
  DirManagementInitialize();
}
