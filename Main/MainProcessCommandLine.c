/*****************************************************************************!
 * Function : MainProcessCommandLine
 *****************************************************************************/
void
MainProcessCommandLine
(int argc, char** argv)
{
  int					                i;
  string				                command;

  for ( i = 1 ; i < argc; i++ ) {
    command = argv[i];

    //! Specify the CAN Interface to use
    if ( StringEqualsOneOf(command, "-ci", "--caninterface", NULL) ) {
      i++;
      if ( i == argc ) {
        fprintf(stderr, "%s requires a CAN Interface name\n", command);
        MainDisplayHelp();
        exit(EXIT_FAILURE);
      }
      if ( MainCANInterfaceName ) {
        FreeMemory(MainCANInterfaceName);
      }
      MainCANInterfaceName = StringCopy(argv[i]);
      continue;
    }

    //! 
    if ( StringEqualsOneOf(command, "-v", "--verbose", NULL) ) {
	  MainVerbose = true;
	  continue;
	}

    //! Prevent the use of the UI (for daemon mode)
    if ( StringEqualsOneOf(command, "-n", "--noui", NULL) ) {
      MainUseUI = false;
      continue;
    }

    //! Specify the websocket port
    if ( StringEqualsOneOf(command, "-W", "--websocketport", NULL) ) {
      i++;
      if ( i >= argc ) {
        fprintf(stderr, "%s requires a web socket port number\n", command);
        MainDisplayHelp();
        exit(EXIT_FAILURE); 
      }
      WebSocketIFSetPort(argv[i]);
      continue;
    }

    //! Display the help screen and exit
    if ( StringEqualsOneOf(command, "-h", "--help", NULL) ) {
      MainDisplayHelp();
      exit(EXIT_SUCCESS);
    }

    //! Clear the values database before starting
    if ( StringEqualsOneOf(command, "-cl", "--cleardatabase", NULL) ) {
      MainClearDatabaseSwitch = true;
      continue;
    }

    //! Set the log filename
    if ( StringEqualsOneOf(command, "-l", "--logfile", NULL) ) {
      i++;
      if ( i == argc ) {
        fprintf(stderr, "%s requires a log file name\n", command);
        MainDisplayHelp();
        exit(EXIT_FAILURE);
      }
      CANMonLogSetFilename(argv[i]);
      continue;
    }

    //! Specify the file constraint
    if ( StringEqualsOneOf(command, "-c", "--constraint", NULL) ) {
      i++;
      if ( i == argc ) {
        fprintf(stderr, "%s requires a constraint type\n", command);
        MainDisplayHelp();
        exit(EXIT_FAILURE);
      }
      MainLimitTypeSet(argv[i]);
      continue;
    }
    
    //! Specify the file constraint size
    if ( StringEqualsOneOf(command, "-C", "--constraintsize", NULL) ) {
      i++;
      if ( i == argc ) {
        fprintf(stderr, "%s requires a constraint size\n", command);
        MainDisplayHelp();
        exit(EXIT_FAILURE);
      }
      MainLimitSizeSet(atoi(argv[i]));
      continue;
    }

    //! Specify the directory where the installation files live
    if ( StringEqualsOneOf(command, "-id", "--installdir", NULL) ) {
      i++;
      if ( i == argc ) {
        fprintf(stderr, "%s needs a directory name\n", command);
        MainDisplayHelp();
        exit(EXIT_FAILURE);
      }
      DirManagementSetInstallDir(argv[i]);
      continue;
    }
 
    if ( command[0] == '-' ) {
      fprintf(stderr, "%s is not a recognized command line options\n", command);
      MainDisplayHelp();
      exit(EXIT_SUCCESS);
    }
  }
}


