/*******************************************************************************!
 * Function : DumpDeviceDefList
 *******************************************************************************/
void
DumpDeviceDefList
(
 DeviceDefList*                         InDeviceDefList,
 int                                    InIndent
)
{
    DeviceDef*                          deviceDef;
    
    if ( NULL == InDeviceDefList ) {
        return;
    }
    printf_safe("%*s      Device Def List :\n", InIndent, InIndent > 0 ? " " : "");
    for ( deviceDef = InDeviceDefList->defs; deviceDef; deviceDef = deviceDef->next ) {
        DumpDeviceDef(deviceDef, InIndent+4);
        printf_safe("\n");
    }
}
