/*****************************************************************************!
 * Function : WebSocketIFHandleResponsePrepareDownloadFile
 *****************************************************************************/
function
WebSocketIFHandleResponsePrepareDownloadFile
(InPacket)
{
  var					aref;

  aref = document.getElementById("DownloadFilename").children[0];

  aref.href = InPacket.linkname;
  aref.innerHTML = InPacket.filename;
}

