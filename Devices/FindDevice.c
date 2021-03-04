/*****************************************************************************!
 * Function FindDevice
 *****************************************************************************/
CanDevice* FindDevice(char* DeviceName, int Count)
{
    for (int i = 0; i < NumDevices; i++)  // for each device
    {
        if (strcasecmp(CanDeviceList[i].deviceDefinition->name, DeviceName) == 0)  // found match for my device name
            if ((CanDeviceList[i].CanAddress - CanDeviceList[i].deviceDefinition->canAddressStart + 1) == Count) // and found my device
                return &CanDeviceList[i];
    }
    return NULL;
}
