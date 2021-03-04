/*******************************************************************************!
 * Function : CreateDeviceMessageDefList
 *******************************************************************************/
DeviceMessageDefList*
CreateDeviceMessageDefList
()
{
    DeviceMessageDefList*               messageDefs;

    messageDefs = (DeviceMessageDefList*)GetMemory(sizeof(DeviceMessageDefList));
    memset(messageDefs, 0x00, sizeof(DeviceMessageDefList));
    return messageDefs;
}
