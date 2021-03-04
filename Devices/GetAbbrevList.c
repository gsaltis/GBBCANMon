/*****************************************************************************!
 * Function : GetAbbrevList
 *****************************************************************************/
void GetAbbrevList(char* AbbrevList, char* GroupName, DeviceDef* MyDeviceDef)
{
    bool FirstFound = false;
    bool FoundNumber = false;
    strcpy(AbbrevList, "<no registers found>");
    char FirstNum[SHORTSTRINGLEN];
    char LastNum[SHORTSTRINGLEN];
    for ( DeviceRegDef* regDef = MyDeviceDef->regDefs->definitions; regDef; regDef = regDef->next ) {
        char MyDeviceGroupName[SHORTSTRINGLEN];
        strcpy(&MyDeviceGroupName[0], regDef->group);
        char IncomingGroupName[SHORTSTRINGLEN];
        strcpy(&IncomingGroupName[0], &GroupName[0]);
        if (strcasecmp(IncomingGroupName, MyDeviceGroupName) == 0)
        {
            if (strcasecmp("1", regDef->shortName) == 0) {
                FoundNumber = true;
                strcpy(&FirstNum[0], regDef->shortName);
            }
            if (FoundNumber)
                strcpy(&LastNum[0], regDef->shortName);
            else if (!FirstFound) {
                strcpy(AbbrevList, regDef->shortName);
                FirstFound = true;
            } else {
                strcat(AbbrevList, ", ");
                strcat(AbbrevList, regDef->shortName);
            }
        }
    }
    if (FoundNumber)
        sprintf(AbbrevList, "%s to %s", FirstNum, LastNum);
}
