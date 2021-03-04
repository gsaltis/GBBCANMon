/*****************************************************************************!
 * Function : GetDeviceList
 * Purpose  : Return a list of comma separated device names
 *****************************************************************************/
string
GetDeviceList()
{
  string                                deviceList;
  DeviceDef*                            deviceDef;
    
  for ( deviceDef = mainDeviceDefs->defs; deviceDef;  deviceDef = deviceDef->next ) {
    if ( deviceList == NULL ) {
      deviceList = StringCopy(deviceDef->name);
    } else {
      deviceList = StringConcatTo(deviceList, ", ");
      deviceList = StringConcatTo(deviceList, deviceDef->name); 
    }
  }
  return deviceList;
}
