/*******************************************************************************!
 * Function : DeviceDefErrorCodeToString
 *******************************************************************************/
char*
DeviceDefErrorCodeToString
(
 int                                    InErrorCode
)
{
    switch(InErrorCode) {
        case DEVICE_DEF_OK :
            return "OK";
            
        case DEVICE_DEF_DUPLICATE_DEVICE :
            return "Duplicate Device";
            
        case DEVICE_DEF_MISSING_NAME :
            return "Missing name";

        case DEVICE_DEF_MISSING_DESC :
            return "Missing description";
            
        case DEVICE_DEF_MISSING_CAN_ADDRESS :
            return "CAN Address";
            
        case DEVICE_DEF_MISSING_PROTOCOL :
            return "Missing Protocol";
            
        case DEVICE_DEF_NULL_DEVICE_LIST :
            return "Empty Device Definition List";
            
        case DEVICE_DEF_GENERAL_ERROR : 
            return "General Error";
    }
    return "";
}
