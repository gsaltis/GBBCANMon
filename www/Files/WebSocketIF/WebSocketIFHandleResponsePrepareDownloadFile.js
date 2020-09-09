/*****************************************************************************!
 * Function : WebSocketIFHandleResponsePrepareDownloadFile
 *****************************************************************************/
function
WebSocketIFHandleResponsePrepareDownloadFile
(InPacket)
{
  var									aref; 
  var									d;

  aref = document.getElementById("DownloadFilename").children[0];

  aref.href = InPacket.linkname;
  aref.innerHTML = InPacket.filename;

  d = document.getElementById("ClearArchiveButton");
  if ( InPacket.archivedfiles.length == 0 ) {
	d.style.visibility = "hidden";
  } else {
	d.style.visibility = "visible";
  }
    
  for (i = 0 ; i < InPacket.archivedfiles.length; i++) {
    aref = document.getElementById("DownloadFilename" + (i + 1)).children[0];
	aref.innerHTML = InPacket.archivedfiles[i];
	aref.href = InPacket.archivedfiles[i];
  }
  for ( ; i < 5 ; i++ ) {
    aref = document.getElementById("DownloadFilename" + (i + 1)).children[0];
    aref.innerHTML = "";
	aref.href = "";
  }
}
