/*****************************************************************************!
 * Function : DeviceRegDefListToJSON
 *****************************************************************************/
string
DeviceRegDefListToJSON
(DeviceRegDefList* InDefinitions)
{
  string                                defsString;
  string                                defString;
  DeviceRegDef*                         regDef;

  defsString = StringCopy("  [\n");
  for ( regDef = InDefinitions->definitions; regDef; regDef = regDef->next ) {
    defString = DeviceRegDefToJSON(regDef);
    defsString = StringConcatTo(defsString, defString);
    FreeMemory(defString);
    if ( regDef->next ) {
      defsString = StringConcatTo(defsString, ",\n");
    } else {
      defsString = StringConcatTo(defsString, "\n");
    } 
  }
  
  defsString = StringConcatTo(defsString, "  ]");
  return defsString;
}
