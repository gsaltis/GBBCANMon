/*****************************************************************************!
 * Function : WebSocketIFHandleRemoveArchivedFiles
 *****************************************************************************/
function
WebSocketIFHandleRemoveArchivedFiles
(InPacket)
{
  var                                   i, name;
  MainDisplayMessage(InPacket.responsemessage);
  for (i = 0 ; i < 5; i++ ) {
    name = "DownloadFilename" + (i + 1);
    document.getElementById(name).innerHTML = "";
  }
  document.getElementById("ClearArchiveButton").style.visibility = "hidden";
}
