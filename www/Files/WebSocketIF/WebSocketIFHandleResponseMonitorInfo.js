/*****************************************************************************!
 * Function : WebSocketIFHandleResponseMonitorInfo
 *****************************************************************************/
function
WebSocketIFHandleResponseMonitorInfo
(InMonitorInfo)
{
  var                                   d;
 
  d = document.getElementById("MessageLimitValue");
  d.innerHTML = InMonitorInfo.messagelimitvalue;
  if ( InMonitorInfo.limitstatus == "OK" ) {
	d.className = "GeneralData DataLine1 MessageCountOK";
  } else {
	d.className = "GeneralData DataLine1 MessageCountAT";
  }
  document.getElementById("MessageLimitLabel").innerHTML = InMonitorInfo.messagelimitlabel;
  document.getElementById("MonitorStatus").innerHTML = InMonitorInfo.monitorstatus;
  document.getElementById("MonitorFilename").innerHTML = InMonitorInfo.monitorfilename;
  document.getElementById("MonitorStartTime").innerHTML = InMonitorInfo.monitorstarttime;
  document.getElementById("VersionNumber").innerHTML = InMonitorInfo.version;
  setTimeout(function() { WebSocketIFRequestMonitorInfo(); }, 5000);
}
