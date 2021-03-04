/*****************************************************************************!
 * Function : DeviceRegDefCompareByNumber
 *****************************************************************************/
static int
DeviceRegDefCompareByNumber
(const void* InPointer1, const void* InPointer2)
{
  DeviceRegDef**                        reg1;
  DeviceRegDef**                        reg2;

  reg1 = (DeviceRegDef**)InPointer1;
  reg2 = (DeviceRegDef**)InPointer2;

  return (*reg1)->valueType - (*reg2)->valueType;
}
