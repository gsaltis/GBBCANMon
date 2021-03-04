/*******************************************************************************!
 * Function : RemoveDeviceDefByName
 *******************************************************************************/
void
RemoveDeviceDefByName
(
 DeviceDefList*                         InDeviceDefs,
 char*                                  InName
)
{
    DeviceDef*                          deviceDef;
    DeviceDef*                          previousDef;
    
    if ( InDeviceDefs == NULL || InName == NULL ) {
        return;
    }
    previousDef = NULL;
    for (deviceDef = InDeviceDefs->defs;  deviceDef; deviceDef = deviceDef->next ) {
        if ( !strcmp(deviceDef->name, InName) ) {
            break;
        }
        previousDef = deviceDef;
    }
    if ( deviceDef == NULL ) {
        return;
    }
    if ( deviceDef == InDeviceDefs->defs ) {
        if ( InDeviceDefs->lastDef == deviceDef ) {
            InDeviceDefs->defs = NULL;
            InDeviceDefs->lastDef = NULL;
        } else {
            InDeviceDefs->defs = deviceDef->next;
        }
    } else {
        previousDef->next = deviceDef->next;
        if ( InDeviceDefs->lastDef == deviceDef ) {
            InDeviceDefs->lastDef = previousDef;
        }
    }
    DestroyDeviceDef(deviceDef);
}
