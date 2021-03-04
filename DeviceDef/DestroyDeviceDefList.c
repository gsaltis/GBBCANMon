/*******************************************************************************!
 * Function : DestroyDeviceDefList
 *******************************************************************************/
void
DestroyDeviceDefList
(
 DeviceDefList*                         InDeviceDefs
)
{
    DeviceDef*                          deviceDef;
    if ( InDeviceDefs == NULL ) {
        return;
    }

    for (deviceDef = InDeviceDefs->defs;  deviceDef; deviceDef = deviceDef->next ) {
        DestroyDeviceDef(deviceDef);
    }    
    FreeMemory(InDeviceDefs);
}
