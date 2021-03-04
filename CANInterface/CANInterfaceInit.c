/******************************************************************************!
 * Function : CANInterfaceInit
 ******************************************************************************/
CANInterface*
CANInterfaceInit
(string InInterfaceName)
{
  struct ifreq ifr;
  struct sockaddr_can addr;
  int canSocket = 0;
  CANInterface*                         canInterface;
  memset(&ifr, 0x0, sizeof(ifr));
  memset(&addr, 0x0, sizeof(addr));
  
  /* open CAN_RAW socket */
  canSocket = socket(PF_CAN, SOCK_RAW, CAN_RAW);
  if ( canSocket == -1 ) {
    fprintf(stderr, "Socket open failed.\n");
    return NULL;
  }

  /* convert interface string into interface index */
  strcpy(ifr.ifr_name, InInterfaceName);
  if ( -1 == ioctl(canSocket, SIOCGIFINDEX, &ifr) ) {
    fprintf(stderr, "Could not get CAN interface %s\n", InInterfaceName);
    return NULL;
  }

  /* setup address for bind */
  addr.can_ifindex = ifr.ifr_ifindex;
  addr.can_family= PF_CAN;

  /* bind socket to the can0 interface */
  if ( -1 == bind(canSocket, (struct sockaddr *)&addr, sizeof(addr)) ) {
    fprintf(stderr, "Could not bind to socket\n");
    return NULL;
  }
  canInterface = (CANInterface*)GetMemory(sizeof(CANInterface));
  canInterface->socket = canSocket;
  canInterface->portName = StringCopy(InInterfaceName);
  canInterface->opened = true;

  return canInterface;
}
