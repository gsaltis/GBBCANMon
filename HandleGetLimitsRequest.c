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
  returnString = StringConcatTo(returnString, "\",\n");

  returnString = StringConcatTo(returnString, "  \"days\" : ");
  sprintf(s, "%d,", MainLimitDays);
  returnString = StringConcatTo(returnString, s);

  returnString = StringConcatTo(returnString, "  \"hours\" : ");
  sprintf(s, "%d,", MainLimitHours);
  returnString = StringConcatTo(returnString, s);

  returnString = StringConcatTo(returnString, "  \"size\" : ");
  sprintf(s, "%d,", MainLimitSize);
  returnString = StringConcatTo(returnString, s);

  returnString = StringConcatTo(returnString, "  \"count\" : ");
  sprintf(s, "%d", MainLimitCount);
  returnString = StringConcatTo(returnString, s);
  
  returnString = StringConcatTo(returnString, "}\n");
  WebSocketFrameResponseSend(InConnection, "resgetlimits", returnString, packetid, 0, "");
  FreeMemory(returnString);
   
}
