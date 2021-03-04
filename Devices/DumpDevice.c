/*****************************************************************************!
 * Function : DumpDevice
 *****************************************************************************/
void DumpDevice(char* DeviceName, int Count)
{
    CanDevice* MyDevice = FindDevice(DeviceName, Count);
    if (MyDevice == NULL) {
         printf_safe("Device not found. \n");
         return;
    }
    int n = DeviceDefGetRegCount(MyDevice->deviceDefinition);
    for ( int k = 0 ; k < n ; k++ ) {
        CanReg* reg = &MyDevice->Registers[k];
        printf_safe("Device register: 0x%04X %16s %16s value: 0x%08X %f\n", reg->registerDef->valueType, reg->registerDef->group, reg->registerDef->shortName, reg->Value.data32, reg->Value.fd );
    }
}
