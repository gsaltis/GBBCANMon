/*****************************************************************************!
 * Function : SetRegisterValueFlat
 *****************************************************************************/
void SetRegisterValueFloat(char* DeviceName, int Count, int RegisterNum, float NewValue)
{
    ufloatbit32_t Value; Value.fd = NewValue;
    SetRegisterValue(DeviceName, Count, RegisterNum, Value);
}
