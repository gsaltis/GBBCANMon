/*****************************************************************************!
 * Function : WebSocketIFHandleGetLimitsResponse
 *****************************************************************************/
function WebSocketIFHandleGetLimitsResponse(InPacket)
{
  var                                   d;
  
  MainLimitType = InPacket.limittype;
  d = document.getElementById("LimitTypeSelect").value = MainLimitType;
  if ( MainLimitType == "hours" ) {
    MainLimitHours = InPacket.hours;
    document.getElementById("LimitTypeHours").value = MainLimitHours;
  } else if ( MainLimitType == "days" ) {
    MainLimitDays = InPacket.days;
    document.getElementById("LimitTypeDays").value = MainLimitDays;
  } else if ( MainLimitType == "size" ) {
	MainLimitSize = InPacket.count;
    document.getElementById("LimitTypesSize").value = MainLimitSize;
  } else if ( MainLimitType == "count" ) {
	MainLimitCount = InPacket.count;
    document.getElementById("LimitTypeCount").value = MainLimitCount;
  }
  WebSocketIFRequestMonitorInfo();
}

