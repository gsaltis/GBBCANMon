/*****************************************************************************!
 * Function : SetRegisterValue
 *****************************************************************************/
void SetRegisterValue(char* DeviceName, int Count, int RegisterNum, ufloatbit32_t NewValue)
{
    CanDevice* MyDevice = FindDevice(DeviceName, Count);
    if (MyDevice == NULL) {
        printf_safe("Device not found. \n");
        return;
    }
    int n = DeviceDefGetRegCount(MyDevice->deviceDefinition);
    for (int k = 0; k < n; k++) {
        CanReg* Reg = &MyDevice->Registers[k];
        if (RegisterNum == Reg->registerDef->valueType) {
            Reg->Value.data32 = NewValue.data32;
            printf_safe("%f 0x%08X is the new value of 0x%03X %s in %s - %d \n", 
                        Reg->Value.fd, Reg->Value.data32, Reg->registerDef->valueType, Reg->registerDef->name, MyDevice->deviceDefinition->name,
                        MyDevice->CanAddress);
            break;
        }
    }
}
