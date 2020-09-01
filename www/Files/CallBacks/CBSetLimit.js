/*****************************************************************************!
 * Function : CBSetLimit
 *****************************************************************************/
function CBSetLimit()
{
  var                                   type;
  var                                   value;
 
  MainHideLimitButtons();
  MainHideTypeElements();

  type = document.getElementById("LimitTypeSelect").value;
  value = null;
  if ( type == "days" ) {
    value = document.getElementById("LimitTypeDays").value;
  } else if ( type == "hours" ) {
    value = document.getElementById("LimitTypeHours").value; 
  } else if ( type == "size" ) {
    value = document.getElementById("LimitTypeSize").value;
  } else if ( type == "count" ) {
    value = document.getElementById("LimitTypeCount").value;
  }

  WebSocketIFSendLimits(type, value);
  
}
  
