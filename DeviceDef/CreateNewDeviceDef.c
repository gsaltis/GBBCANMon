/*******************************************************************************!
 * Function : CreateNewDeviceDef
 *******************************************************************************/
int
CreateNewDeviceDef
(
 char* InName, char* InDesc, int InCANAddressStart, int InProtocolNumber, int InMessageType, int InDisplayColumns, int InDisplayType, DeviceDefList* InDeviceDefs
)
{
    DeviceDef*                          deviceDef;
    
    if ( NULL == InDeviceDefs ) {
        return DEVICE_DEF_NULL_DEVICE_LIST;
    }
    
    if ( InName == NULL || InName[0] == 0x00 ) {
        return DEVICE_DEF_MISSING_NAME;
    }
    if ( InDesc == NULL || InDesc[0] == 0x00 ) {
        return DEVICE_DEF_MISSING_DESC;
    }
    if ( InProtocolNumber == 0 ) {
        return DEVICE_DEF_MISSING_PROTOCOL;
    }
    deviceDef = CreateDeviceDef();
    deviceDef->name = StringCopy(InName);
    deviceDef->desc = StringCopy(InDesc);
    deviceDef->messageType = InMessageType;
    deviceDef->protocolNumber = InProtocolNumber;
    deviceDef->displayColumns = InDisplayColumns;
    deviceDef->DisplayType = InDisplayType;
    AddDeviceDef(InDeviceDefs, deviceDef);
    return DEVICE_DEF_OK;
}
