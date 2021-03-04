/******************************************************************************!
 * Function : CANInterfaceTransaction
 ******************************************************************************/
uint8_t
CANInterfaceTransaction
(CANInterface* InInterface, uint32_t InID, uint64_t InData, uint8_t InDataLength,
 uint32_t* InReadID, uint64_t* InReadData, uint8_t* InReadDataLength,
 uint8_t InRetries, uint8_t InTimeout)
{
  int                                   i, n;

  CANInterfaceWrite(InInterface, InID, InData, InDataLength);
  for ( i = 0; i < InRetries; i++ ) {
    n = CANInterfaceReadTimeout(InInterface, InReadID, InReadData, 
                                InReadDataLength, InTimeout);
    if ( n == CAN_READ_OK ) {
      return CAN_READ_OK;
    }
    if ( n == CAN_READ_ERROR ) {
      return CAN_READ_ERROR;
    }
  }
  return CAN_READ_TIMEOUT;
}
