/*****************************************************************************!
 * Function : CBConfigPressed
 *****************************************************************************/
function
CBConfigPressed
()
{
  var                                   sectionHeight;
  var                                   dataArea;
  var                                   configSection;

  configSection = document.getElementById("ConfigSection");
  dataArea = document.getElementById("DataArea");
  if ( configSection.dataOpen ) {
    configSection.style.height = "30px";
    configSection.dataOpen = false;
    dataArea.style.height = "420px";
  } else {
    configSection.style.height = "90px";
    configSection.dataOpen = true;
    dataArea.style.height = "480px";
  }
}

  
