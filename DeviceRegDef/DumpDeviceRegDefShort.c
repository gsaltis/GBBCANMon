/*****************************************************************************!
 * Function : DumpDeviceRegDefShort
 *****************************************************************************/
void
DumpDeviceRegDefShort
(DeviceRegDef* InRegDef, int InIndent, int InNameIndent, int InShortNameIndent, 
 int InGroupIndent, int InDisplayLabelIndent)
{
  string                                indentString;

  if ( InIndent > 0 )  {
    indentString = StringFill(' ', InIndent);
  } else {
    indentString = (string)GetMemory(1);
    *indentString = 0x00;
  }
  printf("%s%*s  %*s  %*s  %*s  %04d  %04x  %9.04f\n",
         indentString,
         InNameIndent,
         InRegDef->name,

         InShortNameIndent,
         InRegDef->shortName,

         InDisplayLabelIndent,
         InRegDef->displayLabel,

         InGroupIndent,
         InRegDef->group,

         InRegDef->valueType,
         InRegDef->messageType,
         InRegDef->initialValue.fd);
  FreeMemory(indentString);
}
