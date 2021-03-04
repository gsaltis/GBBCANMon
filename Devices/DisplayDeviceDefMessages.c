/*****************************************************************************!
 * Function : DisplayDeviceDefMessages
 * Purpose  : Display all messages for a give Device Definition
 *****************************************************************************/
void
DisplayDeviceDefMessages
(DeviceDef* InDevice)
{
  DeviceMessageDef*                     messageDef;
  int                                   j;
 
  printf_safe("\n\n%sDevice  Start address: 0x%04X Protocol: 0x%04X Device: %s %s\n", ColorRed, InDevice->canAddressStart, InDevice->protocolNumber, InDevice->name, ColorWhite);
  for ( j = 0, messageDef = InDevice->messageDefs->definitions; messageDef; messageDef = messageDef->next, j++ ) {
    printf_safe("Message: %d 0x%04X \n", j, messageDef->msgType);
    for ( int k = 0 ; k < messageDef->responsesCount ; k++ ) {
      int valueType = messageDef->responses[k].responseType;
      DeviceRegDef* regDef = FindRegDefByValue(InDevice->regDefs, valueType);
      if ( regDef) {
        printf_safe("Message sends back: %d 0x%04X %f 0x%08X %s %d \n", k, regDef->valueType, regDef->initialValue.fd, regDef->initialValue.data32, regDef->name, regDef->messageType);
      } 
    } 
  } 
}
