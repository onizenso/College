<?php

function spamcheck($field)
  {
  //filter_var() sanitizes the e-mail
  //address using FILTER_SANITIZE_EMAIL
  $field=filter_var($field, FILTER_SANITIZE_EMAIL);

  //filter_var() validates the e-mail
  //address using FILTER_VALIDATE_EMAIL
  if(filter_var($field, FILTER_VALIDATE_EMAIL))
    {
    return TRUE;
    }
  else
    {
    return FALSE;
    }
  }

if (isset($_REQUEST['email']))
  {//if "email" is filled out, proceed

  //check if the email address is invalid
  $mailcheck = spamcheck($_REQUEST['email']);
  if ($mailcheck==FALSE)
    {
    echo "Invalid input";
    }
  else
  {
   $to = 'nramsey@cs.csub.edu';
   $name = $_REQUEST('name');
   $from = $_REQUEST('email');
   $subject = $_REQUEST('subject');
   $message = $_REQUEST('message');
   $headers = "From: $name{$from}";
   mail($to,$subject,$message,$headers);
   echo "Success! Package delivered.";
   echo "Thank you for filling out the form";
  }
}
  else{
      echo
	"<form action='upload.php' method='post' enctype='multipart/form-data'>
	<label for='file'>Filename:</label>
	<input type='file' name='file' id='file' />
	<br />
	<label for='name'>Name:</label>
	<input type='text' name='name' id='name' />
	<br />
	<label for='email'>Email:</label>
	<input type='text' name='email' id='email' />
	<br />
	<label for='subject'>Subject:</label>
	<input type='text' name='subject' id='subject' />
	<br />
	<label for='message'>Message:</label>
	<textarea name='message' id='message' rows='15' cols='40'></textarea>
	<br />
	<input type='submit' name='submit' value='Submit' />
	</form>";
	 }


/* Creates a folder to put uploaded files into if it does not exist
   This is a good idea because on Sleipnir, all http requests are run under
   the user www-data, so this will create a folder that only www-data can write to.
   If you did not do this, then you would have to make a directory that is 
   writable by all users, which is a security risk. */

echo "File size: ".$_FILES["file"]["size"]."<br />";

if (!file_exists("upload"))
    mkdir("upload");
if ((($_FILES["file"]["type"] == "image/gif")
|| ($_FILES["file"]["type"] == "image/jpeg")
|| ($_FILES["file"]["type"] == "image/jpg"))
|| ($_FILES["file"]["type"] == "text/plain")
&& ($_FILES["file"]["size"] < 500000 ))
  {
  if ($_FILES["file"]["error"] > 0)
    {
    echo "Return Code: " . $_FILES["file"]["error"] . "<br />";
    }
  else
    {
    echo "Upload: " . $_FILES["file"]["name"] . "<br />";
    echo "Type: " . $_FILES["file"]["type"] . "<br />";
    echo "Size: " . ($_FILES["file"]["size"] / 1024) . " Kb<br />";
    echo "Temp file: " . $_FILES["file"]["tmp_name"] . "<br />";

    if (file_exists("upload/" . $_FILES["file"]["name"]))
      {
      echo $_FILES["file"]["name"] . " already exists. ";
      }
    else
    {
      move_uploaded_file($_FILES["file"]["tmp_name"],
      "upload/" . $_FILES["file"]["name"]);
      echo "Stored in: " . "upload/" . $_FILES["file"]["name"];
      }
    }
  }
else
  {
  echo "Invalid file";
  }
/*Was going to use the function below for replacing deprecated 
 * 'string mime_content_type(string $filename)',
 * but instead I used the 'echo system("file -bi '<file path>'");' call
 * to perform basically the same function.

$file = 'file.txt';
$junk = fopen($file, "r") or exit("unable to open file, oh shit!");
fclose($junk);

function get_mime_type($filename, $mimePath = '../etc') {
   $fileext = substr(strrchr($filename, '.'), 1);
   if (empty($fileext)) return (false);
   $regex = "/^([\w\+\-\.\/]+)\s+(\w+\s)*($fileext\s)/i";
   $lines = file("$mimePath/mime.types");
   foreach($lines as $line) {
      if (substr($line, 0, 1) == '#') continue; // skip comments
      $line = rtrim($line) . " ";
      if (!preg_match($regex, $line, $matches)) continue; // no match to the extension
      return ($matches[1]);
   }
   return (false); // no match at all
} 

echo get_mime_type('file.txt');
 */
?> 
