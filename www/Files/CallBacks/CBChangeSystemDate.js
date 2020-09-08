/*****************************************************************************!
 * Function : CBChangeSystemDate
 *****************************************************************************/
function
CBChangeSystemDate()
{
  var                                   d, value, b;
  var									dm;

  dm = document.getElementById("SetDateMessage"); 
  d = document.getElementById("SetDateInput"); 
  value = d.value;
  b = MainDateTimeVerify(value);
  d.style.color = b ? "green" : "red";
  if ( b == MainDateTimeOK ) {
    document.getElementById("ClearDateButton").style.visibility = "hidden";
    document.getElementById("ChangeDateButton").style.visibility = "hidden";
    document.getElementById("SetDateInput").value = "";
	MainDisplayMessage("Date/Time OK");
	dm.innerHTML = "";
	WebSocketIFSendTimeStamp(value);
  } else {

	document.getElementById("SetDateInput").style.color = "red";
    switch (b) {
      case MainDateOK :
        break;
      case MainDateInvalidFormat :
		dm.innerHTML = "Invalid Date Format";
        break;
      case MainDateInvalidDay :
		dm.innerHTML = "Invalid Date Day";
        break;
      case MainDateInvalidMonth :
		dm.innerHTML = "Invalid Date Month";
        break;
      case MainDateInvalidYear :
		dm.innerHTML = "Invalid Date Year";
        break;
      case MainTimeOK :
		dm.innerHTML = "Time OK";
        break;
      case MainTimeInvalidFormat :
		dm.innerHTML = "Invalid Time Format";
        break;
      case MainTimeInvalidHour :
		dm.innerHTML = "Invalid Time Hour";
        break;
      case MainTimeInvalidMinute :
		dm.innerHTML = "Invalid Time Minute";
        break;
      case MainTimeInvalidSecond :
		dm.innerHTML = "Invalid Date Second";
        break;
      case MainDateTimeOK :
		dm.innerHTML = "Date/Time OK";
        break;
      case MainDateTimeInvalidFormat :
		dm.innerHTML = "Invalid Date/Time Format";
        break;
    }
  }
  document.getElementById("MessageLine").value =value;
}

