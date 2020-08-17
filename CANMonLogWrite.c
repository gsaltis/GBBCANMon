/*****************************************************************************!
 * Function : CANMonLogWrite
 *****************************************************************************/
void
CANMonLogWrite
(string InFormat, ...)
{
  va_list                               ap;
  time_t                                t;
  struct tm*                            tm;

  if ( NULL == CANMonLogFile ) {
    return;
  }
  va_start(ap, InFormat);
  pthread_mutex_lock(&CANMonLogMutex); 
  t = time(NULL);
  tm = localtime(&t);
  fprintf(CANMonLogFile, "%02d/%02d/%04d %02d:%02d:%02d : ", tm->tm_mon + 1, tm->tm_mday, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);
  vfprintf(CANMonLogFile, InFormat, ap);
  fflush(CANMonLogFile);
  va_end(ap); 
  pthread_mutex_unlock(&CANMonLogMutex);
}
