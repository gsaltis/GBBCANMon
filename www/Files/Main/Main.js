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
