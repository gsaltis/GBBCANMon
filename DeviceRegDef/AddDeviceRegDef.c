/*******************************************************************************!
 * Function : AddDeviceRegDef
 *******************************************************************************/
void
AddDeviceRegDef
(
 DeviceRegDefList*                      InDeviceRegDefs,
 DeviceRegDef*                          InDeviceRegDef
)
{
    if ( NULL == InDeviceRegDefs || NULL == InDeviceRegDef ) {
        return;
    }
    if ( InDeviceRegDefs->definitions ) {
        InDeviceRegDefs->lastDefinition->next = InDeviceRegDef;
        InDeviceRegDefs->lastDefinition = InDeviceRegDef;
    } else {
        InDeviceRegDefs->definitions = InDeviceRegDef;
        InDeviceRegDefs->lastDefinition = InDeviceRegDef;
    }
}
