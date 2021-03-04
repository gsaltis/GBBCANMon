/*****************************************************************************!
 * Function : DumpGroup
 *****************************************************************************/
void DumpGroup(char* DeviceName, int Count, char* GroupName)
{
    CanDevice* MyDevice = FindDevice(DeviceName, Count);
    if (MyDevice == NULL) {
        printf_safe("Device not found. \n");
        return;
    }
    
    for ( DeviceRegDef* regDef = MyDevice->deviceDefinition->regDefs->definitions; regDef; regDef = regDef->next ) {
        CanReg* Reg = GetRegisterByDef(MyDevice, regDef);
        if (strcasecmp(regDef->group, GroupName) == 0) {
            printf_safe("Device register: 0x%04X %16s %16s value: 0x%08X %f\n", regDef->valueType, regDef->group, regDef->shortName, Reg->Value.data32, Reg->Value.fd);
        }
    }
}
