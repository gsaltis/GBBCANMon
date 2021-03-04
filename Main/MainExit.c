/*****************************************************************************!
 * Function : MainExit
 *****************************************************************************/
void
MainExit
()
{
  MainRemoveTarFiles();
  CANMonLogWrite("%s Exiting\n", MainProgramName);
}
