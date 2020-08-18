/*****************************************************************************!
 * Function : MainDisplayHelp
 *****************************************************************************/
void
MainDisplayHelp
()
{
  fprintf(stdout, "Usage : %s options\n", MainProgramName);
  fprintf(stdout, "        options\n");
  fprintf(stdout, "        -h,  --help                       - Display this help screen\n");
  fprintf(stdout, "        -W,  --websocketport portnumber   - Specify the web socket port number\n");
  fprintf(stdout, "        -cl, --cleardatabase              - Clear the values database\n");
  fprintf(stdout, "        -ci, --caninterface interfacename - Specify the CAN interface name\n");  
  fprintf(stdout, "        -id, --installdir dirname         - Specifiy the base directory for system files\n");
  fprintf(stdout, "        -l,  --logfile                    - Specify the log filename\n");
  fprintf(stdout, "        -n,  --noui                       - Specify to not use the command line interface\n");
}
