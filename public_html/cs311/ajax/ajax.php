<html>
<head>
<script type="text/javascript">

// intialize constants
var STATUS_SUCCESS = 200;    // status code of 200 in the HTTP header means success
var READYSTATE_FINISHED = 4; // ready state of 4 means that we have received a response from the server

// sends a query to the response.php when button is clicked and puts the response in myDiv
function ajaxTest() {
    var ajax = new XMLHttpRequest();  // initialize the XMLHttpRequest object

    ajax.onreadystatechange=function() {   
      if (ajax.readyState == READYSTATE_FINISHED && ajax.status == STATUS_SUCCESS) {
        document.getElementById("myDiv").innerHTML = ajax.responseText;
      }
    }

    ajax.open("GET", "response.php?q="+document.getElementById("query").value, true);
    ajax.send();
}

</script>
</head>
<body>
<input type="text" id="query" />
<input type="button" value="Click me" onclick="ajaxTest()" />
<div id="myDiv">
Hello, I am a div.
</div>
</body>
</html>
