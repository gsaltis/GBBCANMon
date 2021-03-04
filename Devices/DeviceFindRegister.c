/*******************************************************************************!
 * Function : DeviceFindRegister
 * Purpose  : Find a Register in name by short name and gorup
 *******************************************************************************/
CanReg*
DeviceFindRegister
(
 CanDevice*                             InDevice,
 char*                                  InShortName,
 char*                                  InGroup
)
{
    int                                 n = GetDeviceRegCount(InDevice->deviceDefinition->regDefs);
    for (int i = 0; i < n; i++) {
        if ( strcmp(InDevice->Registers[i].registerDef->group, InGroup) == 0 &&
             strcmp(InDevice->Registers[i].registerDef->shortName, InShortName) == 0 ) {
            return &(InDevice->Registers[i]);
        }
    }
    return NULL;
}
