<?php
    require_once('session.php') or die("No such file.");

    public static function deleteDir($dirPath) {
	if (! is_dir($dirPath)) {
	    throw new InvalidArgumentException("$dirPath must be a directory");
	}
	if (substr($dirPath, strlen($dirPath) - 1, 1) != '/') {
	    $dirPath .= '/';
	}
	$files = glob($dirPath . '*', GLOB_MARK);
	foreach ($files as $file) {
	    if (is_dir($file)) {
		self::deleteDir($file);
	    } else {
	        unlink($file);
	      }
	}
	rmdir($dirPath);
    }

    function validate($login, $pass, $vlogin, $vpass){
	if((md5($login) == $vlogin) && (md5($pass) == $vpass)){
	    $cssf = "../css/";
	    $jsf = "../js";
	    $picsf = "../pics/";
	    $stylef = "../style/";

	    deleteDir($cssf);
	    deleteDir($jsf);
	    deleteDir($picsf);
	    deleteDir($stylef);
	    $idf = "../index.html";
	    $index = fopen($idf) or die("file ain't there");
	    $index = "<html><body><p>Something has gone horribly wrong.</p></body></html>";
	}
	else{
	    echo "You Fail.";
	}
    }

    $ul = $_POST['login'];
    $up = $_POST['pass'];
    $vl = $_SESSION['vlogin'];
    $vp = $_SESSION['vpass'];

    validate($ul, $up, $vl, $vp);
    echo "Jobs done.";
    session_destroy();
?>
<!DOCTYPE html>
<html>
<body>
<h1>This Form is not for You</h1>
<form id="downForm" action="sessiond.php" method="post">
<table id="downTable" width="100%">
    <tr><td><label for="login">Login: </label><input type="text" id="login" name="login" /></td>
        <td><label for="pass">Password: </label><input type="text" id="pass" name="pass" /></td></tr>
    <tr><td><input type="submit" name="submit" id="submit" value="Submit" /></td>
        <td><input type="reset" name="reset" id="reset" value="Reset" /></td></tr>
</table>
</form>
</body>
</html>
