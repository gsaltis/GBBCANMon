/*****************************************************************************!
 * Function : MainSetTypeLimitValue
 *****************************************************************************/
function
MainSetTypeLimitValue
(InType, InValue)
{
  if ( InType == "days" ) {
    document.getElementById("LimitTypeDays").value = InValue;
  } else if ( InType == "hours" ) {
    document.getElementById("LimitTypeHours").value = InValue; 
  } else if ( InType == "size" ) {
    document.getElementById("LimitTypeSize").value = InValue;
  } else if ( InType == "count" ) {
    document.getElementById("LimitTypeCount").value = InValue;
  }
}
