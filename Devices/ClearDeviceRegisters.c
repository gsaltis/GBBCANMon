/*****************************************************************************!
 * Function : ClearDeviceRegisters
 *****************************************************************************/
void
ClearDeviceRegisters
(CanDevice* InDevice)
{
  int                                   i, n;
  
  n = DeviceDefGetRegCount(InDevice->deviceDefinition);
  for ( i = 0; i < n ; i++ ) {
    CanReg* reg = &InDevice->Registers[i];
    reg->Value.data32 = 0;
  }
}
