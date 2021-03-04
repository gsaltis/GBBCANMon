/*****************************************************************************!
 * Function : DeviceDefToJSON
 *****************************************************************************/
string
DeviceDefToJSON
(DeviceDef* InDeviceDef)
{
  string				returnString;
  char					s[16];  
  if ( NULL == InDeviceDef ) {
    return NULL;
  }
  returnString = StringCopy("    {\n");
  returnString = StringConcatTo(returnString, "      \"name\" : \"");
  returnString = StringConcatTo(returnString, InDeviceDef->name);
  returnString = StringConcatTo(returnString, "\",\n");
  
  returnString = StringConcatTo(returnString, "      \"description\" : \"");
  returnString = StringConcatTo(returnString, InDeviceDef->desc);
  returnString = StringConcatTo(returnString, "\",\n");
 
  returnString = StringConcatTo(returnString, "      \"startcanaddress\" : ");
  sprintf(s, "%d,\n", InDeviceDef->canAddressStart);
  returnString = StringConcatTo(returnString, s);
  
  returnString = StringConcatTo(returnString, "      \"protocol\" : ");
  sprintf(s, "%d\n", InDeviceDef->protocolNumber);
  returnString = StringConcatTo(returnString, s);
  
  returnString = StringConcatTo(returnString, "    }");

  return returnString;
}
