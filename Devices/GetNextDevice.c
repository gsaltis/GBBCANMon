/*******************************************************************************!
 * Function : GetNextDevice
 * Purpose  : Get the device of the same type following a given device
 *******************************************************************************/
CanDevice*
GetNextDevice
(
 CanDevice*                             InCurrentDevice
)
{
  int                                   i;

  if ( NULL == InCurrentDevice ) {
    return NULL;
  }

  // Find the location of the current device
  for ( i = 0 ; i < NumDevices; i++ ) {
    if ( &CanDeviceList[i] == InCurrentDevice ) {
      break;
    }
  }

  // We should not have exhausted the list but in case we do
  if ( i >= NumDevices ) {
    return NULL;
  }

  // Starting at the next location find the device with the same device type
  for ( i++ ; i < NumDevices; i++ ) {
    if ( strcasecmp(CanDeviceList[i].deviceDefinition->name, InCurrentDevice->deviceDefinition->name) == 0 ) {
      // We found is so return it
      return &(CanDeviceList[i]);
    }
  }
  // InCurrentDevice was the last one, so return NULL;
  return NULL;
}
