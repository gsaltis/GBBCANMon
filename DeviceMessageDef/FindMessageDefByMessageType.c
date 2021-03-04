/*******************************************************************************!
 * Function : FindMessageDefByMessageType
 *******************************************************************************/
DeviceMessageDef*
FindMessageDefByMessageType
(
 DeviceMessageDefList*                  InMessageDefs,
 int                                    InMessageType
)
{
    DeviceMessageDef*               messageDef;
    
    for ( messageDef = InMessageDefs->definitions; messageDef; messageDef = messageDef->next ) {
        if ( messageDef->msgType == InMessageType ) {
            return messageDef;
        }
    }
    return NULL;
}
