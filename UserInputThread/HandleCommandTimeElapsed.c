/*****************************************************************************!
 * Function ; HandleCommandTimeElapsed
 *****************************************************************************/
void
HandleCommandTimeElapsed
(StringList* InStrings)
{
  time_t                                t;
  uint32_t                              e, hours, minutes, seconds;

  t = time(NULL);

  e = t - MainStartTime;
  hours = e / 3600;
  e = e % 3600;
  minutes = e / 60;
  seconds = e % 60;

  if ( hours ) {
    fprintf(stdout, "Elapsed : %d:%02d:%02d\n", hours, minutes, seconds);
  } else {
    fprintf(stdout, "Elapsed : %d:%02d\n", minutes, seconds);
  }
}
