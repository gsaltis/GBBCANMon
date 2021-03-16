/*****************************************************************************!
 * Function : CANInterfaceThreadHandleRequest
 *****************************************************************************/
void
CANInterfaceThreadHandleRequest
(CANInterface* InInterface, frameid InID, dataframe InData, time_t InTime)
{
  struct utimbuf						timebuf;
  string                                                        installDir, s;

  timebuf.actime = MainTimeStampTime;
  timebuf.modtime = MainTimeStampTime;
  installDir = DirManagementGetInstallDir();
  s = StringConcat(installDir, CANInterfaceOutputFilename);

  if ( utime(s, &timebuf) ) {
    if ( MainUseUI ) {
      fprintf(stderr, "Could not change times on %s - %s\n", s, strerror(errno));
    }
  }		

  FreeMemory(s);
  FreeMemory(installDir);
  if ( CANInterfaceMonitor && CANInterfaceOutputFile ) {
    MainLimitSizeRuntime += fprintf(CANInterfaceOutputFile, "%08x %016llX %08lx\n", InID.data32, InData.data64, InTime);
    
    fflush(CANInterfaceOutputFile);
  }
}

