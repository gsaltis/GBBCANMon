/*****************************************************************************!
 * Function : HandleCommandMessage
 *****************************************************************************/
void
HandleCommandMessage
(StringList* InStrings)
{
  string                                command;

  if ( NULL == InStrings || InStrings->stringCount < 2 ) {
    return;
  }
  command = InStrings->strings[1];
  if ( StringEqualNoCase(command, "COUNT") ) {
    HandleCommandMessageCount(InStrings);
  }
}
