/*****************************************************************************!
 * Function : CANMonLogSetFilename
 *****************************************************************************/
void
CANMonLogSetFilename
(string InFilename)
{
  if ( InFilename == NULL ) {
    return;
  }

  if ( CANMonLogFilename ) {
    FreeMemory(CANMonLogFilename);
  }
  CANMonLogFilename = StringCopy(InFilename);
}
