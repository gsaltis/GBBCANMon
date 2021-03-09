// FILE: ./Files/CallBacks/CBChangeSystemDate.js
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


// FILE: ./Files/CallBacks/CBClearArchiveFiles.js
/*****************************************************************************!
 * Function : CBClearArchiveFiles
 *****************************************************************************/
function
CBClearArchiveFiles
()
{
  WebSocketIFSendRemoveArchivedFiles();
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


// FILE: ./Files/CallBacks/CBClearSystemDate.js
/*****************************************************************************!
 * Function : CBClearSystemDate
 *****************************************************************************/
function
CBClearSystemDate()
{
  document.getElementById("ChangeDateButton").style.visibility = "hidden";
  document.getElementById("ClearDateButton").style.visibility = "hidden";
  document.getElementById("SetDateInput").value = "";
}


// FILE: ./Files/CallBacks/CBConfigPressed.js
/*****************************************************************************!
 * Function : CBConfigPressed
 *****************************************************************************/
function
CBConfigPressed
()
{
  var                                   sectionHeight;
  var                                   dataArea;
  var                                   configSection;

  configSection = document.getElementById("ConfigSection");
  dataArea = document.getElementById("DataArea");
  if ( configSection.dataOpen ) {
    configSection.style.height = "30px";
    configSection.dataOpen = false;
    dataArea.style.height = "420px";
  } else {
    configSection.style.height = "90px";
    configSection.dataOpen = true;
    dataArea.style.height = "480px";
  }
}

  

// FILE: ./Files/CallBacks/CBDataAreaTransitionEnd.js
/*****************************************************************************!
 * Function : CBDataAreaTransitionEnd
 *****************************************************************************/
function
CBDataAreaTransitionEnd
()
{
  var                                   configSection;
  var                                   d;

  configSection = document.getElementById("ConfigSection");
  d = document.getElementById("DataArea");
  console.log(configSection.dataOpen);
  if ( configSection.dataOpen ) {
    console.log("");
    document.getElementById("ConfigTypeLabel").style.visibility = "visible";
    document.getElementById("ConfigTypeSelectContainer").style.visibility = "visible";
    document.getElementById("ConfigDefinitionsLabel").style.visibility = "visible";
  }
}

// FILE: ./Files/CallBacks/CBDataAreaTransitionStart.js
/*****************************************************************************!
 * Function : CBDataAreaTransitionStart
 *****************************************************************************/
function
CBDataAreaTransitionStart
()
{
  var                                   configSection;
  var                                   d;

  configSection = document.getElementById("ConfigSection");
  d = document.getElementById("DataArea");
  console.log(configSection.dataOpen);
  document.getElementById("ConfigTypeLabel").style.visibility = "hidden";
  document.getElementById("ConfigTypeSelectContainer").style.visibility = "hidden"; 
 document.getElementById("ConfigDefinitionsLabel").style.visibility = "hidden";
}

// FILE: ./Files/CallBacks/CBDateInputChanged.js
/*****************************************************************************!
 * Function : CBDateInputChanged 
 *****************************************************************************/
function
CBDateInputChanged()
{
  document.getElementById("ChangeDateButton").style.visibility = "visible";
  document.getElementById("ClearDateButton").style.visibility = "visible";
} 

// FILE: ./Files/CallBacks/CBGetSystemDate.js
/*****************************************************************************!
 * Function : CBGetSystemDate
 *****************************************************************************/
function CBGetSystemDate()
{
  var                                   di;
  var                                   hours, minutes, seconds;
  var                                   day, month, year, m;

  di = document.getElementById("SetDateInput");
  da = new Date(Date.now());

  document.getElementById("ChangeDateButton").style.visibility = "visible";
  document.getElementById("ClearDateButton").style.visibility = "visible";
  minutes = da.getMinutes().toString();
  hours = da.getHours().toString();
  seconds = da.getSeconds().toString();

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
  if ( seconds.length < 2 ) {
	seconds = "0" + seconds;
  }
  d = month + "/" + day + "/" + year + "  " + hours  + ":" + minutes + ":" + seconds;

  di.value = d;
}
  

// FILE: ./Files/CallBacks/CBLimitDaysChange.js
/*****************************************************************************!
 * Function : CBLimitDaysChange
 *****************************************************************************/
function CBLimitDaysChange()
{

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


// FILE: ./Files/CallBacks/CBLimitTypeSelect.js
/*****************************************************************************!
 * Function : CBLimitTypeSelect
 *****************************************************************************/
function CBLimitTypeSelect(event)
{
  CBLimitTypeChange();
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


// FILE: ./Files/CallBacks/CBSetLimit.js
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


var MainDateOK				= 10;
var MainDateInvalidFormat		= 11;
var MainDateInvalidDay			= 12;
var MainDateInvalidMonth		= 13;
var MainDateInvalidYear			= 14;
var MainTimeOK				= 20;
var MainTimeInvalidFormat		= 21;
var MainTimeInvalidHour			= 22;
var MainTimeInvalidMinute		= 23;
var MainTimeInvalidSecond		= 24;
var MainDateTimeOK			= 30;
var MainDateTimeInvalidFormat		= 31;

// FILE: ./Files/Main/MainDateTimeVerify.js
/*****************************************************************************!
 * Function : MainDateTimeVerify
 *****************************************************************************/
function
MainDateTimeVerify(InString)
{
  var                                   a;
  var					rvalue

  a = InString.split(/\s+/);
  if ( a.length > 2 ) {
    return MainDateTimeInvalidFormat;
  }
   
  rvalue = MainDateVerify(a[0]);
  if ( rvalue != MainDateOK ) {
    return rvalue;
  }
  if ( a.length == 2 ) {
    rvalue = MainTimeVerify(a[1]);
    if ( rvalue != MainTimeOK ) {
      return rvalue;
    }
  }
  return MainDateTimeOK;
}


// FILE: ./Files/Main/MainDateVerify.js
/*****************************************************************************!
 * Function : MainDateVerify
 *****************************************************************************/
function MainDateVerify
(InDateString)
{
  var                                   a, day, month, year;
  var                                   d;

  d = new Date(Date.now());  

  if ( null == InDateString ) {
    return MainDateInvalidFormat;
  }
  a = InDateString.split('/');
  if ( a.length != 2 && a.length != 3 ) {
    return MainDateInvalidFormat;
  }

  year = d.getFullYear();
  month = parseInt(a[0], 10);
  day = parseInt(a[1], 10);
  if ( a.length == 3 ) {
    year = parseInt(a[2], 10);
    if ( year < 100 ) {
	  if ( year > 70 ) {
		year += 1900;
      } else {
		year += 2000;
	  }
    } 
  }
  if ( month < 1 || month > 12 ) {
	return MainDateInvalidMonth;
  }
  if ( day < 1 || day > 31 ) {
    return MainDateInvalidDay;
  }
  if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
	if ( day > 31 ) {
	  return MainDateInvalidDay;
    }
  } else if ( month == 4 || month == 6 || month == 9 || month == 11 ) {
	if ( day > 30 ) {
	  return MainDateInvalidDay;
	}
  } else if ( month == 2 ) {
    if ( year % 4 ) {
	  if ( day > 28 ) {
		return MainDateInvalidDay;
	  }
    } else if ( year % 400 == 0 ) {
	  if ( day > 28 ) {
		return MainDateInvalidDay;
	  }	
    } else if ( year % 100 == 0 ) {
	  if ( day > 29 ) {
		return MainDateInvalidDay;
	  }
	}
  }
  return MainDateOK;
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


// FILE: ./Files/Main/MainDisplayMessage.js
/*****************************************************************************!
 * Function : MainDisplayMessage
 *****************************************************************************/
function
MainDisplayMessage(InMessage)
{
  MainDisplayMessageColor(InMessage, "#000000"); 
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


// FILE: ./Files/Main/MainHideLimitButtons.js
/*****************************************************************************!
 * Function : MainHideLimitButtons
 *****************************************************************************/
function MainHideLimitButtons()
{
  document.getElementById("SetLimitButton").style.visibility = "hidden";
  document.getElementById("ClearLimitButton").style.visibility = "hidden";
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

  d = document.getElementById("DataArea");
  d.addEventListener("transitionend", CBDataAreaTransitionEnd, true);
  d.addEventListener("transitionstart", CBDataAreaTransitionStart, true);
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

// FILE: ./Files/Main/MainSetTypeLimitValue.js
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

// FILE: ./Files/Main/MainShowLimitButtons.js
/*****************************************************************************!
 * Function : MainShowLimitButtons
 *****************************************************************************/
function MainShowLimitButtons()
{
  document.getElementById("SetLimitButton").style.visibility = "visible";
  document.getElementById("ClearLimitButton").style.visibility = "visible";
}

// FILE: ./Files/Main/MainTimeVerify.js
/*****************************************************************************!
 * Function : MainTimeVerify
 *****************************************************************************/
function
MainTimeVerify(InString)
{
  var                                   a;
  var                                   hour, minute, second;
  
  if ( null == InString ) {
	return MainTimeInvalidFormat;
  }

  a = InString.split(':');
  if ( a.length != 2 && a.length != 3 ) {
	return MainTimeInvalidFormat;
  }

  for ( i = 0 ; i < a.length; i++ ) {
    if ( a[i] == "" ) {
      return MainTimeInvalidFormat;
    }
  }
  second = 0;
  hour = parseInt(a[0], 10);
  minute = parseInt(a[1], 10);
  if ( a.length == 3 ) {
	second = parseInt(a[2], 10);
  }
  if ( hour > 23 ) {
	return MainTimeInvalidHour;
  }
  if ( minute > 59 ) {
	return MainTimeInvalidMinute;
  }
  if ( second > 59 ) {
	return MainTimeInvalidSecond;
  }
  return MainTimeOK;
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



// FILE: ./Files/WebSocketIF/WebSocketIFHandleDeviceDefs.js
/*****************************************************************************!
 * Function : WebSocketIFHandleDeviceDefs
 *****************************************************************************/
function
WebSocketIFHandleDeviceDefs(InDeviceDefs)
{
  MainDeviceDefs = InDeviceDefs;
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
 

// FILE: ./Files/WebSocketIF/WebSocketIFHandleFuseBreakerTypes.js
/*****************************************************************************!
 * Function : WebSocketIFHandleFuseBreakerTypes
 *****************************************************************************/
function
WebSocketIFHandleFuseBreakerTypes(InFuseBreakerTypes)
{
  MainFuseBreakerTypes = InFuseBreakerTypes;
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



// FILE: ./Files/WebSocketIF/WebSocketIFHandleRemoveArchivedFiles.js
/*****************************************************************************!
 * Function : WebSocketIFHandleRemoveArchivedFiles
 *****************************************************************************/
function
WebSocketIFHandleRemoveArchivedFiles
(InPacket)
{
  var                                   i, name;
  MainDisplayMessage(InPacket.responsemessage);
  for (i = 0 ; i < 5; i++ ) {
    name = "DownloadFilename" + (i + 1);
    document.getElementById(name).innerHTML = "";
  }
  document.getElementById("ClearArchiveButton").style.visibility = "hidden";
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


// FILE: ./Files/WebSocketIF/WebSocketIFHandleResponseBays.js
/*****************************************************************************!
 * Function : WebSocketIFHandleResponseBayTypes
 *****************************************************************************/
function
WebSocketIFHandleResponseBayTypes(InBayTypes)
{
  MainBayTypes = InBayTypes;
}


// FILE: ./Files/WebSocketIF/WebSocketIFHandleResponseMonitorInfo.js
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
  } else if ( InPacket.type == "ressettimestamp" ) {
	WebSocketIFHandleSetTimeResponse(InPacket.body);
  } else if ( InPacket.type == "ressetlimits" ) {
	WebSocketIFHandleSetLimitsResponse(InPacket.body);
  } else if ( InPacket.type == "resremovearchivefiles" ) {
	WebSocketIFHandleRemoveArchivedFiles(InPacket);
  }
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


// FILE: ./Files/WebSocketIF/WebSocketIFHandleResponsePrepareDownloadFile.js
/*****************************************************************************!
 * Function : WebSocketIFHandleResponsePrepareDownloadFile
 *****************************************************************************/
function
WebSocketIFHandleResponsePrepareDownloadFile
(InPacket)
{
  var									aref; 
  var									d;

  aref = document.getElementById("DownloadFilename").children[0];

  aref.href = InPacket.linkname;
  aref.innerHTML = InPacket.filename;

  d = document.getElementById("ClearArchiveButton");
  if ( InPacket.archivedfiles.length == 0 ) {
	d.style.visibility = "hidden";
  } else {
	d.style.visibility = "visible";
  }
    
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

// FILE: ./Files/WebSocketIF/WebSocketIFHandleSetLimitsResponse.js
/*****************************************************************************!
 * Function : WebSocketIFHandleSetLimitsResponse
 *****************************************************************************/
function
WebSocketIFHandleSetLimitsResponse
(InResponse)
{
  console.log(InResponse);
  MainDisplayMessage(InResponse.message);
  document.getElementById("LimitTypeSelect").value = InResponse.type;
  MainSetTypeLimitValue(InResponse.type, InResponse.value);
}

// FILE: ./Files/WebSocketIF/WebSocketIFHandleSetTimeResponse.js
/*****************************************************************************!
 * Function : WebSocketIFHandleSetTimeResponse
 *****************************************************************************/
function
WebSocketIFHandleSetTimeResponse
(InResponse)
{
  MainDisplayMessage(InResponse.message);
}

// FILE: ./Files/WebSocketIF/WebSocketIFInitialize.js
/*****************************************************************************!
 * Function : WebSocketIFInitialize
 *****************************************************************************/
function 
WebSocketIFInitialize()
{
  var hostAddress = "ws://" + WebSocketIFAddress + ":" + WebSocketIFPort; 

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


// FILE: ./Files/WebSocketIF/WebSocketIFRequestBayTypes.js
/*****************************************************************************!
 * Function : WebSocketIFRequestGetBayTypes
 *****************************************************************************/
function
WebSocketIFRequestGetBayTypes()
{
   WebSocketIFSendSimpleRequest("getbaytypes");
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


// FILE: ./Files/WebSocketIF/WebSocketIFSendLimits.js
/*****************************************************************************!
 * Function : WebSocketIFSendLimits
 *****************************************************************************/
function
WebSocketIFSendLimits
(InType, InValue)
{
  var                                   request;

  request = {};
  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID(); 
  request.time = 0;
  request.type = "setlimits";
  request.body = {};
  request.body.type = InType;
  if ( InValue ) {
    request.body.value = InValue;
  }
  WebSocketIFSendGeneralRequest(request);
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



// FILE: ./Files/WebSocketIF/WebSocketIFSendRemoveArchivedFiles.js
/*****************************************************************************!
 * Function : WebSocketIFSendRemoveArchivedFiles
 *****************************************************************************/
function
WebSocketIFSendRemoveArchivedFiles
()
{
  var									request;

  request = {};
  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID();
  request.time = 0;
  request.type = 'removearchivefiles';
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


// FILE: ./Files/WebSocketIF/WebSocketIFSendTimeStamp.js
/*****************************************************************************!
 * Function : WebSocketIFSendTimeStamp
 *****************************************************************************/
function
WebSocketIFSendTimeStamp
(InDateString)
{
  var                                   request;

  request = {};
  request.packettype = "request";
  request.packetid = WebSocketIFGetNextID(); 
  request.time = 0;
  request.type = "settimestamp";
  request.body = {};
  request.body.datetime = InDateString;
  
  WebSocketIFSendGeneralRequest(request);
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
