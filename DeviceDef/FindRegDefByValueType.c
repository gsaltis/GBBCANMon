/*****************************************************************************!
 * Function : FindRegDefByValueType
 *****************************************************************************/
DeviceRegDef*
FindRegDefByValueType
(DeviceDefList* InDeviceDefs, int InValueType)
{
  DeviceDef*                            def;
  DeviceRegDef*				deviceRegDef;

  for ( def = InDeviceDefs->defs ; def ; def = def->next ) {
    for ( deviceRegDef = def->regDefs->definitions; deviceRegDef; deviceRegDef = deviceRegDef->next ) {
      if ( deviceRegDef->valueType == InValueType ) {
        return deviceRegDef;
      }
    }
  }
  return NULL;
}
