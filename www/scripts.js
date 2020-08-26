// FILE: ./Files/Main/MainDisplayMessage.js
/*****************************************************************************!
 * Function : MainDisplayMessage
 *****************************************************************************/
function
MainDisplayMessage(InMessage)
{
  MainDisplayMessageColor(InMessage, "#000000"); 
}

// FILE: ./Files/Main/MainDisplayTimedMessage.js
/*****************************************************************************!
 * Function : MainDisplayTimedMessage
 *****************************************************************************/
function
MainDisplayTimedMessage(InMessage, InTimeout)
{
  var					messageArea;

  MainMessageTimerID = setInterval(MainMessageTimeout, InTimeout * 1000);
  messageArea = document.getElementById("MessageLine");
  messageArea.innerHTML = InMessage;
}

// FILE: ./Files/Main/MainHideBlocker.js
/*****************************************************************************!
 * Function : MainHideBlocker
 *****************************************************************************/
function
MainHideBlocker()
{
  document.getElementById("MainBlocker").style.visibility = "hidden";
}

// FILE: ./Files/Main/MainMessageTimeout.js
/*****************************************************************************!
 * Function : MainMessageTimeout
 *****************************************************************************/
function
MainMessageTimeout()
{
  clearInterval(MainMessageTimerID)
  document.getElementById("MessageLine").innerHTML = "";
  MainMessageTimerID = null;
}

// FILE: ./Files/Main/MainResizeBody.js
/*****************************************************************************!
 * Function : MainResizeBody
 *****************************************************************************/
function
MainResizeBody
(InEvent)
{
  var					mainArea, clientWidth, clientHeight;
  var					i, bay, locationInfo;

  mainArea = document.getElementById("BayDisplayArea");

  clientWidth = mainArea.clientWidth;
  clientHeight = mainArea.clientHeight;

  console.log(clientWidth, clientHeight);

  for (i = 0; i < mainArea.children.length; i++) {
    bay = mainArea.children[i];
    BayResize(bay);
    locationInfo = GetPanelPositionsSizes(bay);
    for ( j = 0; j < bay.children.length; j++ ) {
      panel = bay.children[j];
      if ( panel.dataType == "EmptyPanel" || panel.dataType == "Panel" ) {
        panel.style.width = locationInfo.panelwidth;
        panel.style.height = locationInfo.panelheight;
        panel.style.top = locationInfo.panelYs[panel.dataIndex];
        n = locationInfo.panelXs[(panel.dataIndex - 1) % 2];
        panel.style.left = n;
      }
    }
  }
}
// FILE: ./Files/Main/MainInitializeDisplay.js
/*****************************************************************************!
 * Function : MainInitializeDisplay
 *****************************************************************************/
function
MainInitializeDisplay()
{
  var					name;
  name = null;

  if ( MainBays.length > 0 ) {
    name = MainBays[0].type;
  }
  
  BayTypesListPopulate(name);
}

// FILE: ./Files/Main/MainDisplayMessageColor.js
/*****************************************************************************!
 * Function : MainDisplayMessageColor
 *****************************************************************************/
function
MainDisplayMessageColor
(InMessage, InColor)
{
  var					messageArewa;
  
  messageArea = document.getElementById("MessageLine");
  messageArea.style.color = InColor;
  MainDisplayTimedMessage(InMessage, MAIN_DEFAULT_MESSAGE_TIME);
}
// FILE: ./Files/Main/MainHideLimitButtons.js
/*****************************************************************************!
 * Function : MainHideLimitButtons
 *****************************************************************************/
function MainHideLimitButtons()
{
  document.getElementById("SetLimitButton").style.visibility = "hidden";
  document.getElementById("ClearLimitButton").style.visibility = "hidden";
}
// FILE: ./Files/Main/MainDisplayBlocker.js
/*****************************************************************************!
 * Function : MainDisplayBlocker
 *****************************************************************************/
function
MainDisplayBlocker()
{
  document.getElementById("MainBlocker").style.visibility = "visible";
}

// FILE: ./Files/Main/MainHideTypeElements.js
/*****************************************************************************!
 * Function : MainHideTypeElements
 *****************************************************************************/
function MainHideTypeElements()
{
  var                                   elementNameBases = [
    "Days", "Hours", "Size", "Count"
  ]

  // Hide all the inputs and labels
  for (i = 0; i < elementNameBases.length; i++) {
    d1 = document.getElementById("LimitType" + elementNameBases[i]);
    d2 =  document.getElementById("LimitType" + elementNameBases[i] + "Label");
    d1.style.visibility = "hidden";
    d2.style.visibility = "hidden";
    d1.parentElement.className = ""
  }
}

