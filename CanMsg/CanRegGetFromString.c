/*****************************************************************************!
 * Function : CanRegGetFromString
 *****************************************************************************/
string
CanRegGetFromString
(string InValueString, CanReg* InCanReg)
{
  return CANValueGetFromString(InValueString, InCanReg->registerDef, InCanReg->Value);
}
