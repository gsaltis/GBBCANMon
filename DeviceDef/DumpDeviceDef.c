/*******************************************************************************!
 * Function : DumpDeviceDef
 *******************************************************************************/
void
DumpDeviceDef
(
 DeviceDef*                             InDeviceDef,
 int                                    InIndent
)
{
    if ( NULL == InDeviceDef ) {
        return;
    }
    printf_safe("%*s           DEVICE DEF :\n", InIndent, InIndent > 0 ? " " : "");
    printf_safe("%*s                 Name : %s\n", InIndent, InIndent > 0 ? " " : "", InDeviceDef->name);
    printf_safe("%*s                 Desc : %s\n", InIndent, InIndent > 0 ? " " : "", InDeviceDef->desc);
    printf_safe("%*s    CAN Address Start : %d\n", InIndent, InIndent > 0 ? " " : "", InDeviceDef->canAddressStart);
    printf_safe("%*s      Protocol Number : %d\n", InIndent, InIndent > 0 ? " " : "", InDeviceDef->protocolNumber);
    printf_safe("%*s      Display Columns : %d\n", InIndent, InIndent > 0 ? " " : "", InDeviceDef->displayColumns);
    DumpDeviceRegDefList(InDeviceDef->regDefs, InIndent + 4);
    DumpDeviceMessageDefList(InDeviceDef->messageDefs, InIndent + 4);
}
