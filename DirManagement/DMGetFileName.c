/*******************************************************************************!
 * Function : DMGetFileName
 *******************************************************************************/
char*
DMGetFileName
(
 char*                                  InReturnFileName,
 const char*                            InFileName,
 uint16_t                               InMaxFileNameLength
)
{
    if ( NULL == InReturnFileName || InMaxFileNameLength < DMMinFileLength ) {
        return NULL;
    }
    strcpy(InReturnFileName, DMBaseDirectoryName);
    strcat(InReturnFileName, InFileName);
    return InReturnFileName;
}
