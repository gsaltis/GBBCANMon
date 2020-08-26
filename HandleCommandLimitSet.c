/*****************************************************************************!
 * Function : HandleCommandLimitSet
 *****************************************************************************/
void
HandleCommandLimitSet
(StringList* InStrings)
{
  int                                   n;
  bool                                  b;

  if ( InStrings->stringCount == 2 ) {
	if ( StringEqualNoCase(InStrings->strings[1], "none") ) {
	  MainLimitSet("none", 0);
      return;
    }
  } else if ( InStrings->stringCount == 3 ) {
	n = GetIntValueFromString(&b, InStrings->strings[2]);
	if ( !b ) {
	  return;
	}
	if ( MainLimitSet(InStrings->strings[1], n) ) {
	  fprintf(stdout, "Set Limit to %s %s\n", InStrings->strings[1], InStrings->strings[2]); 
    } else {
	  fprintf(stdout, "Could not set Limit %s to %s\n", InStrings->strings[1], InStrings->strings[2]);
    }
  }
}
