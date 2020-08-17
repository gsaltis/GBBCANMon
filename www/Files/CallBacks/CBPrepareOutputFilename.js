/*****************************************************************************!
 * Function : CBPrepareDownloadFilename
 *****************************************************************************/
function
CBPrepareDownloadFilename
()
{
  var					aref;

  aref = document.getElementById("DownloadFilename").children[0];

  aref.innerHTML = "";
  aref.href = "";
  WebSocketIFSendSimpleRequest("preparedownloadfilename");
}

