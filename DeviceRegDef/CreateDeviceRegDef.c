/*******************************************************************************!
 * Function : CreateDeviceRegDef
 *******************************************************************************/
DeviceRegDef*
CreateDeviceRegDef
()
{
    DeviceRegDef*                       regDef;
    
    regDef = (DeviceRegDef*)GetMemory(sizeof(DeviceRegDef));
    memset(regDef, 0x00, sizeof(DeviceRegDef));
    return regDef;
}
