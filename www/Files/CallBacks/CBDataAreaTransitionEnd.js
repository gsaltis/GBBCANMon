/*****************************************************************************!
 * Function : CBDataAreaTransitionEnd
 *****************************************************************************/
function
CBDataAreaTransitionEnd
()
{
  var                                   configSection;
  var                                   d;

  configSection = document.getElementById("ConfigSection");
  d = document.getElementById("DataArea");
  console.log(configSection.dataOpen);
  if ( configSection.dataOpen ) {
    console.log("");
    document.getElementById("ConfigTypeLabel").style.visibility = "visible";
    document.getElementById("ConfigTypeSelectContainer").style.visibility = "visible";
    document.getElementById("ConfigDefinitionsLabel").style.visibility = "visible";
  }
}
