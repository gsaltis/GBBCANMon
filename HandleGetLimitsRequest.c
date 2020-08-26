/*****************************************************************************!
 * Function : HandleGetLimitsRequest
 *****************************************************************************/
void
HandleGetLimitsRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  int                                   packetid;
  string                                returnString;
  char									s[16];

  packetid = JSONIFGetInt(InPacket, "packetid");
  returnString = StringCopy("{\n");
  returnString = StringConcatTo(returnString, "  \"limittype\" : \"");
  returnString = StringConcatTo(returnString, MainLimitType);
  if ( StringEqual(MainLimitType, "none") ) {
    returnString = StringConcatTo(returnString, "\"\n");
  } else {
    returnString = StringConcatTo(returnString, "\",\n");
    if ( StringEqual(MainLimitType, "days") ) {
      returnString = StringConcatTo(returnString, "  \"days\" : ");
      sprintf(s, "%d", MainLimitDays);
      returnString = StringConcatTo(returnString, s);
    } else if ( StringEqual(MainLimitType, "hours") ) {
      returnString = StringConcatTo(returnString, "  \"hours\" : ");
      sprintf(s, "%d", MainLimitHours);
      returnString = StringConcatTo(returnString, s);
    } else if ( StringEqual(MainLimitType, "size") ) {
      returnString = StringConcatTo(returnString, "  \"size\" : ");
      sprintf(s, "%d", MainLimitSize);
      returnString = StringConcatTo(returnString, s);
    } else if ( StringEqual(MainLimitType, "count") ) {
      returnString = StringConcatTo(returnString, "  \"count\" : ");
      sprintf(s, "%d", MainLimitCount);
      returnString = StringConcatTo(returnString, s);
    }
  }
  returnString = StringConcatTo(returnString, "}\n");
  WebSocketFrameResponseSend(InConnection, "resgetlimits", returnString, packetid, 0, "");
  FreeMemory(returnString);
   
}
