/*****************************************************************************!
 * Function : DeviceMessageDefFromJSON
 *****************************************************************************/
DeviceMessageDef*
DeviceMessageDefFromJSON
(json_value* InValue)
{
  int						i;
  DeviceMessageDef*				message;
  json_value*					responseArray;

  if ( NULL == InValue ) {
    return NULL;
  }
  message = (DeviceMessageDef*)GetMemory(sizeof(DeviceMessageDef));
  memset(message, 0x00, sizeof(DeviceMessageDef));

  message->msgType = JSONIFGetInt(InValue, "request");
  message->messageName = JSONIFGetString(InValue, "name");

  responseArray = JSONIFGetArray(InValue, "responses");
  if ( NULL == responseArray ) {
    return message;
  }
  message->responsesCount = responseArray->u.array.length;
  if ( message->responsesCount + 1 >= MAXRESP ) {
    message->responsesCount = MAXRESP;
  }
  for (i = 0; i < message->responsesCount; i++) {
    DeviceMessageResponseSetFromJSON(&(message->responses[i]), responseArray->u.array.values[i]);
  }
  return message;
}
