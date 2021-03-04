/*******************************************************************************!
 * Function : FindRegDefByValue
 *******************************************************************************/
DeviceRegDef*
FindRegDefByValue
(DeviceRegDefList* InDefinitions, int InValue)
{
  DeviceRegDef*                       regDef;
    
  if ( InDefinitions == NULL ) {
    return NULL;
  }
    
  for (regDef = InDefinitions->definitions; regDef; regDef = regDef->next) {
    if ( regDef->valueType == InValue ) {
      return regDef;
    }
  }
  return NULL;
}
