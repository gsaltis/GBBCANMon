/*****************************************************************************!
 * Function : DeviceRegDefToJSON
 *****************************************************************************/
string
DeviceRegDefToJSON
(DeviceRegDef* InDefinition)
{
  string                                defString;
  char                                  s[15];

  defString = StringCopy("  {\n");
  sprintf(s, "%d, ",  InDefinition->valueType);
  defString = StringConcatTo(defString, "\"valuetype\" : ");
  defString = StringConcatTo(defString, s);
  
  sprintf(s, "%d, ", InDefinition->messageType);
  defString = StringConcatTo(defString, "\"msgtype\" : ");
  defString = StringConcatTo(defString, s);

  defString = StringConcatTo(defString, "\"group\" : \"");
  defString = StringConcatTo(defString, InDefinition->group);
  defString = StringConcatTo(defString, "\",\n");

  defString = StringConcatTo(defString, "\"groupsort\" : \"");
  defString = StringConcatTo(defString, InDefinition->groupsort);
  defString = StringConcatTo(defString, "\",\n");
 
  defString = StringConcatTo(defString, "\"name\" : \"");
  defString = StringConcatTo(defString, InDefinition->name);
  defString = StringConcatTo(defString, "\",\n");

  defString = StringConcatTo(defString, "\"abbrev\" : \"");
  defString = StringConcatTo(defString, InDefinition->shortName);
  defString = StringConcatTo(defString, "\",\n");

  defString = StringConcatTo(defString, "\"displaylabel\" : \"");
  defString = StringConcatTo(defString, InDefinition->displayLabel);
  defString = StringConcatTo(defString, "\",\n");

  defString = StringConcatTo(defString, "\"format\" : ");
  sprintf(s, "%d\n", InDefinition->formatType);
  defString = StringConcatTo(defString, s);
  defString = StringConcatTo(defString, "  }");
  return defString;
}
