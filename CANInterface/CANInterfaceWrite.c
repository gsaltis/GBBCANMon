/******************************************************************************!
 * Function : CANInterfaceWrite
 ******************************************************************************/
void
CANInterfaceWrite
(CANInterface* InInterface, uint32_t InID, uint64_t InData, uint8_t InDataLength)
{
  struct can_frame                      frame;

  if ( NULL == InInterface ) {
    return;
  }
  memset(&frame, 0x0, sizeof(frame));
  frame.can_id = InID| CAN_EFF_FLAG;
  memcpy(&(frame.data), &InData, sizeof(frame.data));
  frame.can_dlc = InDataLength;
  write(InInterface->socket, &frame, sizeof(frame));
}
