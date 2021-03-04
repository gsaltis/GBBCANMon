/*****************************************************************************!
 * Function : GetDeviceRegisterFloat
 *****************************************************************************/
float
GetDeviceRegisterFloat
(CanDevice* InDevice, int InIndex, string InGroup)
{
  CanReg*                               reg;
  char                                  s[17];
  
  snprintf(s, sizeof(s) - 1, "%d", InIndex);
  reg = DeviceFindRegister(InDevice, s, InGroup);
  if ( reg == NULL ) {
    return 0.0;
  }
  return reg->Value.fd;
}
