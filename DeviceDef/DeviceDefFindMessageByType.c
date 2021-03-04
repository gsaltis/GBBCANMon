/*****************************************************************************!
 * Function : DeviceDefFindMessageByType
 *****************************************************************************/
DeviceMessageDef*
DeviceDefFindMessageByType
(DeviceDef* InDeviceDef, int InMessageType)
{
  return FindMessageDefByMessageType(InDeviceDef->messageDefs, InMessageType); 
}
