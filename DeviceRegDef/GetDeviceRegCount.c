/*******************************************************************************!
 * Function : GetDeviceRegCount
 *******************************************************************************/
int
GetDeviceRegCount
(
 DeviceRegDefList*                      InDeviceRegDefs
)
{
    int                                 i;
    DeviceRegDef*                       regDef;
    
    if ( NULL == InDeviceRegDefs ) {
        return 0;
    }
    for (i = 0, regDef = InDeviceRegDefs->definitions; 
         regDef;
         regDef = regDef->next, i++) {}
    return i;
}
