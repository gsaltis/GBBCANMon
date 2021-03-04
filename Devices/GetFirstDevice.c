/*******************************************************************************!
 * Function : GetFirstDevice
 * Purpose  : Get the first device of a given type
 *******************************************************************************/
CanDevice*
GetFirstDevice
(
 char*                                  InDeviceName
)
{
  if ( InDeviceName == NULL || 0x00 == *InDeviceName ) {
    return NULL;
  }
  for ( int i = 0 ; i < NumDevices ; i++ ) {
    if ( strcasecmp(CanDeviceList[i].deviceDefinition->name, InDeviceName) == 0 ) {
      return &CanDeviceList[i];
    }
  }
  return NULL;
}
