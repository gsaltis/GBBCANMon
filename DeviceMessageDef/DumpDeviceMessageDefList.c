/*******************************************************************************!
 * Function : DumpDeviceMessageDefList
 *******************************************************************************/
void
DumpDeviceMessageDefList
(
 DeviceMessageDefList*                  InMessageDefs,
 int                                    InIndent
)
{
    DeviceMessageDef* messageDef;
    if ( NULL == InMessageDefs ) {
        return;
    }
    printf_safe("%*s         MESSAGE DEFS :\n", InIndent, InIndent > 0 ? " " : "");
    for ( messageDef = InMessageDefs->definitions; messageDef; messageDef = messageDef->next ) {
        DumpDeviceMessageDef(messageDef, InIndent+4);
        if ( messageDef->next ) {
            printf_safe("\n");
        } 
    }
}
