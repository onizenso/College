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

   $to = 'nramsey@cs.csub.edu';
   $name = 'Obama';
   $from = 'blatant@liar.edu';
   $subject = 'Flying Across the Skies in a million dollar tube';
   $message = 'This has to be the hokiest fucking thing ever.';
   $headers = "From: ".$name."{".$from."}";

if (isset($from))
  {//if "email" is filled out, proceed

  //check if the email address is invalid
  $mailcheck = spamcheck($from);
  if ($mailcheck==FALSE)
    {
    echo "Invalid input";
    }
  else
  {
   mail($to,$subject,$message,$headers);
   echo "Success! Package delivered.";
   echo "Thank you for filling out the form<br>";
  }
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
?> 
