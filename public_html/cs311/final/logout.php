<!--
File: logout.php
Purpose: Destroy the session
To do's: none
-->

<html>
<head>
<?php 
// Destroys the session and deletes the cookie from the web browser
session_start();
$_SESSION = array();
$_GET = array();
setcookie(session_name(),"",0,"/");
session_destroy();
?>
</head>
<body>
You are now logged out.<br />
<a href=".">Browse</a>
</body>
</html>
