/*****************************************************************************!
 * Function : CBLimitTypeChange
 *****************************************************************************/
function
CBLimitTypeChange()
{
  var                                   selector;
  var                                   value;
  var                                   i;

  selector = document.getElementById("LimitTypeSelect");
  value = selector.value;
  MainHideTypeElements();  

  // Show input and label for the selected one
  if ( value == "days" ) {
	d1 = document.getElementById("LimitTypeDays");
	d2 = document.getElementById("LimitTypeDaysLabel");
  } else if ( value == "hours" ) {
	d1 = document.getElementById("LimitTypeHours");
	d2 = document.getElementById("LimitTypeHoursLabel");
  } else if ( value == "size" ) {
	d1 = document.getElementById("LimitTypeSize");
	d2 = document.getElementById("LimitTypeSizeLabel");
  } else if ( value == "count" ) {
	d1 = document.getElementById("LimitTypeCount");
	d2 = document.getElementById("LimitTypeCountLabel");
  } else {
	return;
  }

  d1.style.visibility = "visible";
  d2.style.visibility = "visible";
  d1.parentElement.className = "GeneralData2 DataLine2";
  MainShowLimitButtons();
}

