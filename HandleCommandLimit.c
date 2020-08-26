/*****************************************************************************!
 * Function : HandleCommandLimit
 *****************************************************************************/
void
HandleCommandLimit
(StringList* InString)
{
  if ( InString == NULL ) {
	return;
  }
  printf("Limit : ");
  if ( InString->stringCount == 1 ) {
    if ( StringEqual(MainLimitType, "none") ) {
	  printf("None\n");
    } else if ( StringEqual(MainLimitType, "days") ) {
	  printf(" %d Days\n", MainLimitDays);
    } else if ( StringEqual(MainLimitType, "hours") ) {
	  printf(" %d Hours\n", MainLimitHours);
    } else if ( StringEqual(MainLimitType, "size") ) {
	  printf(" %d Size : %d Used\n", MainLimitSize, MainLimitSizeRuntime);
    } else if ( StringEqual(MainLimitType, "count") ) {
	  printf(" %d Messages : %d used\n", MainLimitCount, CANInterfaceMessagesCount);
    }
    printf("\n");
  } else {
 	HandleCommandLimitSet(InString);
  }
}

