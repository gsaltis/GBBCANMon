/*****************************************************************************!
 * Function : MessageSetLimitsResponse
 *****************************************************************************/
string
MessageSetLimitsResponse
(bool InSuccess, string InType, int InValue)
{
  char									s[32];

  if ( InSuccess ) {
    if ( StringEqual(InType, "none") ) {
      return StringCopy("Limit set to NONE");
	}
	if ( StringEqual(InType, "days") ) {
	  if ( InValue == 1 ) {
		return StringCopy("Limit set to 1 Day");	
	  }
	  sprintf(s, "%d", InValue);
	  return StringMultiConcat("Limit set to ", s, " Days", NULL);
	}

	if ( StringEqual(InType, "hours") ) {
	  if ( InValue == 1 ) {
		return StringCopy("Limit set to 1 Hour");	
	  }
	  sprintf(s, "%d", InValue);
	  return StringMultiConcat("Limit set to ", s, " Hours", NULL);
	}

	if ( StringEqual(InType, "count") ) {
	  if ( InValue == 1 ) { 
		return StringCopy("Limit set to 1 Message");	
	  }
      ConvertIntToCommaString(InValue, s);
	  return StringMultiConcat("Limit set to ", s, " Messages", NULL);
	}

	if ( StringEqual(InType, "size") ) {
	  if ( InValue == 1 ) {
		return StringCopy("Limit set to 1 MByte");	
	  }
	  sprintf(s, "%d", InValue);
	  return StringMultiConcat("Limit set to ", s, " MBytes", NULL);
	}
  } else {
    if ( StringEqual(InType, "none") ) {
      return StringCopy("Cannot set limit to NONE");
	}
	if ( StringEqual(InType, "days") ) {
	  if ( InValue == 1 ) {
		return StringCopy("Cannot set limit to 1 Day");	
	  }
	  sprintf(s, "%d", InValue);
	  return StringMultiConcat("Cannot set limit to ", s, " Days", NULL);
	}

	if ( StringEqual(InType, "hours") ) {
	  if ( InValue == 1 ) {
		return StringCopy("Cannot set limit to 1 Hour");	
	  }
	  sprintf(s, "%d", InValue);
	  return StringMultiConcat("Cannot set limit to ", s, " Hours", NULL);
	}

	if ( StringEqual(InType, "count") ) {
	  if ( InValue == 1 ) { 
		return StringCopy("Cannot set limit to 1 Message");	
	  }
      ConvertIntToCommaString(InValue, s);
	  return StringMultiConcat("Cannot set limit to ", s, " Messages", NULL);
	}

	if ( StringEqual(InType, "size") ) {
	  if ( InValue == 1 ) {
		return StringCopy("Cannot set limit to 1 MByte");	
	  }
	  sprintf(s, "%d", InValue);
	  return StringMultiConcat("Cannot set limit to ", s, " MBytes", NULL);
	}

  }
  return StringCopy("");
}
