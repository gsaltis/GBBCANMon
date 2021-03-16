/*****************************************************************************!
 * Function : MainLimitTypeSet
 *****************************************************************************/
void
MainLimitTypeSet
(string InType)
{
  if ( StringEqualNoCase(InType, "none") ) {
    if ( MainLimitType ) {
      FreeMemory(MainLimitType);
    }
    MainLimitType = StringCopy(InType);
  } else if ( StringEqualNoCase(InType, "count") ) {
    if ( MainLimitType ) {
      FreeMemory(MainLimitType);
    }
    MainLimitType = StringCopy(InType);
  } else if ( StringEqualNoCase(InType, "days") ) {
    if ( MainLimitType ) {
      FreeMemory(MainLimitType);
    }
    MainLimitType = StringCopy(InType);
  } else if ( StringEqualNoCase(InType, "size") ) {
    if ( MainLimitType ) {
      FreeMemory(MainLimitType);
    }
    MainLimitType = StringCopy(InType);
  } else if ( StringEqualNoCase(InType, "hours") ) {
    if ( MainLimitType ) {
      FreeMemory(MainLimitType);
    }
    MainLimitType = StringCopy(InType);
  }
}
