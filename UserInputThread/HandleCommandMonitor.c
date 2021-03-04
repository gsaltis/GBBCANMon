/*****************************************************************************!
 * Function : HandleCommandMonitor
 *****************************************************************************/
void
HandleCommandMonitor
(StringList* InStrings)
{
  if ( InStrings == NULL ) {
    return;
  }
  if ( InStrings->stringCount == 1 ) {
    printf("Monitor CAN Traffic : %s\n", CANInterfaceMonitor ? "ON" : "FALSE");
    printf("Monitor Output file : %s\n", CANInterfaceOutputFilename);
    return;
  }
  if ( InStrings->stringCount < 2 ) {
    return;
  }
  if ( StringEqualNoCase(InStrings->strings[1], "STOP") ) {
    HandleCommandMonitorStop(InStrings);
  } else if ( StringEqualNoCase(InStrings->strings[1], "START") ) {
    HandleCommandMonitorStart(InStrings);
  } else if ( StringEqualNoCase(InStrings->strings[1], "CLEAR") ) {
    HandleCommandMonitorClear(InStrings);
  }
}
