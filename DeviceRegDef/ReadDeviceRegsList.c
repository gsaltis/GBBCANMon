/*******************************************************************************!
 * Function : ReadDeviceRegsList
 * Note     : We got here because we read an opening "RegDefs" token
 *            We will continue to read tokens until we run out of tokens
 *            (which is an error) or read a RegDefsEnd token
 *******************************************************************************/
DeviceRegDefList*
ReadDeviceRegList
(
 FILE*                                  InFile
)
{
    char                                token[DEF_FILE_TOKEN_MAX_LENGTH+1];
    DeviceRegDefList*                   regDefs;
    
    regDefs = CreateDeviceRegDefList();
    
    while (1) {
        if ( NULL == ReadDefTokenFromFile(token, InFile, DEF_FILE_TOKEN_MAX_LENGTH) )  {
            break;
        }
        if ( *token == 0x00 ) {
            continue;
        }
        if ( strcmp(token, "RegDefsEnd") == 0 ) {
            // We are at the end and done
            break;
        }
        if ( strcmp(token, "RegDef") == 0 ) {
            DeviceRegDef* regDef = ReadDeviceReg(InFile);
            AddDeviceRegDef(regDefs, regDef);
        }
    }
    return regDefs;
}
