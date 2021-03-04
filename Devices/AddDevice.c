/*****************************************************************************!
 * Function AddDevice
 *****************************************************************************/
bool AddDevice(char* DeviceName, int Count)
{
    for (int j = 0; j < Count; j++) {
        CanDevice* device = AddSingleDevice(DeviceName);
        if ( device ) {
            printf_safe("Added Device: %s at address %04X with protocol %03X \n", DeviceName, device->CanAddress, device->deviceDefinition->protocolNumber);
        }
    }
    return true;
}