// FILE: ./Files/Main/MainShowLimitButtons.js
/*****************************************************************************!
 * Function : MainShowLimitButtons
 *****************************************************************************/
function MainShowLimitButtons()
{
  document.getElementById("SetLimitButton").style.visibility = "visible";
  document.getElementById("ClearLimitButton").style.visibility = "visible";
}
// FILE: ./Files/Main/Main.js
/*****************************************************************************
 * FILE NAME    : script.js
 * DATE         : June 11 2020
 * PROJECT      : BDFB Simulator
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Local Data
 *****************************************************************************/
var MAIN_DEFAULT_MESSAGE_TIME		= 10;

var MainBayTypes 			= null;
var MainPanelTypes			= null;
var MainFuseBreakerTypes		= null;
var MainBays				= [];
var MainDeviceDefs			= null;
var MainMessageTimerID			= null;
var MainLimitType			= "none";
var MainLimitHours			= 0;
var MainLimitDays			= 0;
var MainLimitCount			= 0;
var MainLimitSize			= 0;
// FILE: ./Files/Main/MainInitialize.js
/*****************************************************************************!
 * Function : MainInitialize
 *****************************************************************************/
function
MainInitialize()
{
  var                                   d, i;
  var                                   option;

  WebSocketIFInitialize();

  d = document.getElementById("LimitTypeHours");

  for ( i = 1 ; i <= 96; i++ ) {
    option = document.createElement("option");
    option.value = i;
    option.innerHTML = i;
    d.appendChild(option);
  }

  d = document.getElementById("LimitTypeSize");
  for ( i = 10; i <= 500; i += 10 ) {
	option = document.createElement("option");
	option.value = i;
 	option.innerHTML = i;
	d.appendChild(option)
  }
}

// FILE: ./Files/CallBacks/CBClearLimit.js
/*****************************************************************************!
 * Function : CBClearLimits
 *****************************************************************************/
function CBClearLimits()
{
  MainHideLimitButtons();
  MainHideTypeElements();
}

// FILE: ./Files/CallBacks/CBMonitorToggle.js
/*****************************************************************************!
 * Function : CBMonitorToggle
 *****************************************************************************/
function
CBMonitorToggle
()
{
  WebSocketIFSendSimpleRequest("monitortoggle");
}

// FILE: ./Files/CallBacks/CBLimitTypeChange.js
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
  console.log("Change : " + value);

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
  d1.parentElement.className = "GeneralData2 DataLine5";
  MainShowLimitButtons();
}

// FILE: ./Files/CallBacks/CBLimitDaysChange.js
/*****************************************************************************!
 * Function : CBLimitDaysChange
 *****************************************************************************/
function CBLimitDaysChange()
{

}
// FILE: ./Files/CallBacks/CBLimitTypeSelect.js
/*****************************************************************************!
 * Function : CBLimitTypeSelect
 *****************************************************************************/
function CBLimitTypeSelect(event)
{
  CBLimitTypeChange();
}
// FILE: ./Files/CallBacks/CBSetLimit.js
/*****************************************************************************!
 * Function : CBSetLimit
 *****************************************************************************/
function CBSetLimit()
{
  MainHideLimitButtons();
  MainHideTypeElements();
}

// FILE: ./Files/CallBacks/CBPrepareOutputFilename.js
/*****************************************************************************!
 * Function : CBPrepareDownloadFilename
 *****************************************************************************/
function
CBPrepareDownloadFilename
()
{
  var					aref;

  aref = document.getElementById("DownloadFilename").children[0];

  aref.innerHTML = "";
  aref.href = "";
  WebSocketIFSendSimpleRequest("preparedownloadfilename");
}

// FILE: ./Files/WebSocketIF/WebSocketIFHandleRemovePanelResponse.js
/*****************************************************************************!
 * Function : WebSocketIFHandleRemovePanelResponse
 *****************************************************************************/
function
WebSocketIFHandleRemovePanelResponse
(InID, InMessage, InBayIndex, InPanelIndex)
{
  RemovePanel(InBayIndex, InPanelIndex);
  MainDisplayMessageColor(InMessage, "#080");

  bay = document.getElementById("Bay " + InBayIndex);
  locationInfo = GetPanelPositionsSizes(bay);

  CreateEmptyPanel(bay, InPanelIndex, 
                   locationInfo.panelXs[(InPanelIndex - 1) % 2], locationInfo.panelYs[InPanelIndex],
                   locationInfo.panelwidth, locationInfo.panelheight); 
}

