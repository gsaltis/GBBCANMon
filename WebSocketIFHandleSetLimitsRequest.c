/*****************************************************************************!
 * Function : WebSocketIFHandleSetLimitsRequest
 *****************************************************************************/
void
WebSocketIFHandleSetLimitsRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  int                                   packetid;
  string                                typeString, valueString;
  string								responseString; 	// Free Me
  string								returnMessage;		// Free Me
  json_value*							body;
  int                                   value;
  bool									b;

  packetid = JSONIFGetInt(InPacket, "packetid");
  body = JSONIFGetObject(InPacket, "body");

  typeString = JSONIFGetString(body, "type");
  valueString = JSONIFGetString(body, "value");

  if ( StringEqual(typeString, "none" ) ) {
    b = MainLimitSet(typeString, 0);
	returnMessage = MessageSetLimitsResponse(b, typeString, 0);
  } else {
    value = GetIntValueFromString(&b, valueString);
    if ( !b ) {
	  returnMessage = StringMultiConcat(valueString, " is not a valid number", NULL);
    } else {
	  b = MainLimitSet(typeString, value);
	  returnMessage = MessageSetLimitsResponse(b, typeString, value);
    }
  }
  responseString = StringCopy("{ ");
  responseString = StringConcatTo(responseString, "\"message\" : \"");
  responseString = StringConcatTo(responseString, returnMessage);
  responseString = StringConcatTo(responseString, "\" }");

  WebSocketFrameResponseSend(InConnection, "ressetlimits", responseString, packetid, 0, "");
  FreeMemory(returnMessage);
  FreeMemory(responseString);
}
