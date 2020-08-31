/*****************************************************************************!
 * Function : CBGetSystemDate
 *****************************************************************************/
function CBGetSystemDate()
{
  var                                   di;
  di = document.getElementById("SetDateInput");
  da = new Date(Date.now());

  document.getElementById("ChangeDateButton").style.visibility = "visible";
  document.getElementById("ClearDateButton").style.visibility = "visible";
  minutes = da.getMinutes().toString();
  hours = da.getHours().toString();

  day = da.getDate().toString();
  m = da.getMonth() + 1;
  month = m.toString();
  year = da.getFullYear();

  if ( minutes.length < 2 ) {
	minutes = "0" + minutes;
  }
  if ( hours.length < 2 ) {
	hours = "0" + hours;
  }
  d = month + "/" + day + "/" + year + "  " + hours  + ":" + minutes;

  di.value = d;
}
  