// FILE: ./Files/WebSocketIF/WebSocketIFInitialize.js
/*****************************************************************************!
 * Function : WebSocketIFInitialize
 *****************************************************************************/
function 
WebSocketIFInitialize()
{
  var hostAddress = "ws://" + WebSocketIFAddress + ":" + WebSocketIFPort; 

  console.log(hostAddress);
  WebSocketIFConnection = new WebSocket(hostAddress);

  WebSocketIFConnection.onopen = function () {
    WebSocketIFSendSimpleRequest("getlimits"); 
    MainDisplayMessage("Connected");
  };

  // Log errors
  WebSocketIFConnection.onerror = function (error) {
  };

  // 
  WebSocketIFConnection.onclose = function() {
  }
  
  // Log messages from the server
  WebSocketIFConnection.onmessage = function (e) {
    WebSocketIFHandleInputPacket(e.data);
  };
}

// FILE: ./Files/WebSocketIF/WebSocketIFHandleBayRegValues.js
/*****************************************************************************!
 * Function : WebSocketIFHandleBayRegValues
 *****************************************************************************/
function 
WebSocketIFHandleBayRegValues
(InPacket)
{
  var					bay;
  var					i;

  bay = BayFindByIndex(InPacket.bayindex);
  if ( null == bay ) {
    return;
  }
  bay.registers = InPacket.registers;
  for (i = 0; i < bay.registers.length; i++) {
    input = document.getElementById("RegInput " + bay.registers[i].valuetype);
    if ( input ) {
      input.value = bay.registers[i].value;
    }
  }
}


// FILE: ./Files/WebSocketIF/WebSocketIFRequestBayTypes.js
/*****************************************************************************!
 * Function : WebSocketIFRequestGetBayTypes
 *****************************************************************************/
function
WebSocketIFRequestGetBayTypes()
{
   WebSocketIFSendSimpleRequest("getbaytypes");
}


// FILE: ./Files/WebSocketIF/WebSocketIFHandleResponsePanelTypes.js
/*****************************************************************************!
 * Function : WebSocketIFHandleResponsePanelTypes
 *****************************************************************************/
function
WebSocketIFHandleResponsePanelTypes(InPanelTypes)
{
  MainPanelTypes = InPanelTypes;
}

// FILE: ./Files/WebSocketIF/WebSocketIFSendSimpleRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendSimpleRequest
 *****************************************************************************/
function
WebSocketIFSendSimpleRequest(InRequest)
{
  var                           request = {};

  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.type = InRequest;
  request.body = "";

  WebSocketIFSendGeneralRequest(request);
}

// FILE: ./Files/WebSocketIF/WebSocketIFHandleResponsePrepareDownloadFile.js
/*****************************************************************************!
 * Function : WebSocketIFHandleResponsePrepareDownloadFile
 *****************************************************************************/
function
WebSocketIFHandleResponsePrepareDownloadFile
(InPacket)
{
  var					aref;

  aref = document.getElementById("DownloadFilename").children[0];

  aref.href = InPacket.linkname;
  aref.innerHTML = InPacket.filename;

  for (i = 0 ; i < InPacket.archivedfiles.length; i++) {
    aref = document.getElementById("DownloadFilename" + (i + 1)).children[0];
	aref.innerHTML = InPacket.archivedfiles[i];
	aref.href = InPacket.archivedfiles[i];
  }
  for ( ; i < 5 ; i++ ) {
    aref = document.getElementById("DownloadFilename" + (i + 1)).children[0];
    aref.innerHTML = "";
	aref.href = "";
  }
}
// FILE: ./Files/WebSocketIF/WebSocketIFSendDeviceDefRegRequestNext.js
/*****************************************************************************!
 * Function : WebSocketIFSendDeviceDefRegRequestNext
 *****************************************************************************/
function
WebSocketIFSendDeviceDefRegRequestNext
()
{
  WebSocketIFDeviceIndex++;
  if ( WebSocketIFDeviceIndex >= MainDeviceDefs.length ) {
    WebSocketIFSendSimpleRequest("getbays");
  } else {
    WebSocketIFSendDeviceDefRegRequest();
  }
}


// FILE: ./Files/WebSocketIF/WebSocketIFSendDeviceDegRegRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendDeviceDefRegRequest 
 *****************************************************************************/
function
WebSocketIFSendDeviceDefRegRequest
()
{
  var                           request = {};

  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.devicename = MainDeviceDefs[WebSocketIFDeviceIndex].name;
  request.type = "getdeviceregs";
  request.body = "";

  WebSocketIFSendGeneralRequest(request);
}


// FILE: ./Files/WebSocketIF/WebSocketIFHandleBays.js
/*****************************************************************************!
 * Function : WebSocketIFHandleBays
 *****************************************************************************/
