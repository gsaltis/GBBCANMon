/*****************************************************************************!
 * Function : MainOpenDatabase
 *****************************************************************************/
void
MainOpenDatabase
()
{
  int                                   n;

  n = sqlite3_open(MainDatabaseName, &MainDatabase);
  if ( SQLITE_OK != n ) {
    fprintf(stderr, "Could not open database %s\n", MainDatabaseName);
    exit(EXIT_FAILURE);
  }
}
