/*****************************************************************************!
 * Function : GetBitsI
 *****************************************************************************/
int GetBitsI(int InNum, int InMSB, int InLSB)
{
        uint64_t Temp1, Temp2, Temp3, Temp4;
        Temp1 = InNum >> InLSB;
        Temp4 = 1;
        Temp2 = (Temp4 << (InMSB - InLSB + 1)) - 1;
        Temp3 = Temp1 & Temp2;
        return Temp3;
}
