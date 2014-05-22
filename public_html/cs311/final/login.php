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

require_once(dirname(__FILE__).'/lib.php');
function login() {
/******************************************************
 Write code to authenticate the user here and redirect 
 to the store if successful. Create a session variable 
 called 'online' and set to true (see lib.php).
 *****************************************************/

    if((USER == $_POST['user']) && (PASS == $_POST['pass'])){
	session_start();
	$_SESSION['online'] = true;
	$host = $_SERVER['HTTP_HOST'];
	$uri = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	$page = 'store.php';
	header("Location: $page");
	exit;
	}
	
    else
	echo "You fail, stop trying to hack mah shiz!";


}

function redirect_if_online() {
/******************************************************
 Write code that redirects the user to the store if they 
 are already logged in
 *****************************************************/
	if(isset($_SESSION['online']))
	{
	   $host  = $_SERVER['HTTP_HOST'];
	   $uri = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	   $page = 'store.php';
	   header("Location: $page");
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
<link rel="stylesheet" type="text/css" href="style.css" />
</head>
<body>

<h3>
PHP Store Login
</h3>
<p>
    <form action="login.php" method="post">
        <table id="login" class="login" width="100%">
            <caption class="hidden">Login form</caption>
        <tr>
            <th>Username:</th>
            <td><input name="user" type="text" /></td>
        </tr>
        <tr>
            <th>Password: </th>
            <td><input name="pass" type="password" /></td>
        </tr>
        <tr>
            <th class="hidden">Submit Login</th>
            <td><input name="submit" type="submit" value="Login" /></td>
        </tr>
        </table>
    </form>
</p>
<a href="logout.php">Log out</a>

</body>
</html>
