/*******************************************************************************!
 * Function : GetRegisterByGroup
 *******************************************************************************/
int GetRegisterByGroup(char* MyGroup, char* MyAbbrev, DeviceDef* MyDeviceDef)
{
    DeviceRegDef*                       regDef;
    
    for ( regDef = MyDeviceDef->regDefs->definitions; regDef; regDef = regDef->next ) {
        if ( strcmp(regDef->group, MyGroup) == 0 && strcmp(regDef->shortName, MyAbbrev) == 0 ) {
            return regDef->valueType;
        }
    }
    return 0;
}
