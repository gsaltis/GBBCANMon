/*******************************************************************************!
 * Function : DestroyDeviceMessageDeviceList
 *******************************************************************************/
void
DestroyDeviceMessageDefList
(
 DeviceMessageDefList*                  InMessageDefs
)
{
    DeviceMessageDef*                   messageDef;
    DeviceMessageDef*                   nextMessageDef;
    
    if ( NULL == InMessageDefs ) {
        return;
    }
    
    messageDef = InMessageDefs->definitions;
    while (messageDef) {
        nextMessageDef = messageDef->next;
        DestroyDeviceMessageDef(messageDef);
        messageDef = nextMessageDef;
    }
    FreeMemory(InMessageDefs);
}
