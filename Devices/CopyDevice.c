/*******************************************************************************!
 * Function : CopyDevice
 * Purpose  : Copy the contents of one device to another.
 *     Note : This is not a 'deep' copy, just the pointer to the registers
 *            is copied not all the registers.
 *******************************************************************************/
void
CopyDevice
(
 CanDevice*                             InTargetDevice,
 CanDevice*                             InSourceDevice
)
{
    if ( NULL == InTargetDevice || NULL == InSourceDevice ) {
        return;
    }
    InTargetDevice->CanAddress = InSourceDevice->CanAddress;
    InTargetDevice->State      = InSourceDevice->State;
    InTargetDevice->deviceDefinition        = InSourceDevice->deviceDefinition;
    InTargetDevice->Registers  = InSourceDevice->Registers;
}
