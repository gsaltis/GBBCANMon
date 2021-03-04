/*****************************************************************************!
 * Function :  DeviceRegDefFromJSON
 *****************************************************************************/
DeviceRegDef*
DeviceRegDefFromJSON
(json_value* InValue)
{
  DeviceRegDef*                         def;
  string                                s;
  bool                                  b;

  def = (DeviceRegDef*)GetMemory(sizeof(DeviceRegDef));
  memset(def, 0x00, sizeof(DeviceRegDef));

  def->valueType = JSONIFGetInt(InValue, "valuetype");
  def->messageType = JSONIFGetInt(InValue, "msgtype");

  s = JSONIFGetString(InValue, "group");
  strcpy(def->group, s);
  strcpy(def->groupsort, s);
  FreeMemory(s);

  s = JSONIFGetString(InValue, "groupsort");
  strcpy(def->groupsort, s);
  FreeMemory(s);
 
  s = JSONIFGetString(InValue, "name");
  strcpy(def->name, s);
  FreeMemory(s);

  s = JSONIFGetString(InValue, "abbrev");
  strcpy(def->shortName, s);
  FreeMemory(s);
 
  s = JSONIFGetString(InValue, "initvalue");
  def->initialValue.data32 = GetIntValueFromString(&b, s);
  FreeMemory(s);
    
  s = JSONIFGetString(InValue, "displaylabel");
  strcpy(def->displayLabel, s);
  FreeMemory(s);
  def->formatType = JSONIFGetInt(InValue, "format");

  return def;
}
