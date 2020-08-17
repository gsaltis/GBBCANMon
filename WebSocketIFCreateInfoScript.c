/*****************************************************************************!
 * Function : WebSocketIFCreateInfoScript
 *****************************************************************************/
void
WebSocketIFCreateInfoScript
()
{
  string                                address;
  int                                   fd;
  struct                                ifreq ifr;
  FILE*                                 file;
  struct sockaddr_in*                   sa;
  int                                   i;
  char                                  b;

  //! We only want to do this when we have a value 192. address
  //  So we loop until we do or we eventually give up
  for (i = 0; i < WEBSOCKET_IF_MAX_ADDRESS_TRIES; i++ ) { 
    fd = socket(AF_INET, SOCK_DGRAM, 0);
  
    /* I want to get an IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;
  
    /* I want IP address attached to "eth0" */
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);
  
    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);
    sa = (struct sockaddr_in*)&ifr.ifr_addr;
    b = (char)(sa->sin_addr.s_addr & 0xFF);

    //! Check that we have a at least a C Address
    if ( b & 0xC0 ) {
      address = StringCopy(inet_ntoa(sa->sin_addr));
      file = FileUtilsOpen("www/websocketinfo.js", "wb");
      fprintf(file, "var WebSocketIFAddress = \"%s\";\n", address);
      fprintf(file, "var WebSocketIFPort = \"%s\";\n", s_websocket_port);
      fclose(file);
      FreeMemory(address);
      break;
    }
    //! We don't so sleep and try again
    sleep(WEBSOCKET_IF_ADDRESS_WAIT_PERIOD);
  }
}

