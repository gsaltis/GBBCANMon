/*****************************************************************************!
 * Function : CANMonLogInit
 *****************************************************************************/
void
CANMonLogInit
()
{
  if ( CANMonLogFilename == NULL ) {
    CANMonLogSetFilename(CANMONLOG_DEFAULT_FILENAME);
  }
  unlink(CANMonLogFilename);

  
  CANMonLogFile = fopen(CANMonLogFilename, "wb");
}
