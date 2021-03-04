/*****************************************************************************!
 * Function : DeviceRegDefCompareByGroupName
 *****************************************************************************/
static int
DeviceRegDefCompareByGroupName
(const void* InPointer1, const void* InPointer2)
{
  DeviceRegDef**                        reg1;
  DeviceRegDef**                        reg2;
  int                                   n;

  reg1 = (DeviceRegDef**)InPointer1;
  reg2 = (DeviceRegDef**)InPointer2;

  n = strcmp((*reg1)->group, (*reg2)->group);
  if ( n != 0 ) {
    return n;
  }
  return strcmp((*reg1)->name, (*reg2)->name);
}
