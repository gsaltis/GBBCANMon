/*****************************************************************************!
 * Function : CanRegSetFromString
 *****************************************************************************/
void
CanRegSetFromString
(CanReg* InCanReg, string InValueString)
{
  bool                                  b;

  if ( InCanReg->registerDef->formatType == 0 ) {
    InCanReg->Value.fd = GetFloatValueFromString(&b, InValueString);
  } else if ( InCanReg->registerDef->formatType == 1 ) {
    memcpy(&(InCanReg->Value.data32), InValueString, 3);
  } else if ( InCanReg->registerDef->formatType == 2 ) {
    InCanReg->Value.data32 = GetIntValueFromString(&b, InValueString);
  } else if ( InCanReg->registerDef->formatType == 3 ) {
    memcpy(&(InCanReg->Value.data32), InValueString, 4);
  } else if ( InCanReg->registerDef->formatType == 4 ) {
    InCanReg->Value.data32 = GetHex32ValueFromString(NULL, InValueString);
  }
}
