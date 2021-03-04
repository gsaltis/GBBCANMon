/*****************************************************************************!
 * Function : SendResponses
 *****************************************************************************/
void SendResponses(CANInterface* InInterface, int Protocol, int SrcAddr, int DestAddr, int IncomingMsgType, int IncomingValueType, ufloatbit32_t IncomingValue, time_t InTime)
{
  // printf_safe("Sending responses for 0x%02X 0x%02X 0x%02X 0x%04X 0x%04X 0x%08X %f \n" , Protocol, SrcAddr, DestAddr, IncomingMsgType, IncomingValueType, IncomingValue.data32 , IncomingValue.fd);
  for (int dev = 0; dev<NumDevices; dev++) {  // look through the list of devices
    CanDevice* CurrDevice = &CanDeviceList[dev];
    DeviceDef* currDeviceDef = CurrDevice->deviceDefinition;
        
    if (CurrDevice->State == offline) {
      continue;
    }
    if (currDeviceDef->protocolNumber != Protocol) {
      continue;
    }
    if ((CurrDevice->CanAddress != DestAddr) && (DestAddr != 0xFF)) {
      continue;
    }
    CurrDevice->lastContactTime = InTime;
    if ((IncomingMsgType == 0x01) || (IncomingMsgType == 0x73)) { // if this is a get request
      int n = DeviceDefGetRegCount(currDeviceDef);
      for (int reg = 0; reg < n; reg++) { // for each register in this device
        if (CurrDevice->Registers[reg].registerDef->valueType == IncomingValueType)  {// if the ValueType matches the ValueType in the request
          int Cont = 0;
          CanReg Reg = CurrDevice->Registers[reg];    // get the value for this register              
          frameid Id = GetFrameId(Protocol, CurrDevice->CanAddress, SrcAddr, Cont);
          dataframe Data = GetDataFrame(CurrDevice->State, Reg.registerDef->messageType, Reg.registerDef->valueType, Reg.Value);
          CANInterfaceWrite(InInterface, Id.data32, Data.data64, 8); // and send the value in the response
        }
      }
    } else if ((IncomingMsgType == 0x03) || (IncomingMsgType == 0x74)) { //if this is a set request
      int n = DeviceDefGetRegCount(currDeviceDef);
      for (int reg = 0; reg < n; reg++) { // for each register in the this device
        if (CurrDevice->Registers[reg].registerDef->valueType == IncomingValueType) { // if the ValueType matches the ValueType in the request
          CurrDevice->Registers[reg].Value = IncomingValue;  // set the value of this register to the incoming value in the request
        }
      }
    } else { // look up the response
      DeviceMessageDef* messageDef = FindMessageDefByMessageType(currDeviceDef->messageDefs, IncomingMsgType);
      if ( messageDef ) {
        for (int resp = 0; resp < messageDef->responsesCount; resp++) { // for each response in the list of responses for this MsgType
          DeviceMessageResponse Response = messageDef->responses[resp]; // this is the ValueType to send back
          DeviceRegDef* regDef = FindRegDefByValue(currDeviceDef->regDefs, Response.responseType);
          if ( regDef ) {
            CanReg* reg = GetRegisterByDef(CurrDevice, regDef);
            if ( reg ) {
              uint64_t                                  d;

              int Cont = resp + 1 < messageDef->responsesCount ? 1 : 0;
              frameid Id = GetFrameId(Protocol, CurrDevice->CanAddress, SrcAddr, Cont);
              dataframe Data = GetDataFrame(CurrDevice->State, reg->registerDef->messageType, reg->registerDef->valueType, reg->Value);
              d = ByteManageSwap8(Data.data64);
              CANInterfaceWrite(InInterface, Id.data32, d, 8);  // and send the register
            }
          }
        }
      }
    }
  }
}
