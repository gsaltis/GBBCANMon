/*******************************************************************************!
 * Function : GetDeviceTypeCount
 *******************************************************************************/
int
GetDeviceTypeCount
(
 char*                          InDeviceName
)
{
 
  int                           deviceCount = 0;

  for ( int i = 0 ; i < NumDevices ; i++) {
    if ( strcasecmp(CanDeviceList[i].deviceDefinition->name, InDeviceName) == 0 ) {
      deviceCount++;
    }
  }
  return deviceCount;
}
