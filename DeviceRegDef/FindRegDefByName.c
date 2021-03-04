/*******************************************************************************!
 * Function : FindRegDefByName
 *******************************************************************************/
DeviceRegDef*
FindRegDefByName
(
 DeviceRegDefList*                      InDefinitions, 
 char*                                  InName
)
{
    DeviceRegDef*                       regDef;
    
    if ( NULL == InDefinitions || NULL == InName ) {
        return NULL;
    }
    
    if ( *InName == 0x00 ) {
        return NULL;
    }

    for (regDef = InDefinitions->definitions; regDef; regDef = regDef->next) {
        if ( strcmp(regDef->name, InName) == 0 ) {
            return regDef;
        }
    }
    return NULL;
}
