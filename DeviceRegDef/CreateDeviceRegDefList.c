/*******************************************************************************!
 * Function : CreateDeviceRegDefList
 *******************************************************************************/
DeviceRegDefList*
CreateDeviceRegDefList
()
{
    DeviceRegDefList*                   regDefs;
    
    regDefs = (DeviceRegDefList*)GetMemory(sizeof(DeviceRegDefList));
    memset(regDefs, 0x00, sizeof(DeviceRegDefList));
    return regDefs;
}
