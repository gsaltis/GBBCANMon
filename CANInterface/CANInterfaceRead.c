/******************************************************************************!
 * Function : CANInterfaceRead
 ******************************************************************************/
uint8_t
CANInterfaceRead
(CANInterface* InInterface, uint32_t* InID, uint64_t* InData, uint8_t* InDataLength)
{
  return CANInterfaceReadTimeout(InInterface, InID, InData, InDataLength, CAN_DEFAULT_TIMEOUT);
}
