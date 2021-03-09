/*****************************************************************************!
 * Function : MainInitialize
 *****************************************************************************/
function
MainInitialize()
{
  var                                   d, i;
  var                                   option;

  WebSocketIFInitialize();

  d = document.getElementById("LimitTypeHours");

  for ( i = 1 ; i <= 96; i++ ) {
    option = document.createElement("option");
    option.value = i;
    option.innerHTML = i;
    d.appendChild(option);
  }

  d = document.getElementById("LimitTypeSize");
  for ( i = 10; i <= 500; i += 10 ) {
	option = document.createElement("option");
	option.value = i;
 	option.innerHTML = i;
	d.appendChild(option)
  }

  d = document.getElementById("DataArea");
  d.addEventListener("transitionend", CBDataAreaTransitionEnd, true);
  d.addEventListener("transitionstart", CBDataAreaTransitionStart, true);
}

