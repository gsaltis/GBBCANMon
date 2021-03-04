/*******************************************************************************!
 * Function : DestroyDeviceRegList
 *******************************************************************************/
void
DestroyDeviceRegList
(
 DeviceRegDefList*                      InRegDefs
)
{
    DeviceRegDef*                       regDef;
    if ( NULL == InRegDefs ) {
        return;
    }
    for (regDef = InRegDefs->definitions; regDef; regDef = regDef->next) {
        DestroyDeviceRegDef(regDef);
    }      
    FreeMemory(InRegDefs);
}
