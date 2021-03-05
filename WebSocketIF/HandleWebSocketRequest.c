/*****************************************************************************!
 * Function : HandleWebSocketRequest
 *****************************************************************************/
void
HandleWebSocketRequest
(struct mg_connection* nc, struct mg_str InMessage)
{
  string                                packettype;
  json_value*                           jsonDoc;

  jsonDoc = json_parse((const json_char*)InMessage.p, (size_t)InMessage.len);

  packettype = JSONIFGetString(jsonDoc, "packettype");

  if ( NULL == packettype ) {
    json_value_free(jsonDoc);
    return;
  }

  if ( StringEqual("request", packettype) ) {
    WebSocketIFHandlePacketRequest(nc, jsonDoc);
  } else if ( StringEqual("response", packettype) ) {
 
  } else if ( StringEqual("push", packettype) ) {
 
  }
  FreeMemory(packettype);
  json_value_free(jsonDoc);
}
