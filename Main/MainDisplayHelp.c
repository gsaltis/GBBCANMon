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
  fprintf(stdout, "        -v,  --verbose                    - Be verbose in interactive messages\n");
  fprintf(stdout, "        -c,  --constraint type            - Specify the file constraint type\n");
  fprintf(stdout, "                                            (none | size | days | hours | count)\n");
  fprintf(stdout, "        -C,  --constrainsize size         - Specify the file constraint size\n");
  fprintf(stdout, "                                             size : %d -- %d (in Megabytes)\n", MainMinLimitSize, MainMaxLimitSize / 1000000);
  fprintf(stdout, "                                            count : %d -- %d\n", MainMinLimitCount, MainMaxLimitCount);
  fprintf(stdout, "                                            hours : %d -- %d\n", MainMinLimitHours, MainMaxLimitHours);
  fprintf(stdout, "                                             days : %d -- %d\n", MainMinLimitDays, MainMaxLimitDays); 

}
