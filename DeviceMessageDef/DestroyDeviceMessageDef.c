/*******************************************************************************!
 * Function : DestroyDeviceMessageDef
 *******************************************************************************/
void
DestroyDeviceMessageDef
(
 DeviceMessageDef*                      InMessageDef
)
{
    if ( NULL == InMessageDef ) {
        return;
    }
    FreeMemory(InMessageDef);
}
