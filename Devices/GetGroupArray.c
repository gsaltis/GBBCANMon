/*******************************************************************************!
 * Function : GetGroupArray
 *******************************************************************************/
#ifdef IMPLEMENTED
void GetGroupArray(int* FullGroupList, DeviceDef* InDeviceDef)
{
    DeviceRegDef*                       regDef;
    DeviceRegDef*                       regDefPrev;
    int                                 GroupIndex;
    for (int i = 0; i < MAXGROUPS; i++) {
        FullGroupList[i] = -1;
    }
    GroupIndex = 0;
    for ( int reg = 0, regDef = InDeviceDef->regDefs->definitions; regDef; regDef = regDef->next, reg++ ) {
        if (reg == 0) {
            FullGroupList[GroupIndex] = reg;
            GroupIndex++;
        } else {
            if (strcasecmp(regDef->group, regDefPrev->group) != 0) {
                bool Found = false;
                for (int grp = 0; ((grp < MAXGROUPS) && (FullGroupList[grp] != -1)); grp++) {
                    if (strcasecmp(regDef->group, InDeviceDef->RegDefList[FullGroupList[grp]].Group) == 0) {
                        Found = true;
                    }
                }
                if (!Found) {
                    FullGroupList[GroupIndex] = reg; GroupIndex++; // put the group name in the list
                }
            }
        }
        regDefPrev = regDef;
    }
}
#endif
