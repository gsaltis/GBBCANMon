/*****************************************************************************!
 * Function : AddCANDevice
 *****************************************************************************/
CanDevice*
AddCANDevice
(string InDeviceDefName, uint16_t InDeviceCANAddress)
{
  CanDevice*                            device;
  DeviceDef*                            deviceDef;

  device = FindCANDeviceByDefNameAddress(InDeviceDefName, InDeviceCANAddress);
  if ( device ) {
    return device;
  }

  deviceDef = FindDeviceDef(mainDeviceDefs, InDeviceDefName);  
  if ( NULL == deviceDef ) {
    return NULL;
  }

  device = CreateDevice(deviceDef, InDeviceCANAddress);

  return device; 
}
