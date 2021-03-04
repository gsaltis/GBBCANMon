/*******************************************************************************!
 * Function : DestroyDeviceDef
 *******************************************************************************/
void
DestroyDeviceDef
(
 DeviceDef*                             InDeviceDef
)
{
  if ( InDeviceDef == NULL ) {
    return;
  }
  if ( InDeviceDef->regDefs ) {
    DestroyDeviceRegList(InDeviceDef->regDefs);
  }
    
  if ( InDeviceDef->messageDefs ) {
    DestroyDeviceMessageDefList(InDeviceDef->messageDefs);
  }
  FreeMemory(InDeviceDef->name);
  FreeMemory(InDeviceDef->desc);
  FreeMemory(InDeviceDef);
}
