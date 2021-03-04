/*****************************************************************************!
 * Function : HandleReguest
 *****************************************************************************/
void HandleRequest(CANInterface* InInterface, frameid Id, dataframe Data, time_t InTime)
{
    int Protocol;
    int SrcAddr;
    int DestAddr;
    int IncomingMsgType;
    int IncomingValueType, IncomingErrType;
    ufloatbit32_t IncomingValue;
    GetRequestBreakdown(Id, Data, &Protocol, &SrcAddr, &DestAddr, &IncomingMsgType, &IncomingErrType, &IncomingValueType, &IncomingValue);
    SendResponses(InInterface, Protocol, SrcAddr, DestAddr, IncomingMsgType, IncomingValueType, IncomingValue, InTime);
    return;
}
