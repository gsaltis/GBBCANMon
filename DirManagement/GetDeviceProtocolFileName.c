/*******************************************************************************!
 * Function : GetDeviceProtocolFileName
 *******************************************************************************/
char*
GetDeviceProtocolFileName
(
 char*                                  InFileName,
 uint16_t                               InMaxFileNameLength
)
{
    return DMGetFileName(InFileName, DMDeviceProtocolFileName, InMaxFileNameLength);
}
