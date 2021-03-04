/*******************************************************************************!
 * Function : CreateDeviceDefList
 *******************************************************************************/
DeviceDefList*
CreateDeviceDefList
()
{
    DeviceDefList*                      deviceDefs;
    deviceDefs = (DeviceDefList*)GetMemory(sizeof(DeviceDefList));
    memset(deviceDefs, 0x00, sizeof(DeviceDefList));
    return deviceDefs;
}
