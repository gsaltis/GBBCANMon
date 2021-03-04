/*****************************************************************************!
 * Function : GetRequestBreakdown
 *****************************************************************************/
void GetRequestBreakdown(frameid Id, dataframe Data, int* Protocol, int* SrcAddr, int* DestAddr, int* IncomingMsgType, int* IncomingErrType, int* IncomingValueType, ufloatbit32_t* IncomingValue)
{
  ParseId(Id, Protocol, SrcAddr, DestAddr);
  ParseData(Data, IncomingMsgType, IncomingValueType, IncomingErrType, IncomingValue);
  return;
}
