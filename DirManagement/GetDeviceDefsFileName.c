/*******************************************************************************!
 * Function : GetDeviceDefsFileName
 *******************************************************************************/
char*
GetDeviceDefsFileName
(
 char*                                  InFileName,
 uint16_t                               InMaxFileNameLength
)
{
    return DMGetFileName(InFileName, DMDeviceDefsFileName, InMaxFileNameLength);
}