function
WebSocketIFHandleBays(InBays)
{
  MainBays = InBays;
  BaysPopulateWindow();
}


// FILE: ./Files/WebSocketIF/WebSocketIFSendUpdatePanelRegValuesRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendUpdatePanelRegValuesRequest
 *****************************************************************************/
function
WebSocketIFSendUpdatePanelRegValuesRequest
(InBayIndex, InPanelIndex, InBody)
{
  var                           request = {};

  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.bayindex = InBayIndex;
  request.panelindex = InPanelIndex
  request.type = "setpanelregvalues";
  request.body = InBody;

  WebSocketIFSendGeneralRequest(request);
}
// FILE: ./Files/WebSocketIF/WebSocketIFHandleInputPacket.js
/*****************************************************************************!
 * Function : WebSocketHandlerInputPacket
 *****************************************************************************/
function
WebSocketIFHandleInputPacket(InData)
{
  var					requestpacket;

  requestpacket = JSON.parse(InData);
  if ( requestpacket.packettype == "response" ) {
    WebSocketIFHandleResponsePacket(requestpacket);
  }
}

// FILE: ./Files/WebSocketIF/WebSocketIFGetNextID.js
/*****************************************************************************!
 * Function : WebSocketIFGetNextID
 *****************************************************************************/
function 
WebSocketIFGetNextID()
{
  WebSocketIFNextID++;
  return WebSocketIFNextID;
}

// FILE: ./Files/WebSocketIF/WebSocketIFHandleDeviceRegs.js
/*****************************************************************************!
 * Function : WebSocketIFHandleDeviceRegs
 *****************************************************************************/
function
WebSocketIFHandleDeviceRegs
(InPacket)
{
  var					device;

  device = DeviceDefFindByName(InPacket.devicename);
  if ( device ) {
    device.registers = InPacket.registers;
  }
  WebSocketIFSendDeviceDefRegRequestNext();
}
 
// FILE: ./Files/WebSocketIF/WebSocketIFHandleDeviceDefs.js
/*****************************************************************************!
 * Function : WebSocketIFHandleDeviceDefs
 *****************************************************************************/
function
WebSocketIFHandleDeviceDefs(InDeviceDefs)
{
  MainDeviceDefs = InDeviceDefs;
}


// FILE: ./Files/WebSocketIF/WebSocketIF.js
/*****************************************************************************
 * FILE NAME    : WebSocketIF.js
 * DATE         : June 11 2020
 * PROJECT      : BDFB Simulator
 * COPYRIGHT    : Copyright (C) 2020 by Vertiv Company
 *****************************************************************************/

/*****************************************************************************!
 * Local Data 
 *****************************************************************************/
var WebSocketIFConnection = null;
var WebSocketIFNextID = 1;
var WebSocketIFDeviceIndex = 0;

// FILE: ./Files/WebSocketIF/WebSocketIFSendBayRegValuesRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendBayRegValuesRequest
 *****************************************************************************/
function
WebSocketIFSendBayRegValuesRequest(InBayIndex)
{
  var                           request = {};

  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.bayindex = InBayIndex;
  request.type = "getbayregvalues";
  request.body = "";

  WebSocketIFSendGeneralRequest(request);
}


// FILE: ./Files/WebSocketIF/WebSocketIFHandleResponsePacket.js
/*****************************************************************************!
 * Function : WebSocketIFHandleResponsePacket
 *****************************************************************************/
function
WebSocketIFHandleResponsePacket(InPacket)
{
  if ( InPacket.responseid != "OK" ) {
    MainDisplayMessage(InPacket.responsemessage);
    return;
  }
  if ( InPacket.type == "resmonitorinfo" ) {
    WebSocketIFHandleResponseMonitorInfo(InPacket.body.monitorinfo);
  } else if ( InPacket.type == "respreparedownloadfile"  ) {
    WebSocketIFHandleResponsePrepareDownloadFile(InPacket.body);
  } else if ( InPacket.type == "resgetlimits" ) {
	WebSocketIFHandleGetLimitsResponse(InPacket.body);
  }
}

// FILE: ./Files/WebSocketIF/WebSocketIFSendAddPanelRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendAddPanelRequest
 *****************************************************************************/
function
WebSocketIFSendAddPanelRequest
(InBayIndex, InPanelIndex, InListNumber)
{
  var						request;

  request = {};

  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.panelindex = InPanelIndex;
  request.bayindex = InBayIndex;
  request.type = "addpanel";
  request.body = {};
  request.body.listnumber = InListNumber
  request.body.panelindex = InPanelIndex;
  request.body.bayindex = InBayIndex;

  WebSocketIFSendGeneralRequest(request);
}
// FILE: ./Files/WebSocketIF/WebSocketIFSendDeviceDefRequestStart.js
/*****************************************************************************!
 * Function : WebSocketIFSendDeviceDefRegRequestStart
 *****************************************************************************/
