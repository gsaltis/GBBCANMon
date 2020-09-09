/*****************************************************************************!
 * Function : CANInterfaceThreadHandleRequest
 *****************************************************************************/
void
CANInterfaceThreadHandleRequest
(CANInterface* InInterface, frameid InID, dataframe InData, time_t InTime)
{
  struct utimbuf						timebuf;

  timebuf.actime = MainTimeStampTime;
  timebuf.modtime = MainTimeStampTime;

  if ( utime(CANInterfaceOutputFilename, &timebuf) ) {
    if ( MainUseUI ) {
      fprintf(stderr, "Could not change times on %s - %s\n", CANInterfaceOutputFilename, strerror(errno));
    }
  }		
  if ( CANInterfaceMonitor && CANInterfaceOutputFile ) {
    MainLimitSizeRuntime += fprintf(CANInterfaceOutputFile, "%08x %016llX %08lx\n", InID.data32, InData.data64, InTime);
    
    fflush(CANInterfaceOutputFile);
  }
}

