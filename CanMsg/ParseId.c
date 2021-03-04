/*****************************************************************************!
 * Function : ParseId
 *****************************************************************************/
void ParseId(frameid Id, int* Protocol, int* SrcAddr, int* DestAddr)
{
        *Protocol = GetProtocolBits(Id.data32);
        *SrcAddr = GetSrcBits(Id.data32);
        *DestAddr = GetDestBits(Id.data32);
}
