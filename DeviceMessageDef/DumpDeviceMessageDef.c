/*******************************************************************************!
 * Function : DumpDeviceMessageDef
 *******************************************************************************/
void
DumpDeviceMessageDef
(
 DeviceMessageDef*                      InMessageDef,
 int                                    InIndent
)
{
    int i;
    printf_safe("%*s          MESSAGE DEF :\n", InIndent, InIndent > 0 ? " " : "");
    printf_safe("%*s         Message Type : %d\n", InIndent, InIndent > 0 ? " " : "", InMessageDef->msgType);
    printf_safe("%*s       Response Count : %d\n", InIndent, InIndent > 0 ? " " : "", InMessageDef->responsesCount);
    printf_safe("%*s            Responses :\n", InIndent, InIndent > 0 ? " " : "");
    for ( i = 0 ; i < InMessageDef->responsesCount ; i++ ) {
        printf_safe("%*s          Response %2d : %d\n", InIndent, InIndent > 0 ? " " : "", i + 1, InMessageDef->responses[i].responseType);
    }
}
