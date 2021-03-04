/*******************************************************************************!
 * Function : RemoveDevice
 *  Purpose : Remove a device from the CanDeviceList
 *     Note : This involves not only removing the devuce but shuffline the list
 *            to close up the gap created when the device was removed.
 *******************************************************************************/
int
RemoveDevice
(
 char*                                  InDeviceName,
 int                                    InDeviceNumber
)
{
    int                                 dev, newDeviceCount;
    CanDevice*                          currDevice;
    bool                                found;
    int                                 foundIndex;
    int                                 deviceAddress;
    
    // The external ID is the devices CAN Address + 1
    deviceAddress = InDeviceNumber - 1;
    
    // A small sanity check before we start things
    if ( NumDevices == 0 ) {
        return DEVICE_ERROR_DEVICE_NOT_FOUND;
    }
    
    found = false;
    foundIndex = -1;
    for ( dev = 0 ; dev < NumDevices && !found ; dev++ ) {
        currDevice = &CanDeviceList[dev];
        if ( strcasecmp(currDevice->deviceDefinition->name, InDeviceName) == 0 &&
             deviceAddress == currDevice->CanAddress ) {
            // Save the index of the now empty index space for when we shuffle the 
            // device list later
            foundIndex = dev;
            found = true;
            break;
        }
    }
    
    // We didn't find it, return an error
    if ( !found ) {
        return DEVICE_ERROR_DEVICE_NOT_FOUND;
    }
    
    // Clear the removed device and its associated registers
    ClearDevice(currDevice, true);

    // Remove device from table by shifting the devices higher in the table 
    // down one to fill the empty space in the array
    newDeviceCount = NumDevices-1;
    for ( dev = foundIndex; dev < NumDevices-1; dev++) {
        CopyDevice(&CanDeviceList[dev], &CanDeviceList[dev+1]);
    }
    
    // Clear the last entry in the array (it's been moved one to the left)
    ClearDevice(&CanDeviceList[newDeviceCount], false);
    NumDevices = newDeviceCount;
    return DEVICE_ERROR_NONE;
}
