/*****************************************************************************!
 * Function : MainClearDatabase
 *****************************************************************************/
void
MainClearDatabase
()
{
  string                                statement;
  char*                                 errormessage;

  statement = "DELETE from RegisterValues;";
  if ( SQLITE_OK != sqlite3_exec(MainDatabase, statement, NULL, NULL, &errormessage) ) {
    fprintf(stderr, "SQL Error : %s %s\n", statement, errormessage);
    sqlite3_free(errormessage);
  }
}
