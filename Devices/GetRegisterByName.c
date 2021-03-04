/*****************************************************************************!
 * Function : GetRegisterByName
 *****************************************************************************/
CanReg*
GetRegisterByName
(CanDevice* InDevice, char* InName)
{
  int                                   n, i;

  n = GetDeviceRegCount(InDevice->deviceDefinition->regDefs);
  for (i = 0; i < n; i++) {
    if ( StringEqual(InDevice->Registers[i].registerDef->name, InName) ) {
      return &(InDevice->Registers[i]);
    }
  }
  return NULL;
}
