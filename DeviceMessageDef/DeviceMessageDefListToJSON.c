/*****************************************************************************!
 * Function : DeviceMessageDefListToJSON
 *****************************************************************************/
string
DeviceMessageDefListToJSON
(DeviceMessageDefList* InMessageList, bool InIncludeResponses)
{
  string				response;
  DeviceMessageDef*			messageDef;
  string				s;

  response = StringCopy("  [\n");
  for ( messageDef = InMessageList->definitions; messageDef; messageDef = messageDef->next ) {
    s = DeviceMessageDefToJSON(messageDef, InIncludeResponses);
    response = StringConcatTo(response, s);
    FreeMemory(s);
    if ( messageDef->next ) {
      response = StringConcatTo(response, ",\n");
    } else {
      response = StringConcatTo(response, "\n");
    }
  }
  response = StringConcatTo(response, "\n  ]");
  return response;
}
