/*****************************************************************************!
 * Function : SetDeviceRegister
 *****************************************************************************/
int
SetDeviceRegister
(CanDevice* InDevice, string InShortName, string InGroup, float InValue)
{ 
  CanReg*                               reg;

  reg = DeviceFindRegister(InDevice, InShortName, InGroup);
  if ( NULL == reg ) {
    return DEVICE_ERROR_REGISTER_NOT_FOUND;
  }
  reg->Value.fd = InValue;
  return DEVICE_ERROR_NONE;
}
