/*****************************************************************************!
 * Function : WebSocketIFHandleGetMonitorInfoRequest
 *****************************************************************************/
void
WebSocketIFHandleGetMonitorInfoRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  string								s;
  int									packetid;
  char									s2[228];
  char                  				s3[32];
  char				 					s4[64];
  char									s5[64];
  char			 						MessageCountString[32];
  struct tm*							t;
  bool                                  b;
  time_t							 	days, minutes, hours, seconds; 
  time_t                                t1 = time(NULL);
  time_t								t2;

  packetid = JSONIFGetInt(InPacket, "packetid");
  s = StringCopy("{  \"monitorinfo\" :  { \n");
  s = StringConcatTo(s, "    \"version\" : \"");
  s = StringConcatTo(s, MainVersionNumber);
  s = StringConcatTo(s, "\",\n");

  s = StringConcatTo(s, "    \"messagelimitvalue\" : ");

  if ( StringEqual(MainLimitType, "none") ) {
    ConvertIntToCommaString(CANInterfaceMessagesCount, MessageCountString);
    ConvertIntToCommaString(MainLimitCount, s5);
	sprintf(s2, "\"%s of %s messages\",\n", MessageCountString, s5);
  } else if ( StringEqual(MainLimitType, "count") ) {
	ConvertIntToCommaString(CANInterfaceMessagesCount, MessageCountString);
    ConvertIntToCommaString(MainLimitCount, s5);
	sprintf(s2, "\"%s of %s messages\",\n", MessageCountString, s5);
  } else if ( StringEqual(MainLimitType, "days") ) {
    time_t t2 = t1- MainStartTime;
    days = t2 / (3600 * 24);
	hours = t2 % (3600 * 24);
    minutes = hours % 3600;
    minutes /= 60;
    hours /= 3600;
    ConvertIntToCommaString(CANInterfaceMessagesCount, MessageCountString);
    if ( days == 0 ) {
	  if ( hours == 0 ) {
		if ( minutes == 0 ) {
		  sprintf(s2, "\"0 minutes 0 hours 0 days of %d day%s : (%s Messages)\",\n", MainLimitDays, MainLimitDays > 1 ? "s" : "", MessageCountString);
 	    } else { 
		  sprintf(s2, "\"%d minute%s 0 hours 0 days of %d day%s : (%s Messages)\",\n", (int)minutes, minutes > 1 ? "s" : "", MainLimitDays, MainLimitDays > 1 ? "s" : "", MessageCountString);
		}
      } else {
		if ( minutes == 0 ) {
          sprintf(s2, "\"0 minutes %d hour%s of %d day%s : (%s Messages)\",\n", (int)hours, hours > 1 ? "s" : "", MainLimitDays, MainLimitDays > 1 ? "s" : "", MessageCountString);
		} else {
          sprintf(s2, "\"%d minute%s %d hour%s of %d day%s : (%s Messages)\",\n", (int)minutes, minutes > 1 ? "s" : "", (int)hours, hours > 1 ? "s" : "", MainLimitDays, MainLimitDays > 1 ? "s" : "", MessageCountString);
        }
	  }
    } else {
	  if ( hours == 0 ) {
		if ( minutes == 0 ) {
	 	  sprintf(s2, "\"%d day%s of %d day%s : (%s Messages)\",\n", (int)days, days > 1 ? "s" : "", MainLimitDays, MainLimitDays > 1 ? "s" : "", MessageCountString);
	    } else {
	 	  sprintf(s2, "\"%d minute%s %d day%s of %d day%s : (%s Messages)\",\n", (int)minutes, minutes > 1 ? "s" : "", (int)days, days > 1 ? "s" : "", MainLimitDays, MainLimitDays > 1 ? "s" : "", MessageCountString);
		}
      } else {
		if ( minutes == 0 ) {
          sprintf(s2, "\"%d hour%s %d day%s of %d day%s : (%s Messages)\",\n", (int)hours, hours > 1 ? "s" : "", (int)days, days > 1 ? "s" : "", MainLimitDays, MainLimitDays > 1 ? "s" : "", MessageCountString);
	    } else {
          sprintf(s2, "\"%d minute%s %d hour%s %d day%s of %d day%s : (%s Messages)\",\n", (int)minutes, minutes > 1 ? "s" : "", (int)hours, hours > 1 ? "s" : "", (int)days, days > 1 ? "s" : "", MainLimitDays, MainLimitDays > 1 ? "s" : "", MessageCountString);
        }
	  }
    }
  } else if ( StringEqual(MainLimitType, "hours") ) {
    t2 = t1 - MainStartTime;
    hours = t2 / 3600;
    minutes = t2 % 3600;
    minutes /= 60;
    ConvertIntToCommaString(CANInterfaceMessagesCount, MessageCountString);
    if ( hours == 0 ) {
	  if ( minutes == 0 ) {
		sprintf(s2, "\"0 minutes 0 hours of %d hour%s : (%s Message)\",\n", MainLimitHours, MainLimitHours > 1 ? "s" : "", MessageCountString);
      } else {
        sprintf(s2, "\"%d minute%s of %d hour%s : (%s Messages)\",\n", (int)minutes, minutes > 1 ? "s" : "", MainLimitHours, MainLimitHours > 1 ? "s" : "", MessageCountString);
      }
    } else {
	  if ( minutes == 0 ) {
		sprintf(s2, "\"%d hour%s of %d hour%s : (%s Messages)\",\n", (int)hours, hours > 1 ? "s" : "", MainLimitHours, MainLimitHours > 1 ? "s" : "", MessageCountString);
      } else {
        sprintf(s2, "\"%d minute%s %d hour%s of %d hour%s : (%s Messages)\",\n", (int)minutes, minutes > 1 ? "s" : "", (int)hours, hours > 1 ? "s" : "", MainLimitHours, MainLimitHours > 1 ? "s" : "", MessageCountString);
      }
    } 

  } else if ( StringEqual(MainLimitType, "size") ) {
    ConvertIntToCommaString(MainLimitSizeRuntime, s3);
	ConvertIntToCommaString(MainLimitSize * 1000000, s4);
    ConvertIntToCommaString(CANInterfaceMessagesCount, MessageCountString);
    sprintf(s2, "\"%s of %s bytes : (%s Messages)\",\n", s3, s4, MessageCountString);
  }

  s = StringConcatTo(s, s2);

  s = StringConcatTo(s, "    \"messagelimitlabel\" : ");

  if ( StringEqual(MainLimitType, "none") ) {
    s = StringConcatTo(s, "\"Message Count :\",\n");
  } else if ( StringEqual(MainLimitType, "count") ) {
    s = StringConcatTo(s, "\"Message Count :\",\n");
  } else if ( StringEqual(MainLimitType, "days") ) {
    s = StringConcatTo(s, "\"Days of Data :\",\n");
  } else if ( StringEqual(MainLimitType, "hours") ) {
    s = StringConcatTo(s, "\"Hours of Data :\",\n");
  } else if ( StringEqual(MainLimitType, "size" ) ) {
    s = StringConcatTo(s, "\"File Size :\",\n");
  }
 
  s = StringConcatTo(s, "    \"monitorstatus\" : ");
  sprintf(s2, "%s,\n", CANInterfaceMonitor ? "true" : "false");
  s = StringConcatTo(s, s2);

  s = StringConcatTo(s, "    \"monitorstarttime\" : \"");
  t = localtime(&MainTimeStampTime);
  t2 = (int)t1 - MainStartTime;
  minutes = t2 / 60;
  seconds = t2 % 60;
  hours   = minutes / 60;
  minutes = minutes % 60;

  if ( hours == 0 ) {
    sprintf(s5, " -- %02d.%02d Elapsed\",\n", (int)minutes, (int)seconds);
  } else {
    sprintf(s5, " -- %d:%02d.%02d Elapsed\",\n", (int)hours, (int)minutes, (int)seconds);
  } 
  sprintf(s4, "%02d/%02d/%04d %02d:%02d:%02d", t->tm_mon + 1, t->tm_mday, t->tm_year + 1900, t->tm_hour, t->tm_min, t->tm_sec);
  s = StringConcatTo(s, s4);
  s = StringConcatTo(s, s5);

  b = CANInterfaceThreadThrottleFile();
  s = StringConcatTo(s, "    \"limitstatus\" : \"");
  if ( b ) {
    s = StringConcatTo(s, "AT\",\n");
  } else {
    s = StringConcatTo(s, "OK\",\n");
  }
  s = StringConcatTo(s, "    \"monitorfilename\" : \"");
  s = StringConcatTo(s, CANInterfaceOutputFilename);
  s = StringConcatTo(s, "\"\n");
 
  s = StringConcatTo(s, "  }\n");
  s = StringConcatTo(s, "}\n");

  WebSocketFrameResponseSend(InConnection, "resmonitorinfo", s, packetid, 0, "");
  FreeMemory(s);
}
