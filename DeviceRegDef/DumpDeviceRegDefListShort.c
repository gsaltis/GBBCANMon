/*****************************************************************************!
 * Function : DumpDeviceRegDefListShort
 *****************************************************************************/
void
DumpDeviceRegDefListShort
(DeviceRegDefList* InDeviceDefRegList, int InIndent, int InSortOrder)
{
  DeviceRegDef*                         regDef;
  int                                   maxGroupLen, maxShortNameLen;
  int                                   maxNameLen, maxDisplayLabelLen;
  int                                   k, n, i;
  DeviceRegDef**                        regs;
 
  n = GetDeviceRegCount(InDeviceDefRegList);

  maxGroupLen        = 5;
  maxNameLen         = 4;
  maxShortNameLen    = 10;
  maxDisplayLabelLen = 13;

  for ( regDef = InDeviceDefRegList->definitions; 
        regDef;
        regDef = regDef->next ) {
    if ( maxNameLen < (k = strlen(regDef->name)) ) {
      maxNameLen = k;
    }
    if ( maxShortNameLen < (k = strlen(regDef->shortName)) ) {
      maxShortNameLen = k;
    }
    if ( maxDisplayLabelLen < (k = strlen(regDef->displayLabel)) ) {
      maxDisplayLabelLen = k;
    }
    if ( maxGroupLen < (k = strlen(regDef->group)) ) {
      maxGroupLen = k;
    }
  }
  regs = GetMemory(n * sizeof(DeviceRegDef*));
  for ( i = 0, regDef = InDeviceDefRegList->definitions; 
        regDef;
        regDef = regDef->next, i++ ) {
    regs[i] = regDef;
  }
  if ( InSortOrder == DEVICE_REG_SORT_NAME ) {
    qsort(regs, n, sizeof(DeviceRegDef*), DeviceRegDefCompareByName);
  } else  if ( InSortOrder == DEVICE_REG_SORT_GROUP ) {
    qsort(regs, n, sizeof(DeviceRegDef*), DeviceRegDefCompareByGroupName);
  } else if ( InSortOrder == DEVICE_REG_SORT_NUMBER ) {
    qsort(regs, n, sizeof(DeviceRegDef*), DeviceRegDefCompareByNumber);
  }  
  for (i = 0; i < n; i++ ) {
    DumpDeviceRegDefShort(regs[i], InIndent, maxNameLen, maxShortNameLen, maxGroupLen, maxDisplayLabelLen);
  }
  FreeMemory(regs);
}
