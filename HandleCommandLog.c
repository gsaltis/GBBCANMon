/*****************************************************************************!
 * Function : HandleCommandLog
 *****************************************************************************/
void
HandleCommandLog
(StringList* InParameters)
{
  char*                                 buffer;
  int                                   bufferLen;
  char**                                lines;
  int                                   linesLength;
  int                                   i;

  if ( !GetFileBuffer(CANMonLogFilename, &buffer, &bufferLen) ) {
    return;
  }

  GetFileLines(buffer, bufferLen, &lines, &linesLength);

  for ( i = 0; i < linesLength; i++ ) {
    printf("%s\n", lines[i]);
  }

  FreeMemory(buffer);
  for ( i = 0 ; i < linesLength; i++ ) {
    FreeMemory(lines[i]);
  }
  FreeMemory(lines);
}
