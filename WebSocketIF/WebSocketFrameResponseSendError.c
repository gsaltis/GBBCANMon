/*****************************************************************************!
 * Function : WebSocketFrameResponseSendError
 *****************************************************************************/
void
WebSocketFrameResponseSendError
(struct mg_connection* InConnection, string InResponseType,
 string InBody, int InPacketID, uint32_t InTime,
 string InResponseCode, string InResponseMessage)
{
  string                                responseString;
  char                                  s[16];

  responseString = StringCopy("{\n");

  responseString = StringConcatTo(responseString, "\"type\" : \"");
  responseString = StringConcatTo(responseString, InResponseType);
  responseString = StringConcatTo(responseString, "\",\n");

  responseString = StringConcatTo(responseString, "\"body\" : ");
  responseString = StringConcatTo(responseString, InBody);
  responseString = StringConcatTo(responseString, ",\n");

  responseString = StringConcatTo(responseString, "\"packettype\" : \"response\",\n");

  sprintf(s, "%d", InPacketID);
  responseString = StringConcatTo(responseString, "\"packetid\" : ");
  responseString = StringConcatTo(responseString, s);
  responseString = StringConcatTo(responseString, ",\n");

  sprintf(s, "%d", InTime);
  responseString = StringConcatTo(responseString, "\"time\" : ");
  responseString = StringConcatTo(responseString, s);
  responseString = StringConcatTo(responseString, ",\n");

  responseString = StringConcatTo(responseString, "\"responseid\" : \"");
  responseString = StringConcatTo(responseString, InResponseCode);
  responseString = StringConcatTo(responseString, "\",\n");

  responseString = StringConcatTo(responseString, "\"responsemessage\" : \"");
  responseString = StringConcatTo(responseString, InResponseMessage);
  responseString = StringConcatTo(responseString, "\"\n");

  responseString = StringConcatTo(responseString, "}\n");
  WebSocketFrameSend(InConnection, responseString, strlen(responseString));
  FreeMemory(responseString);
}
