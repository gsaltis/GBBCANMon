/*****************************************************************************!
 * Function : HandleToggleMonitorRequest
 *****************************************************************************/
void
HandleToggleMonitorRequest
(struct mg_connection* InConnection, json_value* InPacket)
{
  int                                   packetid;
  string                                s;

  if ( CANInterfaceMonitor ) {
    CANInterfaceMonitorStop();
  } else {
    CANInterfaceMonitorStart();
  }
  packetid = JSONIFGetInt(InPacket, "packetid");
  s = StringCopy("{\n");
  s = StringConcatTo(s, "  \"monitorstatus\" : ");
  s = StringConcatTo(s, CANInterfaceMonitor ? "true" : "false");
  s = StringConcatTo(s, "}\n");
  WebSocketFrameResponseSend(InConnection, "restogglemonitor", s, packetid, 0, "");
  FreeMemory(s);
}
