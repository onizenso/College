<!--
File: login.php
Purpose: Authenticate the customer
To do's:
- Validate the user's credentials
- Set a flag in $_SESSION to true if login is successful, otherwise just echo an error
  message.
- redirect user to store if they are already logged in
-->

<?php 
/* defines user credentials as named constants / macros, similar to #define in C.
   Do not change this */
define("USER", "nramsey");
define("PASS", "cs311");

//require_once(dirname(__FILE__).'/lib.php');
//require_once("/var/www/cs311/final/lib.php");
function login() {
/******************************************************
 Write code to authenticate the user here and redirect 
 to the store if successful. Create a session variable 
 called 'online' and set to true (see lib.php).
 *****************************************************/
 
    if(USER == $_POST['user'] && PASS == $_POST['pass']){
	session_name($_POST['user']);
	session_start();
	$_SESSION['online'] = true;
	//echo $_SESSION['online'];
	$host  = $_SERVER['HTTP_HOST'];
	$uri = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	$page = 'store.php';
	header("Location: http://$host$uri/$page");
	exit;
	}
	
    else
	echo "You fucking fail, stop trying to hack mah shit!";


}

function redirect_if_online() {
/******************************************************
 Write code that redirects the user to the store if they 
 are already logged in
 *****************************************************/
	if(isset($_SESSION['online']))
	{
	   setcookie(session_name(), "", 0,"/"); 
	   $host  = $_SERVER['HTTP_HOST'];
	   $uri = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	   $page = 'store.php';
	   header("Location: http://$host$uri/$page");
	   exit;
	}
}

redirect_if_online();

// only processes login information if the submit button has been clicked
if (isset($_POST['submit'])) { 
    login();
}
?>

<html>
<head>
<title>Log in to the PHP Store</title>
</head>
<body>

<h3>
PHP Store Login
</h3>
<p>
	<form action="login.php" method="post">
	    Username: <input name="user" type="text" />
	    Password: <input name="pass" type="password" />
	    <input name="submit" type="submit" value="Login" />
	</form>
</p>
<a href="logout.php">Log out</a>

</body>
</html>
