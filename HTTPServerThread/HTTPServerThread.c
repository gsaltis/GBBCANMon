/*****************************************************************************!
 * Function : HTTPServerThread
 *****************************************************************************/
void*
HTTPServerThread
(void* InArgs)
{
  struct mg_connection *              nc;
  struct mg_mgr                       mgr;
  string                                locationName;

  CANMonLogWrite("Starting server thread on port %s\n", s_http_port);
  CANMonLogWrite("Starting mongoose\n");
  mg_mgr_init(&mgr, NULL);
  CANMonLogWrite("Mongoose started\n");
  nc = mg_bind(&mgr, s_http_port, HTTPEventHandler);
  if (nc == NULL) {
    CANMonLogWrite("Failed to create http listener\n");
    return (void*)1;
  }
  mg_set_protocol_http_websocket(nc);
  locationName = DirManagementGetInstallDir();
  locationName = StringConcatTo(locationName, HTTPWWWBaseDir);
  CANMonLogWrite("HTTP WWW Directory : %s\n", locationName); 
  s_http_server_opts.document_root = locationName;
  s_http_server_opts.enable_directory_listing = "no";

  for (;;) {
    mg_mgr_poll(&mgr, 20);            
  }
}
