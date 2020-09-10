/*****************************************************************************!
 * Function : WebSocketIFHandleSetLimitsResponse
 *****************************************************************************/
function
WebSocketIFHandleSetLimitsResponse
(InResponse)
{
  console.log(InResponse);
  MainDisplayMessage(InResponse.message);
  document.getElementById("LimitTypeSelect").value = InResponse.type;
  MainSetTypeLimitValue(InResponse.type, InResponse.value);
}
