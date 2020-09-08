/*****************************************************************************!
 * Function : CANInterfaceThreadThrottleFile
 *****************************************************************************/
bool
CANInterfaceThreadThrottleFile
()
{
  int                                   m;

  if ( StringEqual(MainLimitType, "none") ) {
    return false;
  }

  if ( StringEqual(MainLimitType, "count") ) {
    if ( CANInterfaceMessagesCount >= MainLimitCount ) {
	  return true;
	}
    return false;
  } 

  if ( StringEqual(MainLimitType, "size") ) {
	m = MainLimitSize * 1000000;
	if ( MainLimitSizeRuntime >= m ) {
	  return true;
	}
    return false;
  } 

  if ( StringEqual(MainLimitType, "days") ) {
    time_t t = time(NULL);
    time_t t2 = t - MainStartTime;
    t2 /= (3600 * 24);
    if ( (int)t2 >= MainLimitDays ) {
	  return true;
    }
    return false;
  } 

  if ( StringEqual(MainLimitType, "hours") ) {
    time_t t = time(NULL);
    time_t t2 = t - MainStartTime;
    if ( (int)t2 >= (int)(MainLimitHours * 3600) ) {
	  return true;
    }
    return false;
  } 
  return false;
}
