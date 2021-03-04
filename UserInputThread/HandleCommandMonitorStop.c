/*****************************************************************************!
 * Function : HandleCommandMonitorStop
 *****************************************************************************/
void
HandleCommandMonitorStop
(StringList* InStrings)
{
  if ( InStrings == NULL ) {
    return;
  }
  if ( InStrings->stringCount < 2 ) {
    return;
  }
  CANInterfaceFileClose();
  CANInterfaceMonitorStop();
}
