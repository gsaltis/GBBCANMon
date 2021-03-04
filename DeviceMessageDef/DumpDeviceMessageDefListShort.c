/*******************************************************************************!
 * Function : DumpDeviceMessageDefListShort
 *******************************************************************************/
void
DumpDeviceMessageDefListShort
(DeviceMessageDefList* InMessageDefs, int InIndent)
{
  DeviceMessageDef*                     messageDef;

  if ( NULL == InMessageDefs ) {
    return;
  }
  for ( messageDef = InMessageDefs->definitions; messageDef; messageDef = messageDef->next ) {
    DumpDeviceMessageDefShort(messageDef, InIndent);
  }
}
