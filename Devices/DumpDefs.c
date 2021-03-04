/*****************************************************************************!
 * Function : DumpDefs
 *****************************************************************************/
void DumpDefs()
{
#ifdef IMPLEMENTED
DeviceDef* deviceDef;
    DeviceRegDef* regDef;
    
    for ( deviceDef = mainDeviceDefs->defs; deviceDef; deviceDef = deviceDef->next ) {
        printf_safe("\n\n%sDevice  Start address: 0x%04X Protocol: 0x%04X Device: %s NumRegisters: %d %s\n", ColorRed, deviceDef->canAddressStart, deviceDef->protocolNumber, deviceDef->name, DeviceDefGetRegCount(deviceDef), ColorWhite);
        for ( regDef = deviceDef->regDefs->definitions; regDef; regDef = regDef->next ) {
            printf_safe("Register: 0x%04X Initial value: %f 0x%08X Name: %s %s Type: 0x%04X \n", RegDef->ValueType, RegDef->InitialValue.fd, RegDef->InitialValue.data32, RegDef->Group, RegDef->Abbrev, RegDef->MsgType);
        }

        char GroupList[COMMANDSIZE]; strcpy(GroupList, "");
        char MyGroup[COMMANDSIZE]; strcpy(MyGroup, "");
        char MyAbbrev[COMMANDSIZE*2]; strcpy(MyAbbrev, "");

        GetGroupList(&GroupList[0], MyDeviceDef);
        printf_safe("\nGroups: %s\n", GroupList);

        int FullGroupList[MAXGROUPS];
        GetGroupArray(&FullGroupList[0], MyDeviceDef);
        for (int i = 0; i < MAXGROUPS; i++)
        {
            if (FullGroupList[i] != -1)
            {
                strcpy(MyGroup, MyDeviceDef->RegDefList[FullGroupList[i]].Group);
                GetAbbrevList(&MyAbbrev[0], &MyGroup[0], MyDeviceDef);
                printf_safe("Register abbreviations for %s: %s \n", MyGroup, MyAbbrev);
            }
        }
    }
#endif
}
