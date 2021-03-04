/*****************************************************************************!
 * Function : HandleCommandMessageCount
 *****************************************************************************/
void
HandleCommandMessageCount
(StringList* InStrings)
{
  time_t                                currentTime = time(NULL);
  time_t                                elapsedTime = currentTime - MainStartTime;
  fprintf(stdout, "%sMessage Count : %d %ld seconds%s\n", ColorBrightGreen, CANInterfaceMessagesCount, elapsedTime, ColorReset);
}
