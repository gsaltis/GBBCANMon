/*****************************************************************************!
 * Function : HandleCommandMonitorClear
 *****************************************************************************/
void
HandleCommandMonitorClear
(StringList* InStrings)
{
  if ( InStrings == NULL ) {
    return;
  }
  if ( InStrings->stringCount < 2 ) {
    return;
  }
  CANInterfaceMonitorStop();
  CANInterfaceFileClose();
  CANInterfaceMonitorCountReset();
  CANInterfaceFileOpen(false);
  CANInterfaceMonitorStart();
}
