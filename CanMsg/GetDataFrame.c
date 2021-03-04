/*****************************************************************************!
 * Function : GetDataFrame
 *****************************************************************************/
dataframe GetDataFrame(int ErrType, int MsgType, int ValueType, ufloatbit32_t Value)
{
        volatile dataframe Outbound;
        Outbound.data64 = 0;
        Outbound.data.MsgType = MsgType;
        Outbound.data.ErrType = ErrType;
        Outbound.data.ValueType = ValueType;
        Outbound.data.Value = Value.data32;
        if (ErrType != 0xF0)
        {
                Outbound.data.MsgType = Outbound.data.MsgType && 0x80;
        }
        return Outbound;
}
