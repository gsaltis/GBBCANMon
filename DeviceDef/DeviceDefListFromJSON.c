/*****************************************************************************!
 * Function : DeviceDefListFromJSON
 *****************************************************************************/
DeviceDefList*
DeviceDefListFromJSON
(json_value* InJSON)
{
  DeviceDefList*	                deviceDefList;
  int                                   i;
  json_value*				value;
  DeviceDef*				deviceDef;

  if ( InJSON == NULL ) {
    return NULL;
  }

  if ( InJSON->type != json_array ) {
    return NULL;
  }

  deviceDefList = CreateDeviceDefList();
  for ( i = 0 ; i < InJSON->u.array.length; i++ ) {
    value = InJSON->u.array.values[i];
    deviceDef = DeviceDefFromJSON(value);
    if ( deviceDef ) {
      AddDeviceDef(deviceDefList, deviceDef);
    }
  }

  return deviceDefList;
}
