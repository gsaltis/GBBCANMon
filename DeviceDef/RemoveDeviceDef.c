/*******************************************************************************!
 * Function : RemoveDeviceDef
 *******************************************************************************/
void
RemoveDeviceDef
(
 DeviceDefList*                         InDeviceDefs,
 DeviceDef*                             InDeviceDef
)
{
    DeviceDef*                          deviceDef;
    if ( InDeviceDefs == NULL || InDeviceDef == NULL ) {
        return;
    }
    for (deviceDef = InDeviceDefs->defs;  deviceDef; deviceDef = deviceDef->next ) {
        if ( !strcmp(deviceDef->name, InDeviceDef->name) ) {
            RemoveDeviceDefByName(InDeviceDefs, InDeviceDef->name);
        }
    }    
}
