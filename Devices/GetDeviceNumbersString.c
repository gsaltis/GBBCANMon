/*****************************************************************************!
 * Function : GetDeviceNumbersString
 *****************************************************************************/
string
GetDeviceNumbersString
(string InDeviceName)
{
  CanDevice*                            device;
  int                                   i;
  string                                returnString;

  returnString = NULL;
  if ( InDeviceName == NULL ) {
    return NULL;
  }
  
  for ( i = 0; i < NumDevices; i++ ) {
    device = &CanDeviceList[i];
    if ( StringEqual(device->deviceDefinition->name, InDeviceName) ) {
      if ( returnString == NULL ) {
      }
    }
  }
  return returnString;
}
