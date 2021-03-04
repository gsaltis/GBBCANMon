/*****************************************************************************!
 * Function : DumpDeviceDefShort
 *****************************************************************************/
void
DumpDeviceDefShort
(DeviceDef* InDeviceDef, int InIndent, int InNameIndent, int InDescIndent,
 bool InDumpRegs, bool InDumpMessages, int InRegSortOrder)
{
  printf_safe("%*s%*s   %*s      %4d     (%03d)%2x       %4d\n",
              InIndent, InIndent > 0 ? " " : "",
              InNameIndent, InDeviceDef->name,
              InDescIndent, InDeviceDef->desc,
              InDeviceDef->canAddressStart,
              InDeviceDef->protocolNumber,
              InDeviceDef->protocolNumber,
              InDeviceDef->displayColumns);
  if ( InDumpRegs ) {
    DumpDeviceRegDefListShort(InDeviceDef->regDefs, InIndent + 4, InRegSortOrder);
  }
  if ( InDumpMessages ) {
    DumpDeviceMessageDefListShort(InDeviceDef->messageDefs, InIndent);
  }
}
