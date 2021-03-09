/*****************************************************************************!
 * Function : CBDataAreaTransitionStart
 *****************************************************************************/
function
CBDataAreaTransitionStart
()
{
  var                                   configSection;
  var                                   d;

  configSection = document.getElementById("ConfigSection");
  d = document.getElementById("DataArea");
  console.log(configSection.dataOpen);
  document.getElementById("ConfigTypeLabel").style.visibility = "hidden";
  document.getElementById("ConfigTypeSelectContainer").style.visibility = "hidden"; 
 document.getElementById("ConfigDefinitionsLabel").style.visibility = "hidden";
}
