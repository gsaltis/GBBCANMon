/*******************************************************************************!
 * Function : AddSingleDevice
 *******************************************************************************/
CanDevice* AddSingleDevice(char* DeviceName)
{
  CanDevice*                            CurrDevice;
  int                                   MaxCanAddr = 0;
  uint32_t                              MaxSNLow = 0;
  bool                                  ExistingDevice = false;
  DeviceDef*                            deviceDef;
  int                                   reg;
  DeviceRegDef*                         regDef;
  int                                   m;

  // This section finds the largest CAN address and the largest SNLow used so far in existing devices.
  for (int dev = 0; dev < NumDevices; dev++) {
    CurrDevice = &CanDeviceList[dev];
    if (strcasecmp(DeviceName, CurrDevice->deviceDefinition->name) == 0) {
      ExistingDevice = true;  
      MaxCanAddr = max(MaxCanAddr, CurrDevice->CanAddress); 
      if (CurrDevice->deviceDefinition->UniqueSNLow) {
        for (reg = 0, regDef = CurrDevice->deviceDefinition->regDefs->definitions; regDef; regDef = regDef->next, reg++) {
          if ( regDef->valueType == 0x54 ) {
            MaxSNLow = max(MaxSNLow, CurrDevice->Registers[reg].Value.data32);
          }
        }
      }
    }
  }
  if (ExistingDevice) {
    MaxCanAddr = MaxCanAddr + 1; // use one higher than the highest CAN address found
    MaxSNLow = MaxSNLow + 1; // use the next serial number
  }

  deviceDef = FindDeviceDef(mainDeviceDefs, DeviceName);
  if ( deviceDef == NULL ) {
    return NULL;
  }

  CanDevice* Device = &CanDeviceList[NumDevices];  
  NumDevices++;
  Device->deviceDefinition = deviceDef;
  Device->CanAddress = max(deviceDef->canAddressStart, MaxCanAddr);
  m = DeviceDefGetRegCount(deviceDef);
  Device->Registers = GetMemory(sizeof(CanReg) * m);
  Device->registersCount = m;
  for ( reg = 0, regDef = deviceDef->regDefs->definitions; regDef; regDef = regDef->next, reg++) {
    Device->Registers[reg].Value = regDef->initialValue;
    Device->Registers[reg].registerDef = regDef;
#ifdef IMPLEMENTED
    if ((deviceDef->uniqueSNLow) && (DeviceDef->RegDefList[reg].ValueType == 0x54))
      Device->Registers[reg].Value.data32 = max(DeviceDef->StartingSNLow.data32, MaxSNLow);

#endif
  }
  Device->State = normal;
  return Device;
}
