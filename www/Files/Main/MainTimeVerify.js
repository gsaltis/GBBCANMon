/*****************************************************************************!
 * Function : MainTimeVerify
 *****************************************************************************/
function
MainTimeVerify(InString)
{
  var                                   a;
  var                                   hour, minute, second;
  
  if ( null == InString ) {
	return MainTimeInvalidFormat;
  }

  a = InString.split(':');
  if ( a.length != 2 && a.length != 3 ) {
	return MainTimeInvalidFormat;
  }

  for ( i = 0 ; i < a.length; i++ ) {
    if ( a[i] == "" ) {
      return MainTimeInvalidFormat;
    }
  }
  second = 0;
  hour = parseInt(a[0], 10);
  minute = parseInt(a[1], 10);
  if ( a.length == 3 ) {
	second = parseInt(a[2], 10);
  }
  if ( hour > 23 ) {
	return MainTimeInvalidHour;
  }
  if ( minute > 59 ) {
	return MainTimeInvalidMinute;
  }
  if ( second > 59 ) {
	return MainTimeInvalidSecond;
  }
  return MainTimeOK;
}

