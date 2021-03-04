/*****************************************************************************!
 * Function : GetFrameId
 *****************************************************************************/
frameid GetFrameId(int Protocol, int SrcAddr, int DestAddr, int Continue )
{ 
        volatile frameid Outbound;
        Outbound.data32 = 0;
        Outbound.msgbit.ProtNo = Protocol;
        Outbound.msgbit.PTP = 1;
        Outbound.msgbit.DstAddr = DestAddr; 
        Outbound.msgbit.SrcAddr = SrcAddr;
        Outbound.msgbit.CNT = Continue;
        Outbound.msgbit.RES1 = 1;
        Outbound.msgbit.RES2 = 1;
        return Outbound;
}
