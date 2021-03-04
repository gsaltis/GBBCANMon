/*****************************************************************************!
 * Function : HandleCanTraffic
 *****************************************************************************/
#define BUFFERSIZE 1024
bool PortOpened = false;
void* HandleCanTraffic()
{
  CANInterface*                         iterface;
  iterface = CANInterfaceInit("slcan0");
  if ( NULL == iterface ) {
    while (true) { 
      sleep(1);
    }
  }
  while (true)
  {
    uint32_t                            id;
    uint64_t                            data;
    uint8_t                             dataLength;
    uint8_t                             result;

    result = CANInterfaceRead(iterface, &id, &data, &dataLength);
    switch ( result ) {
      case CAN_READ_TIMEOUT : {
        break;
      }
      case CAN_READ_OK : {
        frameid fid;
        fid.data32 = id;
        dataframe df;
        df.data64 = ByteManageSwap8(data);
        HandleRequest(iterface, fid, df, time(NULL)); 
        break;
      }
      case CAN_READ_ERROR : {
        break;
      }
      default : {
        break;
      }
    }
  }
  return 0;
}
