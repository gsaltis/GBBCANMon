/*******************************************************************************!
 * Function : SetRegisterValueByName
 *******************************************************************************/
int SetRegisterValueByName(char* DeviceName, int Count, char* AbbrevName, char* Group, float NewValue)
{
  CanReg*                       reg;
  CanDevice*                    device = FindDevice(DeviceName, Count);
  if ( device == NULL ) {
    return DEVICE_ERROR_DEVICE_NOT_FOUND;
  }
  reg = DeviceFindRegister(device, AbbrevName, Group);
  if ( NULL == reg ) {
    return DEVICE_ERROR_REGISTER_NOT_FOUND;
  }
  reg->Value.fd = NewValue;
  return DEVICE_ERROR_NONE;
}
