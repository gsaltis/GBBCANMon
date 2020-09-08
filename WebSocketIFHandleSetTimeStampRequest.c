/*****************************************************************************!
 * Function : WebSocketIFHandleSetTimeStampRequest
 *****************************************************************************/
void
WebSocketIFHandleSetTimeStampRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  int                                   packetid;
  string                                dateString;
  json_value*							body;
  struct tm								times = { 0 };
  time_t								t;
  string								responseString; 	// Free Me
  string								returnMessage;		// Free Me
  string								s;
 
  packetid = JSONIFGetInt(InPacket, "packetid");
  body = JSONIFGetObject(InPacket, "body");

  dateString = JSONIFGetString(body,"datetime");
  strptime(dateString, "%m/%d/%Y %H:%M:%S", &times);

  t = mktime(&times);
  if ( 0 ) {
    s = strerror(errno);
    returnMessage = GetMemory(strlen(s) + 64);
    sprintf(returnMessage, "Failed to set stamp time : %s", s);
  } else {
	returnMessage = StringCopy("Time stamp set");
    MainTimeStampTime = t;
  }

  responseString = StringCopy("{ ");
  responseString = StringConcatTo(responseString, "\"message\" : \"");
  responseString = StringConcatTo(responseString, returnMessage);
  responseString = StringConcatTo(responseString, "\" }");


  WebSocketFrameResponseSend(InConnection, "ressettimestamp", responseString, packetid, 0, "");
  FreeMemory(returnMessage);
  FreeMemory(responseString);
}

