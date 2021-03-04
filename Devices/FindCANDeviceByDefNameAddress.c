/*****************************************************************************!
 * Function : FindCANDeviceByDefNameAddress
 *****************************************************************************/
CanDevice*
FindCANDeviceByDefNameAddress
(string InDeviceDefName, uint16_t InDeviceCANAddress)
{
  int                                   i;
  CanDevice*                            device;

  for ( i = 0 ; i < NumDevices ; i++ ) {
    device = &CanDeviceList[i];
    if ( StringEqual(device->deviceDefinition->name, InDeviceDefName) ) {
      if ( device->CanAddress == InDeviceCANAddress ) {
        return device;
      } 
    }
  }
  return NULL;
}
