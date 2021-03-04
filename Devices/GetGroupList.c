/*****************************************************************************!
 * Function : GetGroupList
 *****************************************************************************/
string GetGroupList(DeviceDef* MyDeviceDef)
{
  string                                returnString;
  StringList*                           list;

  list = StringListCreate();
    
  for (DeviceRegDef* regDef = MyDeviceDef->regDefs->definitions; regDef; regDef = regDef->next ) {
    if ( !StringListContains(list, regDef->group) ) {
      StringListAppend(list, regDef->group);
    }
  }

  returnString = StringListConcat(list, ", ");
  StringListDestroy(list);
  return returnString;
}
