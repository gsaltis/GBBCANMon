/*****************************************************************************!
 * Function : MainDateVerify
 *****************************************************************************/
function MainDateVerify
(InDateString)
{
  var                                   a, day, month, year;
  var                                   d;

  d = new Date(Date.now());  

  if ( null == InDateString ) {
    return MainDateInvalidFormat;
  }
  a = InDateString.split('/');
  if ( a.length != 2 && a.length != 3 ) {
    return MainDateInvalidFormat;
  }

  year = d.getFullYear();
  month = parseInt(a[0], 10);
  day = parseInt(a[1], 10);
  if ( a.length == 3 ) {
    year = parseInt(a[2], 10);
    if ( year < 100 ) {
	  if ( year > 70 ) {
		year += 1900;
      } else {
		year += 2000;
	  }
    } 
  }
  if ( month < 1 || month > 12 ) {
	return MainDateInvalidMonth;
  }
  if ( day < 1 || day > 31 || day < 28 ) {
    return MainDateInvalidDay;
  }
  if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
	if ( day > 31 ) {
	  return MainDateInvalidDay;
    }
  } else if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
	if ( day > 30 ) {
	  return MainDateInvalidDay;
	}
  } else if ( month == 2 ) {
    if ( year % 4 ) {
	  if ( day > 28 ) {
		return MainDateInvalidDay;
	  }
    } else if ( year % 400 == 0 ) {
	  if ( day > 28 ) {
		return MainDateInvalidDay;
	  }	
    } else if ( year % 100 == 0 ) {
	  if ( day > 29 ) {
		return MainDateInvalidDay;
	  }
	}
  }
  return MainDateOK;
}
