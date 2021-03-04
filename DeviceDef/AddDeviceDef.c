/*******************************************************************************!
 * Function : AddDeviceDef
 *******************************************************************************/
void
AddDeviceDef
(
 DeviceDefList*                         InDeviceDefs,
 DeviceDef*                             InDeviceDef
)
{
    if ( InDeviceDefs == NULL || InDeviceDef == NULL ) {
        return;
    }
    if (InDeviceDefs->defs == NULL) {
        InDeviceDefs->defs = InDeviceDef;
        InDeviceDefs->lastDef = InDeviceDef;
    } else {
        InDeviceDefs->lastDef->next = InDeviceDef;
        InDeviceDefs->lastDef = InDeviceDef;
    }
}
