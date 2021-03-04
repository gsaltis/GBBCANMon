/*******************************************************************************!
 * Function : DeviceDefGetRegCount
 *******************************************************************************/
int
DeviceDefGetRegCount
(
 DeviceDef*                             InDeviceDef
)
{
    if ( NULL == InDeviceDef ) {
        return 0;
    }
    return GetDeviceRegCount(InDeviceDef->regDefs);
}
