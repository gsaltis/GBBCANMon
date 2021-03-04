/*******************************************************************************!
 * Function : GetDeviceCount
 *******************************************************************************/
void GetDeviceCount(char* CountList, DeviceDef* MyDeviceDef)
{
    int MaxCount = 0;
    for (int i = 0; i < NumDevices; i++) {
        if (CanDeviceList[i].deviceDefinition == MyDeviceDef) {
            MaxCount++;
        }
    }
    sprintf(&CountList[0], "1-%d", MaxCount);
}
