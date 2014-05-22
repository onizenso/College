<html>
<head>
<title> Exam 2 PHP</title>
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
  $class= $_POST['class'];
  $Q1 =$_POST['Q1'];
  $Q2A=$_POST['Q2A'];
  $Q2B=$_POST['Q2B'];
  $Q2C=$_POST['Q2C'];
  $Q2D=$_POST['Q2D'];
  
  // simple form validation
  if ( empty($name) ){
     print "You must include your name!";
  } 
  //  valid form so good to go
  else {
     $score = 0;
     print "<b>Quiz #1: $name</b><p>";
     print "Class: $class</b><p>";
     $errors = "";

     if ($Q1 == "B"){
        $score++;
     }
     else{
        $errors .= "Q1 ";
     }
     if (  ($Q2B =="on") && ($Q2C=="on") && ($Q2A != "on") && ($Q2D != "on") ) {
        $score++;
     }
     else{
        $errors .= "Q2 ";
     }
     $result = ($score/2) * 100;
     print "Percentage: ".$result."%<p>";
     if ( strlen($errors) == 0 ) {
         print "Errors: 0 Great Job!";
     }
     else {
         print "Errors: ".$errors;
     }
  }  // end else

?>
  
</body>
</html>
