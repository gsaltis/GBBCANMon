/*******************************************************************************!
 * Function : FindDeviceDef 
 *******************************************************************************/
DeviceDef*
FindDeviceDef
(
 DeviceDefList*                         InDeviceDefs,
 char*                                  InName
)
{
    DeviceDef*                          deviceDef;
    if ( InDeviceDefs == NULL || InName == NULL) {
        return NULL;
    }
    for (deviceDef = InDeviceDefs->defs;  deviceDef; deviceDef = deviceDef->next ) {
        if ( !strcmp(deviceDef->name, InName) ) {
            return deviceDef;            
        }
    }
    return NULL;
}
