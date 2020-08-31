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
