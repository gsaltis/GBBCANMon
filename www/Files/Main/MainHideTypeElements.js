/*****************************************************************************!
 * Function : MainHideTypeElements
 *****************************************************************************/
function MainHideTypeElements()
{
  var                                   elementNameBases = [
    "Days", "Hours", "Size", "Count"
  ]

  // Hide all the inputs and labels
  for (i = 0; i < elementNameBases.length; i++) {
    d1 = document.getElementById("LimitType" + elementNameBases[i]);
    d2 =  document.getElementById("LimitType" + elementNameBases[i] + "Label");
    d1.style.visibility = "hidden";
    d2.style.visibility = "hidden";
    d1.parentElement.className = ""
  }
}

