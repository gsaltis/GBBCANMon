/*****************************************************************************!
 * Function : EnableDevice
 *****************************************************************************/
bool EnableDevice(char* DeviceName, int Num)
{
    CanDevice* MyDevice = FindDevice(DeviceName, Num);
    if (MyDevice != NULL)
        MyDevice->State = normal;
    else
        printf_safe("Device is not found. \n");
    return true;
}
