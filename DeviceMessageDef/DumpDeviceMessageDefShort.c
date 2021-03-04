/*******************************************************************************!
 * Function : DumpDeviceMessageDefShort
 *******************************************************************************/
void
DumpDeviceMessageDefShort
(DeviceMessageDef* InMessageDef, int InIndent)
{
  int                                   i;
  if ( InIndent > 0 ) {
    printf_safe("%*s", InIndent, " ");
  }    
  printf_safe("%4d  %2d [", InMessageDef->msgType, InMessageDef->responsesCount);
  for ( i = 0 ; i < InMessageDef->responsesCount ; i++ ) {
    printf_safe("%4d", InMessageDef->responses[i].responseType);
    if ( i + 1 != InMessageDef->responsesCount ) {
      printf_safe(" ");
    }
  }
  printf_safe("]\n");
}
