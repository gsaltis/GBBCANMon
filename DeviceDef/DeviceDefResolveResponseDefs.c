/*****************************************************************************!
 * Function : DeviceDefResolveResponseDefs
 *****************************************************************************/
void
DeviceDefResolveResponseDefs
(DeviceDef* InDeviceDef)
{
  DeviceMessageDef*			message;
  DeviceMessageResponse*		response;
  int					i;

  for ( message = InDeviceDef->messageDefs->definitions; message; message = message->next) {
    for ( i = 0; i < message->responsesCount; i++ ) {
      response = &message->responses[i];
      response->responseDef = FindRegDefByValue(InDeviceDef->regDefs, response->responseType); 
    }
  }
}
