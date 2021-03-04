/*****************************************************************************!
 * Function : SetRegisterValueHex
 *****************************************************************************/
void SetRegisterValueHex(char* DeviceName, int Count, int RegisterNum, uint32_t NewValue)
{
    ufloatbit32_t Value; Value.data32 = NewValue;
    SetRegisterValue(DeviceName, Count, RegisterNum, Value);
}
