/*****************************************************************************!
 * Function : MainDateTimeVerify
 *****************************************************************************/
function
MainDateTimeVerify(InString)
{
  var                                   a;
  var					rvalue

  a = InString.split(/\s+/);
  if ( a.length > 2 ) {
    return MainDateTimeInvalidFormat;
  }
   
  rvalue = MainDateVerify(a[0]);
  if ( rvalue != MainDateOK ) {
    return rvalue;
  }
  if ( a.length == 2 ) {
    rvalue = MainTimeVerify(a[1]);
    if ( rvalue != MainTimeOK ) {
      return rvalue;
    }
  }
  return MainDateTimeOK;
}

