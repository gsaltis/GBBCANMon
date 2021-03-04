/*****************************************************************************!
 * Function : DumpDeviceRegDefList
 *****************************************************************************/
void
DumpDeviceRegDefList
(
 DeviceRegDefList*                      InRegDefs,
 int                                    InIndent
)
{
    DeviceRegDef* regDef;
    if ( NULL == InRegDefs ) {
        return;
    }
    printf_safe("%*s        REGISTER DEFS :\n", InIndent, InIndent > 0 ? " " : "");
    for ( regDef = InRegDefs->definitions; regDef; regDef = regDef->next ) {
        DumpDeviceRegDef(regDef, InIndent+4);
        if ( regDef->next ) {
            printf_safe("\n");
        } 
    }
}
