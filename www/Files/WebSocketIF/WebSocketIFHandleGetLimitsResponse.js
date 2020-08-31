/*****************************************************************************!
 * Function : WebSocketIFHandleGetLimitsResponse
 *****************************************************************************/
function WebSocketIFHandleGetLimitsResponse(InPacket)
{
  var                                   d;
  
  MainLimitType = InPacket.limittype;
  d = document.getElementById("LimitTypeSelect").value = MainLimitType;

  MainLimitHours = InPacket.hours;
  document.getElementById("LimitTypeHours").value = MainLimitHours;

  MainLimitDays = InPacket.days;
  document.getElementById("LimitTypeDays").value = MainLimitDays;

  MainLimitSize = InPacket.size;
  document.getElementById("LimitTypeSize").value = MainLimitSize;

  MainLimitCount = InPacket.count;
  document.getElementById("LimitTypeCount").value = MainLimitCount;

  WebSocketIFRequestMonitorInfo();
}

