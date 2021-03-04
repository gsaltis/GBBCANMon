/*****************************************************************************!
 * Function : DeviceDefListToJSON
 *****************************************************************************/
string
DeviceDefListToJSON
(DeviceDefList* InDeviceDefs)
{
  string				returnString;
  string				defString;
  DeviceDef*				def;

  if ( InDeviceDefs == NULL ) {
    return NULL;
  }
  returnString = StringCopy("  [\n");

  for ( def = InDeviceDefs->defs; def; def = def->next ) {
    defString = DeviceDefToJSON(def);
    returnString = StringConcatTo(returnString, defString);
    FreeMemory(defString);
    if ( def->next ) {
      returnString = StringConcatTo(returnString, ",\n");
    } else {
      returnString = StringConcatTo(returnString, "\n");
    }
  }
  returnString = StringConcatTo(returnString, "  ]");
  return returnString;
}
