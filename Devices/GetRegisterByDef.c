/*****************************************************************************!
 * Function : GetRegisterByDef
 *****************************************************************************/
CanReg*
GetRegisterByDef
(
 CanDevice*                             InDevice,
 DeviceRegDef*                          InRegDef
)
{
    int                                 n = GetDeviceRegCount(InDevice->deviceDefinition->regDefs);
    for (int i = 0; i < n; i++) {
        if ( InDevice->Registers[i].registerDef == InRegDef ) {
            return &(InDevice->Registers[i]);
        }
    }
    return NULL;
}
