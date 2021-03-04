/*****************************************************************************!
 * Function : DeviceDefFindRegByValueType
 *****************************************************************************/
DeviceRegDef*
DeviceDefFindRegByValueType
(DeviceDef* InDeviceDef, int InValueType)
{
  return FindRegDefByValue(InDeviceDef->regDefs, InValueType);
}
