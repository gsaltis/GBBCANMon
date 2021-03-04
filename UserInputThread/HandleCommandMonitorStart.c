/*****************************************************************************!
 * Function : HandleCommandMonitorStart
 *****************************************************************************/
void
HandleCommandMonitorStart
(StringList* InStrings)
{
  if ( InStrings == NULL ) {
    return;
  }
  if ( InStrings->stringCount < 2 ) {
    return;
  }
  CANInterfaceFileOpen(true);
  CANInterfaceMonitorStart();
}
