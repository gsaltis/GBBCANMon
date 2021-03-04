/*******************************************************************************!
 * Function : GetGroupAndAbbrev
 *******************************************************************************/
void GetGroupAndAbbrev(int Protocol, int ValueType, char* MyGroup, char* MyAbbrev)
{
    DeviceDef* deviceDef;
    DeviceRegDef* regDef;
    
    strcpy(MyGroup, "<none>");
    strcpy(MyAbbrev, "<none>");
    for ( deviceDef = mainDeviceDefs->defs; deviceDef; deviceDef = deviceDef->next ) {
        if (deviceDef->protocolNumber == Protocol ) {
            regDef = FindRegDefByValue(deviceDef->regDefs, ValueType);
            if ( regDef ) {
                strcpy(MyGroup, regDef->group);
                strcpy(MyAbbrev, regDef->shortName);
            }
        }
    }
}
