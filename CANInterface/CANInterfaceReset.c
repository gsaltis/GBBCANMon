/******************************************************************************!
 * Function : CANInterfaceReset
 ******************************************************************************/
void
CANInterfaceReset
()
{
  char*                                 stopInterface = "bash ./slcan_remove";
  char*                                 startInterface = "bash ./slcan_add";

  // CLILogMessage("Stopping the CAN Interface\n");
  system (stopInterface);
  sleep(2);
  // CLILogMessage("Starting the CAN Interface\n");
  system(startInterface);
  sleep(3);
}
