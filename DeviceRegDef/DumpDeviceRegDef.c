/*******************************************************************************!
 * Function : DumpDeviceRegDef
 *******************************************************************************/
void
DumpDeviceRegDef
(
 DeviceRegDef*                          InRegDef,
 int                                    InIndent
)
{
    if ( NULL == InRegDef ) {
        return;
    }
    printf_safe("%*s         REGISTER DEF :\n", InIndent, InIndent > 0 ? " " : "");
    printf_safe("%*s                 Name : %s\n", InIndent, InIndent > 0 ? " " : "", InRegDef->name);
    printf_safe("%*s           Short Name : %s\n", InIndent, InIndent > 0 ? " " : "", InRegDef->shortName);
    printf_safe("%*s        Display Label : %s\n", InIndent, InIndent > 0 ? " " : "", InRegDef->displayLabel);
    printf_safe("%*s                Group : %s\n", InIndent, InIndent > 0 ? " " : "", InRegDef->group);
    printf_safe("%*s           Value Type : %04x\n", InIndent, InIndent > 0 ? " " : "", InRegDef->valueType);
    printf_safe("%*s         Message Type : %04x\n", InIndent, InIndent > 0 ? " " : "", InRegDef->messageType);
    printf_safe("%*s        Initial Value : %0.04f\n", InIndent, InIndent > 0 ? " " : "", InRegDef->initialValue.fd);
}
