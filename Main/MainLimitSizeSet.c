/*****************************************************************************!
 * Function : MainLimitSizeSet
 *****************************************************************************/
void
MainLimitSizeSet
(int InValue)
{
  if ( StringEqualNoCase(MainLimitType, "count") ) {
    if ( InValue < MainMinLimitCount || InValue >= MainMaxLimitCount ) {
      return;
    }
    MainLimitCount = InValue;
  } else if ( StringEqualNoCase(MainLimitType, "days") ) {
    if ( InValue < MainMinLimitDays || InValue >= MainMaxLimitDays ) {
      return;
    }
    MainLimitDays = InValue;
  } else if ( StringEqualNoCase(MainLimitType, "size") ) {
    if ( InValue < MainMinLimitSize || InValue >= MainMaxLimitSize ) {
      return;
    }
    MainLimitSize = InValue;
  } else if ( StringEqualNoCase(MainLimitType, "hours") ) {
    if ( InValue < MainMinLimitHours || InValue >= MainMaxLimitHours ) {
      return;
    }
    MainLimitHours = InValue;
  }
}
