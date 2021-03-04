/*****************************************************************************!
 * Function : DeviceMessageResponseSetFromJSON
 *****************************************************************************/
void
DeviceMessageResponseSetFromJSON
(DeviceMessageResponse* InResponse, json_value* InValue)
{
  bool					b;
  if ( InResponse == NULL ) {
    return;
  }
  InResponse->responseType = GetIntValueFromString(&b, InValue->u.string.ptr);
}
