/*****************************************************************************!
 * Function : DisableDevice
 *****************************************************************************/
bool DisableDevice(char* DeviceName, int Num)
{
    CanDevice* MyDevice = FindDevice(DeviceName, Num);
    if (MyDevice != NULL)
        MyDevice->State = offline;
    else
        printf_safe("Device is not found. \n");
    return true;
}
