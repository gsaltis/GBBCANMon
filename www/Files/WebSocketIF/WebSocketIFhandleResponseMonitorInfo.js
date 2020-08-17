/*****************************************************************************!
 * Function : WebSocketIFHandleResponseMonitorInfo
 *****************************************************************************/
function
WebSocketIFHandleResponseMonitorInfo
(InMonitorInfo)
{
  document.getElementById("MessageCount").innerHTML = InMonitorInfo.messagecount;
  document.getElementById("MonitorStatus").innerHTML = InMonitorInfo.monitorstatus;
  document.getElementById("MonitorFilename").innerHTML = InMonitorInfo.monitorfilename;
  document.getElementById("MonitorStartTime").innerHTML = InMonitorInfo.monitorstarttime;
  setTimeout(function() { WebSocketIFRequestMonitorInfo(); }, 5000);
}
