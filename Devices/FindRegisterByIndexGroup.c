/*****************************************************************************!
 * Function : FindRegisterByIndexGroup
 *****************************************************************************/
CanReg*
FindRegisterByIndexGroup
(CanDevice* InDevice, int InIndex, string InGroup)
{
  CanReg*                               reg;
  char                                  s[17];
  if ( InDevice == NULL || InGroup == NULL ) {
    return NULL;
  }
  
  snprintf(s, sizeof(s) - 1, "%d", InIndex);
  reg = DeviceFindRegister(InDevice, s, InGroup);
  return reg;
}
