<html>
<head>
<title> PHP simple forms </title>
</head>
<body>

<?php

// uncomment to dump all elements in $_POST for debugging
//foreach($_POST as $key => $value)
//{
//   printf("%s = %s<br>", $key, $value);
//}
 
  //import form information
  $name = $_POST['name'];
  $room = $_POST['room'];
  $message = $_POST['message'];
  $types=$_POST['types'];
  $entree=$_POST['entree'];
  $pref1=$_POST['pref1'];
  $pref2=$_POST['pref2'];
  $pref3=$_POST['pref3'];
  $pref4=$_POST['pref4'];
  $message=stripslashes($message);
  
  // simple form validation
  if (empty($name) && empty($room)){
     print "You must include your name and room";
  } 
  elseif (empty($name)){
     print "You must enter your name.<br>";
  } 
  elseif (empty($room)){
     print "You must enter your room number. <br>";
  } 
  //  valid form so good to go
  else {
     print "<b>Menu ordered by $name in room $room:</b><br>";
     // start constructing a string for the output file
     $str = "Name: ".$name."<BR> Room:".$room."<BR>";

     // convert selection values into a string
     $ctypes = ""; 
     for ( $i=0; $i < count($types); $i++ ){
         $ctypes=  $ctypes . "\n$types[$i]";
     }
     $str .= " Choices: ".$ctypes;
     $str .= "<BR>Message:".$message."<BR>Entree: ".$entree."<BR>";
     // print the menu 
     print "<p><b>Special instructions</b>: <br>";
     print "$message<br></p><p><b>Selections:</b><br>$ctypes</p>";
     print "<p><b>Entree</b>: <br> $entree <br></p>"; 

     print "<p><b>Preferences</b>:<br>"; 
     $str .= "Preferences:";
     if ($pref1 == "on") {
       print "vegetarian <br>"; 
       $str .= "vegetarian "; 
     }

     if ($pref2 == "on") {
       print "vegan <br>"; 
       $str .= "vegan "; 
     }

     if ($pref3) {
        print "fish <br>"; 
        $str .= " fish"; 
     }

     if ($pref4) {
        print "low-fat <br>"; 
        $str .= " low-fat<br>"; 
     }

     // open file for output
     $filename = "data.txt";
     $fd = fopen($filename, "w");
     if(!$fd) {
         echo 'Could not open file $filename for writing\n';
     exit();
     }

    // construct a header for the log file
    $dt = date('r');   
    $src = $_SERVER['REMOTE_ADDR'];
    $header = "Form Submitted ".$dt." by Src IP: ".$src."<br>";

    // write to the log file
    if(fwrite($fd, $header) === false) {
       echo "Error writing to file ($filename)\n";
    exit();
    }
    fwrite($fd,$str);
    fclose($fd);

    // open output file for reading 
    $filename = "data.txt";
    $fd = fopen($filename, "r");
    if(!$fd) {
       echo 'Could not open file $filename for reading\n';
    exit();
    }

    // read from the output file
    $str = '';
    while(!feof($fd)) {
         $str .= fread($fd, 1024);
     }

     echo "<P>**Display Contents of Log File:<BR/>";
     echo $str."\n";
  
   
  }  // end else

?>
  
</body>
</html>
