/*****************************************************************************!
 * Function : FindDeviceDefByProtocol
 *****************************************************************************/
DeviceDef*
FindDeviceDefByProtocol
(DeviceDefList* InDeviceDefs, int InProtocol)
{
  for ( DeviceDef* def = InDeviceDefs->defs; def; def = def->next ) {
    if ( def->protocolNumber == InProtocol ) {
      return def;
    }
  }
  return NULL;
}
