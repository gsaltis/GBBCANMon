/*******************************************************************************!
 * Function : DestroyDeviceRegDef
 *******************************************************************************/
void
DestroyDeviceRegDef
(
 DeviceRegDef*                       InRegDef
)
{
    if ( NULL == InRegDef ) {
        return;
    }
    FreeMemory(InRegDef);
}
