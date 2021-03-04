/*******************************************************************************!
 * Function : DeviceMessageDefAddResponseType
 *******************************************************************************/
void
DeviceMessageDefAddResponseType
(
 DeviceMessageDef*                      InMessageDef,
 int                                    InMessageType
)
{
    if ( NULL == InMessageDef ) {
        return;
    }
    
    if ( InMessageDef->responsesCount >= MAXRESP ) {
        return;
    }
    
    InMessageDef->responses[InMessageDef->responsesCount].responseType = InMessageType;
    InMessageDef->responsesCount++;
}
