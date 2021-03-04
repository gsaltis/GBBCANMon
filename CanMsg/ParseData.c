/*****************************************************************************!
 * Function : ParseData
 *****************************************************************************/
void ParseData(dataframe Data, int* IncomingMsgType, int* IncomingValueType, int* IncomingErrType, ufloatbit32_t* IncomingValue)
{
        *IncomingMsgType        = GetMsgTypeBits(Data.data64);
        *IncomingValueType      = GetValTypeBits(Data.data64);
        (*IncomingValue).data32 = GetValBits(Data.data64);
        *IncomingErrType        = GetErrTypeBits(Data.data64);
}
