/*****************************************************************************!
 * Function : HandleCommandHelp
 *****************************************************************************/
void
HandleCommandHelp
(StringList* InStrings)
{
  fprintf(stdout, "COMMANDS\n");
  fprintf(stdout, "%s  MESSAGE COUNT%s                       - Display number of messages seen\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  TIME ELAPSED%s                        - Display the time application has been running\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  MONITOR%s                             - Display the monitoring status\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  MONITOR STOP%s                        - Stop the montitoring of CAN Data\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s          START%s                       - Start the montitoring of CAN Data\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s          CLEAR%s                       - Clear the collected of CAN Data\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  HELP%s                                - Display this information\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  LIMIT%s                               - Display the current file limits\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  LIMIT {type {value}}%s                - Set the current file limits\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s         type : { none | hours | count | size | date%s\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s         none%s                         - Do not implose limits on the output file\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s         hours (1-96)%s                 - Specifies maximum number of hours of data to collect\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s         count (1 - 10,000,000)%s       - Specifies max number of message to collect\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s         size (1-500)%s                 - Specifies max number of MBytes of data to collect\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s         days (1-7)%s                   - Specifies max number of days of data to collect\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  EXIT | QUIT%s                         - Exit the application\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s  LOG%s                                 - Display the log\n", ColorBrightRed, ColorBrightGreen);
  fprintf(stdout, "%s\n", ColorReset);
}

