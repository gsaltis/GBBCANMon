/*******************************************************************************
 * Function : GetCanDeviceDefByName
 *******************************************************************************/
DeviceDef*
GetCanDeviceDefByName
(char* InDefName)
{
    return FindDeviceDef(mainDeviceDefs, InDefName);
}
