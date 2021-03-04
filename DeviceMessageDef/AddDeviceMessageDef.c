/*******************************************************************************!
 * Function : AddDeviceMessageDef
 *******************************************************************************/
void
AddDeviceMessageDef
(
 DeviceMessageDefList*                  InMessageDefs,
 DeviceMessageDef*                      InMessageDef
)
{
    if ( NULL == InMessageDefs || NULL == InMessageDef ) {
        return;
    }
    if ( InMessageDefs->definitions == NULL ) {
        InMessageDefs->definitions = InMessageDef;
        InMessageDefs->lastDefinition = InMessageDef;
    } else {
        InMessageDefs->lastDefinition->next = InMessageDef;
        InMessageDefs->lastDefinition = InMessageDef;
    }
}
