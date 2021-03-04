/******************************************************************************!
 * Function : CANInterfaceClose
 ******************************************************************************/
void
CANInterfaceClose
(CANInterface* InInterface)
{
  if ( NULL == InInterface ) {
    return;
  }

  close(InInterface->socket);
  FreeMemory(InInterface->portName);
  FreeMemory(InInterface);
}
