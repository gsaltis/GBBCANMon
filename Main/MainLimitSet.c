/*****************************************************************************!
 * Function : MainLimitSet
 *****************************************************************************/
bool
MainLimitSet
(string InType, int InValue)
{
  if ( StringEqualNoCase(InType, "none") ) {
	if ( MainLimitType ) {
	  FreeMemory(MainLimitType);
	}
	MainLimitType = StringCopy(InType);
	return true;
  }

  if ( StringEqualNoCase(InType, "count") ) {
	if ( InValue < MainMinLimitCount || InValue >= MainMaxLimitCount ) {
	  return false;
	}
	if ( MainLimitType ) {
	  FreeMemory(MainLimitType);
	}
	MainLimitType = StringCopy(InType);
	MainLimitCount = InValue;
	return true;
  }
  if ( StringEqualNoCase(InType, "days") ) {
	if ( InValue < MainMinLimitDays || InValue >= MainMaxLimitDays ) {
	  return false;
	}
	if ( MainLimitType ) {
	  FreeMemory(MainLimitType);
	}
 	MainLimitType = StringCopy(InType);
	MainLimitDays = InValue;
	return true;
  }
  if ( StringEqualNoCase(InType, "size") ) {
	if ( InValue < MainMinLimitSize || InValue >= MainMaxLimitSize ) {
	  return false;
	}
	if ( MainLimitType ) {
	  FreeMemory(MainLimitType);
	}
 	MainLimitType = StringCopy(InType);
	MainLimitSize = InValue;
	return true;
  }
  if ( StringEqualNoCase(InType, "hours") ) {
	if ( InValue < MainMinLimitHours || InValue >= MainMaxLimitHours ) {
	  return false;
	}
	if ( MainLimitType ) {
	  FreeMemory(MainLimitType);
	}
 	MainLimitType = StringCopy(InType);
	MainLimitHours = InValue;
	return true;
  }
  return false;
}
