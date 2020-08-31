/*****************************************************************************!
 * Function : HandleSetDateRequest
 *****************************************************************************/
void
HandleSetDateRequest
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
  if ( -1 == stime(&t) ) {
    s = strerror(errno);
    returnMessage = GetMemory(strlen(s) + 64);
    sprintf(returnMessage, "Failed to set time : %s", s);
  } else {
	returnMessage = StringCopy("Time set");
  }

  responseString = StringCopy("{ ");
  responseString = StringConcatTo(responseString, "\"message\" : \"");
  responseString = StringConcatTo(responseString, returnMessage);
  responseString = StringConcatTo(responseString, "\" }");


  WebSocketFrameResponseSend(InConnection, "ressettime", responseString, packetid, 0, "");
  FreeMemory(returnMessage);
  FreeMemory(responseString);
}

