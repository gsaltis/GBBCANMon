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

  for (i = 0 ; i < InPacket.archivedfiles.length; i++) {
    aref = document.getElementById("DownloadFilename" + (i + 1)).children[0];
	aref.innerHTML = InPacket.archivedfiles[i];
  }
  for ( ; i < 5 ; i++ ) {
    aref = document.getElementById("DownloadFilename" + (i + 1)).children[0];
    aref.innerHTML = "";
	aref.href = "";
  }
}
