/*******************************************************************************!
 * Function : GetDeviceMessageCount
 *******************************************************************************/
int
GetDeviceMessageCount
(
 DeviceMessageDefList*                  InMessageDefs
)
{
    int                                 i;
    DeviceMessageDef*                   messageDef;
    
    if ( NULL == InMessageDefs ) {
        return 0;
    }
    
    for ( messageDef = InMessageDefs->definitions, i = 0 ;
          messageDef;
          messageDef = messageDef->next, i++) {}
    
    return i;
}
