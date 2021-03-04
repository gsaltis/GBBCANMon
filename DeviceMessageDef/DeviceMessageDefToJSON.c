/*****************************************************************************!
 * Function : DeviceMessageDefToJSON 
 *****************************************************************************/
string
DeviceMessageDefToJSON
(DeviceMessageDef* InMessageDef, bool InIncludeResponses)
{
  string				response;
  char					s[16];
  int					i;

  response = StringCopy("    {\n");
  response = StringConcatTo(response, "      \"name\" : \"");
  response = StringConcatTo(response, InMessageDef->messageName);
  response = StringConcatTo(response, "\",\n");

  response = StringConcatTo(response, "      \"deviceDefName\" : \"");
  response = StringConcatTo(response, InMessageDef->deviceDefParent->name);
  response = StringConcatTo(response, "\",\n");

  response = StringConcatTo(response, "      \"request\" : ");
  sprintf(s, "%d", InMessageDef->msgType);
  response = StringConcatTo(response, s);

  if ( InIncludeResponses ) {
    response = StringConcatTo(response, ",\n");
    response = StringConcatTo(response, "      \"responses\" : ");
    response = StringConcatTo(response, "      [ \n");
    for ( i = 0; i < InMessageDef->responsesCount; i++ ) {
      response = StringConcatTo(response, "        { \"responsetype\" : ");
      sprintf(s, "%d, ", InMessageDef->responses[i].responseType);
      response = StringConcatTo(response, s);
      response = StringConcatTo(response, " \"name\" : \"");
      response = StringConcatTo(response, InMessageDef->responses[i].responseDef->name);
      response = StringConcatTo(response, "\" }");      
      if ( i + 1 < InMessageDef->responsesCount ) {
        response = StringConcatTo(response, ",\n");
      } else {
        response = StringConcatTo(response, "\n");
      }
    }
    response = StringConcat(response, "]");
  }
  response = StringConcatTo(response, "\n    }");
  return response;
}
