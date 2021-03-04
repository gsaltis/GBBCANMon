/*******************************************************************************!
 * Function : ClearDevice
 *  Purpose : Clear the contencts of a device structure. 
 *     Note : The register may be destroyed if InFreeRegisters is true
 *            otherwise the pointer is just set to NULL
 *******************************************************************************/
void
ClearDevice
(
 CanDevice*                             InDevice,
 bool                                   InFreeRegisters
)
{
    if ( NULL == InDevice ) {
        return;
    }
    if ( InFreeRegisters ) {
        FreeMemory(InDevice->Registers);
    }
    InDevice->CanAddress = 0;
    InDevice->State      = 0;
    InDevice->Registers  = NULL;
    InDevice->deviceDefinition        = NULL;
}
