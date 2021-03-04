/*******************************************************************************!
 * Function : ReadDeviceReg
 *******************************************************************************/
DeviceRegDef*
ReadDeviceReg
(
 FILE*                                  InFile  
)
{
    char                                token[DEF_FILE_TOKEN_MAX_LENGTH+1];
    int                                 state = 0;
    DeviceRegDef*                       regDef;
    bool                                b;
    int                                 n;
    float                               f;
    
    regDef = CreateDeviceRegDef();

    while (1) {
        if ( NULL == ReadDefTokenFromFile(token, InFile, DEF_FILE_TOKEN_MAX_LENGTH) ) {
            FreeMemory(regDef);
            // This is an error
            break;
        }    
        if ( *token == 0x00 ) {
            // This is ok just a blank line or just a comment line
            continue;
        }
        if ( strcmp(token, "RegDefEnd") == 0 ) {
            if ( state == REG_DEF_READ_END_STATE ) {
                return regDef;
            } 
            FreeMemory(regDef);
            return NULL;
        }
        switch (state) {
            case 0 : {
                strcpy(regDef->name, token);
                state++;
                break;
            }
            case 1 : {
                strcpy(regDef->shortName, token);
                state++;
                break;
            }
            case 2 : {
                strcpy(regDef->displayLabel, token);
                state++;
                break;
            }
            case 3 : {
                strcpy(regDef->group, token);
                state++;
                break;
            }
            case 4 : {
                n = GetIntValueFromString(&b, token);
                if (b) {
                    regDef->valueType = n;
                    state++;
                } else {
                    FreeMemory(regDef);
                    return NULL;
                }
                break;
            }
            case 5 : {
                f = GetFloatValueFromString(&b, token);
                if ( b ) {
                    regDef->initialValue.fd = f;
                    state++;
                } else {
                    FreeMemory(regDef);
                    return NULL;
                }
                break;
            }
            case 6 : {
                n = GetIntValueFromString(&b, token);
                if ( b ) {
                    regDef->messageType = n;
                    state++;
                } else {
                    FreeMemory(regDef);
                    return NULL;
                }
                break;
            }
        }
    }
    return regDef;
}
