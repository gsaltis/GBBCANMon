/*******************************************************************************!
 * Function : ReadDefTokenFromFile
 *******************************************************************************/
char*
ReadDefTokenFromFile
(
 char*                                  InReturnToken,
 FILE*                                  InFile,
 uint16_t                               InMaxTokenLength
)
{
    char                                readString[DEF_FILE_TOKEN_MAX_LINE_LENGTH+1];
    
    if ( NULL == InReturnToken || NULL == InFile ) {
        return NULL;
    }
    
    // Check that we are not at end of file
    if ( feof(InFile) ) {
        return NULL;
    }
    
    // Try reading a line and check that we read something
    if ( NULL == fgets(readString, DEF_FILE_TOKEN_MAX_LINE_LENGTH+1, InFile) ) {
        return NULL;
    }
    
    // Send it to the string version of read token
    return ReadDefToken(InReturnToken, readString, InMaxTokenLength);
}
