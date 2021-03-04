/*******************************************************************************!
 * Function : DeviceDefGetMessageCount
 *******************************************************************************/
int
DeviceDefGetMessageCount
(
 DeviceDef*                             InDeviceDef
)
{
    if ( NULL == InDeviceDef ) {
        return 0;
    }
    return GetDeviceMessageCount(InDeviceDef->messageDefs);
}
