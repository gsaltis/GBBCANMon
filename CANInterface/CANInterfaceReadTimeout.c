/******************************************************************************!
 * Function : CANInterfaceReadTimeout
 ******************************************************************************/
uint8_t
CANInterfaceReadTimeout
(CANInterface* InInterface, uint32_t* InID, uint64_t* InData, uint8_t* InDataLength, uint8_t InTimeout)
{
  fd_set                                readSet;
  struct timeval                        tv;
  struct can_frame                      frame;
  int                                   retval;
  int                                   bytesRead;
  
  if ( NULL == InInterface ) {
    return CAN_READ_ERROR;
  }
  FD_ZERO(&readSet);
  FD_SET(InInterface->socket, &readSet);
  tv.tv_sec = 0;
  tv.tv_usec = 50000;

  retval = select(InInterface->socket + 1, &readSet, NULL, NULL, &tv);
  switch (retval) {
    case 1 : {
      bytesRead = read(InInterface->socket, &frame, sizeof(frame));
      if ( bytesRead == sizeof(frame) ) {
        *InID = frame.can_id & 0x7FFFFFFF;
        memcpy(InData, &(frame.data), sizeof(frame.data));
        *InDataLength = frame.can_dlc;
        if ( CANMonitorInput ) {
          int protocol, srcaddress, destaddress, messagetype, errortype, valuetype;
          ufloatbit32_t value;
          frameid id;
          id.data32 = *InID;
          dataframe data;
          data.data64 = ByteManageSwap8(*InData);
          GetRequestBreakdown(id, data, &protocol, &srcaddress, &destaddress, &messagetype, &errortype, 
                              &valuetype, &value);
          DeviceDef* devicedef = FindDeviceDefByProtocol(mainDeviceDefs, protocol);
          DeviceMessageDef* messagedef = FindMessageDefByMessageType(devicedef->messageDefs, messagetype);
 
          printf("%08X %016llX %d %6s %3d %02x : %s\n", *InID, data.data64, *InDataLength, devicedef->name, destaddress, messagetype, messagedef->messageName);
        }
        return CAN_READ_OK;
      }
      break;
    }

    case 0 : {
      return CAN_READ_TIMEOUT;
      break;
    }

    case -1 : {
      return CAN_READ_ERROR;
      break;
    }

  }
  return CAN_READ_UNKNOWN;
}
