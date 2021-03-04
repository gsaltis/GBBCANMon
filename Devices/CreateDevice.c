/*****************************************************************************!
 * Function : CreateDevice 
 *****************************************************************************/
CanDevice*
CreateDevice
(DeviceDef* InDeviceDef, uint16_t InDeviceCANAddress)
{
  CanDevice*                            device;
  int                                   m, reg;
  DeviceRegDef*                         regDef;

  device = &CanDeviceList[NumDevices];  
  NumDevices++;
  device->deviceDefinition = InDeviceDef;
  device->CanAddress = InDeviceCANAddress;
  m = DeviceDefGetRegCount(InDeviceDef);
  device->Registers = GetMemory(sizeof(CanReg) * m);
  device->registersCount = m;
  for ( reg = 0, regDef = InDeviceDef->regDefs->definitions; regDef; regDef = regDef->next, reg++) {
    device->Registers[reg].Value = regDef->initialValue;
    device->Registers[reg].registerDef = regDef;
  }
  device->State = normal;
  return device;
}
