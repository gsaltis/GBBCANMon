/*******************************************************************************!
 * Function : CreateDeviceDef
 *******************************************************************************/
DeviceDef*
CreateDeviceDef
()
{
  DeviceDef*                          deviceDef;
  deviceDef = (DeviceDef*)GetMemory(sizeof(DeviceDef));
  memset(deviceDef, 0x00, sizeof(DeviceDef));
  return deviceDef;
}
