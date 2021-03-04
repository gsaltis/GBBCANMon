/*****************************************************************************!
 * Function : CANValueGetFromString
 *****************************************************************************/
string
CANValueGetFromString
(string InValueString, DeviceRegDef* InCanRegDef, ufloatbit32_t InValue)
{
  // Normal floating point
  if ( InCanRegDef->formatType == 0 ) {
    sprintf(InValueString, "%.03f", InValue.fd);

  // Hardware Version
  } else if ( InCanRegDef->formatType == 1 ) {
    sprintf(InValueString, "%c%c%c", InValue.data8[3], InValue.data8[2], InValue.data8[1]);

  // Serial Number
  } else if ( InCanRegDef->formatType == 2 ) {
    sprintf(InValueString, "%u", InValue.data32);      

  // 4 ASCII characters
  } else if ( InCanRegDef->formatType == 3 ) {
    sprintf(InValueString, "%c%c%c%c", InValue.data8[3], InValue.data8[2], InValue.data8[1], InValue.data8[0]);

  // Hex characters
  } else if ( InCanRegDef->formatType == 4 ) {
    sprintf(InValueString, "%08X", InValue.data32);
  }
  return InValueString;
}
