/*****************************************************************************!
 * Function : HandleCommand
 *****************************************************************************/
void
HandleCommand
(StringList* InStrings)
{
  string                                command;
  if ( NULL == InStrings || InStrings->stringCount == 0 ) {
    return;
  }
  command = InStrings->strings[0];
  if ( StringEqualNoCase(command, "EXIT")  || StringEqualNoCase(command, "QUIT") ) {
    HandleCommandExit(InStrings);
  } else if ( StringEqualNoCase(command, "MESSAGE") ) {
    HandleCommandMessage(InStrings);
  } else if ( StringEqualNoCase(command, "TIME") ) {
    HandleCommandTime(InStrings);
  } else if ( StringEqualNoCase(command, "HELP") ) {
    HandleCommandHelp(InStrings);
  } else if ( StringEqualNoCase(command, "MONITOR") ) {
    HandleCommandMonitor(InStrings);
  } else if ( StringEqualNoCase(command, "LOG") ) {
    HandleCommandLog(InStrings);
  } else if ( StringEqualNoCase(command, "LIMIT") ) {
        HandleCommandLimit(InStrings);
  }
}
