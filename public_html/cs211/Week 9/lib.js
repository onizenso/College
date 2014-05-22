function output(text, tag)
{
  document.write("<" + tag + ">" + text + "</" + tag + ">");
}

function changeTxt(area, text)
{
   e=document.getElementById(area); 
	 e.innerHTML = text;
}

