/*****************************************************************************!
 * Function : HandleCommandTime
 *****************************************************************************/
void
HandleCommandTime
(StringList* InStrings)
{
  if ( NULL == InStrings || InStrings->stringCount < 2 ) {
    return;
  }
  if ( StringEqualNoCase("ELAPSED", InStrings->strings[1]) ) {
    HandleCommandTimeElapsed(InStrings);
  }
}
