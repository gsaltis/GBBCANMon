/*******************************************************************************!
 * Function : GetDeviceDataFileName
 *******************************************************************************/
char*
GetDeviceDataFileName
(
 char*                                  InFileName,
 uint16_t                               InMaxFileNameLength
)
{
    return DMGetFileName(InFileName, DMDeviceDataFileName, InMaxFileNameLength);
}
