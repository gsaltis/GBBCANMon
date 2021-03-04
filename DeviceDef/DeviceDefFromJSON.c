/*****************************************************************************!
 * Function : DeviceDefFromJSON
 *****************************************************************************/
DeviceDef*
DeviceDefFromJSON
(json_value* InJSON)
{
  DeviceDef*				deviceDef;
  json_value*				regs_array;
  json_value*				msgs_array;
  json_value*				value;
  int					i;
  DeviceRegDef*				reg;
  DeviceMessageDef*			msg;

  if ( NULL == InJSON ) {
    return NULL;
  }

  deviceDef = (DeviceDef*)GetMemory(sizeof(DeviceDef));
  memset(deviceDef, 0x00, sizeof(DeviceDef));

  deviceDef->canAddressStart = JSONIFGetInt(InJSON, "startingcanaddress");
  deviceDef->protocolNumber = JSONIFGetInt(InJSON, "protocol");

  deviceDef->name = JSONIFGetString(InJSON, "name");
  deviceDef->desc = JSONIFGetString(InJSON, "description");
  
  deviceDef->regDefs = CreateDeviceRegDefList();
  deviceDef->messageDefs = CreateDeviceMessageDefList();

  regs_array = JSONIFGetArray(InJSON, "regs");
  if ( regs_array ) {
    for ( i = 0; i < regs_array->u.array.length; i++ ) {
      value = regs_array->u.array.values[i];
      reg = DeviceRegDefFromJSON(value);
      AddDeviceRegDef(deviceDef->regDefs, reg);
    } 
  }

  msgs_array = JSONIFGetArray(InJSON, "messages");
  if ( msgs_array ) {
    for (i = 0; i < msgs_array->u.array.length; i++) {
      value = msgs_array->u.array.values[i];
      msg = DeviceMessageDefFromJSON(value);
      AddDeviceMessageDef(deviceDef->messageDefs, msg);
      msg->deviceDefParent = deviceDef;
    }
  }
  DeviceDefResolveResponseDefs(deviceDef);
  return deviceDef;
}
