/*******************************************************************************!
 * Function : CreateDeviceMessageDef
 *******************************************************************************/
DeviceMessageDef*
CreateDeviceMessageDef
()
{
    DeviceMessageDef*                   messageDef;
    
    messageDef = (DeviceMessageDef*)GetMemory(sizeof(DeviceMessageDef));
    memset(messageDef, 0x00, sizeof(DeviceMessageDef));
    
    return messageDef;
}