function
WebSocketIFSendDeviceDefRegRequestStart
()
{
  WebSocketIFDeviceIndex = 0;
  WebSocketIFSendDeviceDefRegRequest();
}


// FILE: ./Files/WebSocketIF/WebSocketIFSendUpdateBayRegValuesRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendUpdateBayRegValuesRequest
 *****************************************************************************/
function
WebSocketIFSendUpdateBayRegValuesRequest
(InBayIndex, InBody)
{
  var                           request = {};

  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.bayindex = InBayIndex;
  request.type = "setbayregvalues";
  request.body = InBody;

  WebSocketIFSendGeneralRequest(request);
}
// FILE: ./Files/WebSocketIF/WebSocketIFSendRemovePanelRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendRemovePanelRequest
 *****************************************************************************/
function
WebSocketIFSendRemovePanelRequest
(InBayIndex, InPanelIndex)
{
  var					request;
  request = {};

  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.type = "removepanel";
  request.body = {};
  request.body.panelindex = InPanelIndex;
  request.body.bayindex = InBayIndex;

  WebSocketIFSendGeneralRequest(request); 

}

// FILE: ./Files/WebSocketIF/WebSocketIFHandlePanelRegValues.js
/*****************************************************************************!
 * Function : WebSocketIFHandlePanelRegValues
 *****************************************************************************/
function 
WebSocketIFHandlePanelRegValues
(InPacket)
{
  var					panel;
  var					i;

  bay = BayFindByIndex(InPacket.bayindex);

  if ( bay == null ) {
    return;
  }
  panel = BayFindPanelByIndex(bay, InPacket.panelindex);
  if ( null == panel ) {
    return;
  }
  panel.registers = InPacket.registers;
  for (i = 0; i < panel.registers.length; i++) {
    input = document.getElementById("RegInput " + panel.registers[i].valuetype);
    if ( input ) {
      input.value = panel.registers[i].value;
      input.dataOriginalValue = panel.registers[i].value;
    }
  }
}


// FILE: ./Files/WebSocketIF/WebSocketIFRequestMonitorInfo.js
/*****************************************************************************!
 * Function : WebSocketIFRequestMonitorInfo
 *****************************************************************************/
function
WebSocketIFRequestMonitorInfo
()
{
  WebSocketIFSendSimpleRequest("getmonitorinfo");
}

// FILE: ./Files/WebSocketIF/WebSocketIFHandleGetLimitsResponse.js
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

// FILE: ./Files/WebSocketIF/WebSocketIFSendGeneralRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendGeneralRequest
 *****************************************************************************/
function 
WebSocketIFSendGeneralRequest(InRequest) {
  if ( WebSocketIFConnection ) {
    WebSocketIFConnection.send(JSON.stringify(InRequest));
  }
}

// FILE: ./Files/WebSocketIF/WebSocketIFSendPanelRegValuesRequest.js
/*****************************************************************************!
 * Function : WebSocketIFSendPanelRegValuesRequest
 *****************************************************************************/
function
WebSocketIFSendPanelRegValuesRequest(InBayIndex, InPanelIndex)
{
  var                           request = {};

  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.panelindex = InPanelIndex;
  request.bayindex = InBayIndex;
  request.type = "getpanelregvalues";
  request.body = "";

  WebSocketIFSendGeneralRequest(request);
}


// FILE: ./Files/WebSocketIF/WebSocketIFHandleFuseBreakerTypes.js
/*****************************************************************************!
 * Function : WebSocketIFHandleFuseBreakerTypes
 *****************************************************************************/
function
WebSocketIFHandleFuseBreakerTypes(InFuseBreakerTypes)
{
  MainFuseBreakerTypes = InFuseBreakerTypes;
}

// FILE: ./Files/WebSocketIF/WebSocketIFhandleResponseMonitorInfo.js
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
// FILE: ./Files/WebSocketIF/WebSocketIFHandleResponseBays.js
/*****************************************************************************!
 * Function : WebSocketIFHandleResponseBayTypes
 *****************************************************************************/
function
WebSocketIFHandleResponseBayTypes(InBayTypes)
{
  MainBayTypes = InBayTypes;
}

// FILE: ./websocketinfo.js
var WebSocketIFAddress = "192.168.0.16";
var WebSocketIFPort = "8011";
